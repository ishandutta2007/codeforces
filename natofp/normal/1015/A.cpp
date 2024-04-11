#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;
    cin>>n>>m;
    int tab[101];
    for(int i=0;i<=100;i++) tab[i]=0;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        int l; cin>>l;
        for(int j=x;j<=l;j++)
            tab[j]++;
    }
    int wynik=0;
    for(int i=1;i<=m;i++)
    {
        if(tab[i]==0) wynik++;
    }
    cout<<wynik<<endl;
    for(int i=1;i<=m;i++)
    {
        if(tab[i]==0) cout<<i<<" ";
    }
    return 0;
}