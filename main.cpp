#include<windows.h>
#include<iostream>
#include<winuser.h>
#include<time.h>
using namespace std;
#define n 100
#define maxlength 100
char map[n][n]=
{
    "**********************************",
    "*                                *",
    "*                                *",
    "*      Snake2014                 *",
    "*           By NTA               *",
    "*                                *",
    "*                                *",
    "*                                *",
    "*                                *",
    "*                                *",
    "*                                *",
    "*                                *",
    "*                                *",
    "*         @                      *",
    "*                                *",
    "*                                *",
    "*                                *",
    "*                                *",
    "*                                *",
    "*                                *",
    "*                                *",
    "**********************************",
};
int X[maxlength],Y[maxlength];
bool gameover;
void print()
{
    int p,q;
    for (int x=0; x<n; x++) if (map[x][0]!='*')
        {
            p=x;
            break;
        }
    for (int x=0; x<n; x++) if (map[0][x]!='*')
        {
            q=x;
            break;
        }
    for(int x=0; x<p; x++)
    {
        for (int y=0; y<q; y++) cout<<map[x][y];
        cout<<endl;
    }
}
int cou(char c,int x,int y)
{
    int i=0;
    if(map[x+1][y]==c) i++;
    if(map[x-1][y]==c) i++;
    if(map[x][y+1]==c) i++;
    if(map[x][y-1]==c) i++;
    return i;
}
void addhead(char direction)
{
    int x,y;
    if (direction=='d')
    {
        for(x=1; x<n-1; x++)
            for(y=1; y<n-1; y++)
                if (map[x][y]=='@')
                    if (map[x+1][y]!='*'&&map[x+1][y]!='+')
                        if (cou('+',x,y)==0&&map[x+1][y]!='$')
                        {
                            map[x][y]=' ';
                            map[x+1][y]='@';
                            return;
                        }
                        else
                        {
                            map[x][y]='+';
                            map[x+1][y]='@';
                            return;
                        }
                    else
                    {
                        gameover=true;
                        return;
                    }
    }

    if (direction=='u')
    {
        for(x=1; x<n-1; x++)
            for(y=1; y<n-1; y++)
                if (map[x][y]=='@')
                    if (map[x-1][y]!='*'&&map[x-1][y]!='+')
                        if (cou('+',x,y)==0&&map[x-1][y]!='$')
                        {
                            map[x][y]=' ';
                            map[x-1][y]='@';
                            return;
                        }
                        else
                        {
                            map[x][y]='+';
                            map[x-1][y]='@';
                            return;
                        }
                    else
                    {
                        gameover=true;
                        return;
                    }
    }

    if (direction=='l')
    {
        for(x=1; x<n-1; x++)
            for(y=1; y<n-1; y++)
                if (map[x][y]=='@')
                    if (map[x][y-1]!='*'&&map[x][y-1]!='+')
                        if (cou('+',x,y)==0&&map[x][y-1]!='$')
                        {
                            map[x][y]=' ';
                            map[x][y-1]='@';
                            return;
                        }
                        else
                        {
                            map[x][y]='+';
                            map[x][y-1]='@';
                            return;
                        }
                    else
                    {
                        gameover=true;
                        return;
                    }
    }

    if (direction=='r')
    {
        for(x=1; x<n-1; x++)
            for(y=1; y<n-1; y++)
                if (map[x][y]=='@')
                    if (map[x][y+1]!='*'&&map[x][y+1]!='+')
                        if (cou('+',x,y)==0&&map[x][y+1]!='$')
                        {
                            map[x][y]=' ';
                            map[x][y+1]='@';
                            return;
                        }
                        else
                        {
                            map[x][y]='+';
                            map[x][y+1]='@';
                            return;
                        }
                    else
                    {
                        gameover=true;
                        return;
                    }
    }
}
void headplace(int t)
{
    for (int x=0; x<n; x++)
        for (int y=0; y<n; y++)
            if (map[x][y]=='@')
            {
                X[t]=x;
                Y[t]=y;
                return;
            }
}
int checkmoney(char d)
{
    for(int x=0; x<n; x++)
        for (int y=0; y<n; y++)
            if (map[x][y]=='@')
            {
                if (d=='u') if (map[x-1][y]=='$') return 1;
                if (d=='d') if (map[x+1][y]=='$') return 1;
                if (d=='l') if (map[x][y-1]=='$') return 1;
                if (d=='r') if (map[x][y+1]=='$') return 1;
                return 0;
            }

}
int checkdie(char d)
{
    for(int x=0; x<n; x++)
        for (int y=0; y<n; y++)
            if (map[x][y]=='@')
            {
                if (d=='u') if (map[x-1][y]=='+'||map[x-1][y]=='*') return 1;
                if (d=='d') if (map[x+1][y]=='+'||map[x+1][y]=='*') return 1;
                if (d=='l') if (map[x][y-1]=='+'||map[x][y-1]=='*') return 1;
                if (d=='r') if (map[x][y+1]=='+'||map[x][y+1]=='*') return 1;
                return 0;
            }

}
void random()
{
    int p,q,a,b;
    for (int x=0; x<n; x++) if (map[x][0]!='*')
        {
            p=x;
            break;
        }
    for (int x=0; x<n; x++) if (map[0][x]!='*')
        {
            q=x;
            break;
        }
    a=b=0;
    while(map[a][b]!=' ')
    {
        srand(time(NULL));
        a=rand()%(1000)+1;
        b=rand()%(1000)+1;
        a=a%(p-1)+1;
        b=b%(q-1)+1;
    }
    map[a][b]='$';
}
int main()
{
    char direction='r', d;
    gameover=false;
    bool rand=false;
    int turn=0, length=0,m;
    random();

    while(1)
    {
        system("cls");
            print();
            cout<<"Score: "<<length<<endl;
            cout<<"Level: "<<(length/5)+1<<endl;
            if(gameover)
            {
                cout<<"Game over"<<endl;
                break;
            }

        Sleep(500/((length/3)+3));

        d=direction;
        if(GetAsyncKeyState(VK_UP)&&d!='d') {
                direction='u';
        }
         if(GetAsyncKeyState(VK_DOWN)&&d!='u') {
                direction='d';
        }
         if(GetAsyncKeyState(VK_LEFT)&&d!='r') {
                direction='l';
        }
         if(GetAsyncKeyState(VK_RIGHT)&&d!='l') {
                direction='r';
        }
         if(GetAsyncKeyState(VK_ESCAPE)) exit(0);


            m=turn%maxlength;
            headplace(m);
            if (length==1)
            {
                if (checkmoney(direction)==0&&checkdie(direction)==0)
                {
                    addhead(direction);
                    if (turn>=maxlength&&m==0) map[X[maxlength-1]][Y[maxlength-1]]=' ';
                    else map[X[m-1]][Y[m-1]]=' ';
                }
                else
                {
                    if (checkmoney(direction))
                    {
                        length++;
                        rand=true;
                    }
                    addhead(direction);
                }

            }
            else
            {
                if (checkmoney(direction)==0&&checkdie(direction)==0)
                {
                    if (length>0)
                    {
                        if (m<length) map[X[maxlength-length+m]][Y[maxlength-length+m]]=' ';
                        else map[X[m-length]][Y[m-length]]=' ';
                    }
                }
                else if (checkmoney(direction))
                {
                    length++;
                    rand=true;
                }
                addhead(direction);
            }
            turn++;
            if (rand)
            {
                random();
                rand=false;
            }

    }

    system("Pause");
}
