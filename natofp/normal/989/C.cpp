#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tab[48][48];
    for(int i=0;i<48;i++)
        for(int j=0;j<48;j++)
    {
        tab[i][j]=i/12;
    }

    char g[4];
    g[0]='A';
    g[1]='B';
    g[2]='C';
    g[3]='D';
    int kolory[4];
    for(int i=0;i<4;i++)
        cin>>kolory[i];
    for(int i=3;i>=0;i--)
    {
        int p=kolory[i]-1;
        int x,y;
        int kolumna=3-i;
        x=kolumna*12+1;
        y=1;
        while(p)
        {
            p--;
            tab[x][y]=i;
            y+=2;
            if(y>=48) {y=1; x+=2;}
        }


    }
    cout<<"48"<<" "<<"48"<<endl;
    for(int i=0;i<48;i++)
        {
            for(int j=0;j<48;j++)
                {
                    cout<<g[tab[i][j]];
                }
                cout<<endl;
        }

    return 0;
}