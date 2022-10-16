#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char tab[101][101];

int naj(int a,int b,int n,int m)
{
    int i=0;
    while(1)
    {
        if(a+i>n) break;
        if(a-i<1) break;
        if(b+i>m) break;
        if(b-i<1) break;
        if(tab[a+i][b]=='.' || tab[a-i][b]=='.' || tab[a][b+i]=='.' || tab[a][b-i]=='.') break;
        i++;
    }
    return i-1;
}

void maluj(int a,int b,int roz)
{
    for(int i=a+roz;i>=a-roz;i--)
    {
        tab[i][b]='1';
    }
    for(int i=b-roz;i<=b+roz;i++)
    {
        tab[a][i]='1';
    }
}

struct xd
{
    int a; int b; int c;
};

int main()
{
    for(int i=0;i<=100;i++) {for(int j=0;j<=100;j++) tab[i][j]='.';}
    vector<xd> odp;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>tab[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int roz=naj(i,j,n,m);
            if(roz>0)
            {
                maluj(i,j,roz);
                xd lol;
                lol.a=i;
                lol.b=j;
                lol.c=roz;
                odp.push_back(lol);
            }
        }
    }
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(tab[i][j]=='*') {cout<<"-1"; return 0;}
        }

    }
    cout<<odp.size()<<endl;
    for(int i=0;i<odp.size();i++)
    {
        cout<<odp[i].a<<" "<<odp[i].b<<" "<<odp[i].c<<endl;
    }

    return 0;
}