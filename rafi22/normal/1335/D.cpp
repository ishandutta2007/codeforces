#include <bits/stdc++.h>

using namespace std;

char tab[10][10];

int main()
{
    int t;
    cin>>t;
    for(int j=0; j<t; j++)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                cin>>tab[i][j];
            }
        }
        tab[0][0]=tab[0][0]+1;
        tab[1][3]=tab[1][3]+1;
        tab[2][6]=tab[2][6]+1;
        tab[3][1]=tab[3][1]+1;
        tab[4][4]=tab[4][4]+1;
        tab[5][7]=tab[5][7]+1;
        tab[6][2]=tab[6][2]+1;
        tab[7][5]=tab[7][5]+1;
        tab[8][8]=tab[8][8]+1;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(tab[i][j]==58) cout<<'1';
                else cout<<tab[i][j];
            }
            cout<<endl;
        }
    }

    return 0;
}