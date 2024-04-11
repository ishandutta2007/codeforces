#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=205;
int p[nax][nax];
int n,m;

void dokoncz()
{
    cout<<"YES"<<endl;
    cout<<"0"<<endl;
    for(int i=1;i<=m;i++)
    {
        cout<<p[1][i];
    }
}

bool proba(int gora)
{
    vector<int> wzor;
    if(gora==1)
    {
        for(int i=1;i<=m;i++)
        {
            wzor.push_back(p[n][i]);
        }
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            wzor.push_back(p[1][i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i==gora) continue;
        int ilenormal=0;
        int ilerev=0;
        for(int j=1;j<=m;j++)
        {
            if(p[i][j]==wzor[j-1]) ilenormal++;
            else ilerev++;
        }
        if(ilerev!=m && ilenormal!=m) return false;
    }
    vector<int> klucz;
    for(int i=1;i<=m;i++)
    {
        if(wzor[i-1]==0) klucz.push_back(p[gora][i]);
        else
        {
            if(p[gora][i]==1) klucz.push_back(0);
            else klucz.push_back(1);
        }
    }
    int ile=0;
    for(int i=1;i<m;i++)
    {
        if(klucz[i]!=klucz[i-1]) ile++;
    }
    if(ile>1) return false;
    // da sie
    cout<<"YES"<<endl;
    for(int i=1;i<gora;i++)
    {
        if(p[i][1]==wzor[0]) cout<<"0";
        else cout<<"1";
    }
    if(klucz[0]==0) cout<<"0";
    else cout<<"1";
    for(int i=gora+1;i<=n;i++)
    {
        if(p[i][1]==wzor[0]) cout<<"1";
        else cout<<"0";
    }
    cout<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<wzor[i];
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char x; cin>>x;
            p[i][j]=x-'0';
        }
    }
    if(n==1) {dokoncz(); return 0;}
    for(int i=1;i<=n;i++)
    {
        bool ok = proba(i);
        if(ok==true) return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}