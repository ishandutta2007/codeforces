#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=505;

int p1[nax][nax];
int p2[nax][nax];

int main()
{
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>p1[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>p2[i][j];
        }
    }
    vector<int> wiersze1(nax,0);
    vector<int> wiersze2(nax,0);
    vector<int> kolumny1(nax,0);
    vector<int> kolumny2(nax,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            wiersze1[i]+=p1[i][j];
            wiersze2[i]+=p2[i][j];
            kolumny1[j]+=p1[i][j];
            kolumny2[j]+=p2[i][j];
        }
    }
    for(int i=1;i<=500;i++)
    {
        if(wiersze1[i]%2!=wiersze2[i]%2) {cout<<"No"; return 0;}
        if(kolumny1[i]%2!=kolumny2[i]%2) {cout<<"No"; return 0;}
    }
    cout<<"Yes";

    return 0;
}