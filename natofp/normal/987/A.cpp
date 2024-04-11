#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string tab[6][2];
    tab[0][0]="Power";
    tab[0][1]="purple";
    tab[1][0]="Time";
    tab[1][1]="green";
    tab[2][0]="Space";
    tab[2][1]="blue";
    tab[3][0]="Soul";
    tab[3][1]="orange";
    tab[4][0]="Reality";
    tab[4][1]="red";
    tab[5][0]="Mind";
    tab[5][1]="yellow";
    bool x[6]={true,true,true,true,true,true};
    int licznik=0;
    for(int i=0;i<n;i++)
    {
        string wyraz;
        cin>>wyraz;
        for(int j=0;j<6;j++)
        {
            if(wyraz==tab[j][1]) {x[j]=false; licznik++;}
        }
    }
    cout<<6-licznik<<endl;
    for(int i=0;i<6;i++)
    {
        if(x[i]) cout<<tab[i][0]<<endl;
    }

    return 0;
}