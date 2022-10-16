#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=2e5+5;
int a[nax];
bool odw[nax];
int n;
vector<int> adj[nax];

void dodaj(int x,int d)
{
    adj[x].push_back(d);
}

int ans[nax][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(i-a[i]>=1)
        {
            dodaj(i-a[i],i);
        }
        if(i+a[i]<=n)
        {
            dodaj(i+a[i],i);
        }
    }
    vector<int> ziomki;
    for(int i=1;i<=n;i++)
    {
        if(a[i]%2==0)
        {
            ziomki.push_back(i);
            odw[i]=true;
        }
    }
    int wsk=0;
    while(wsk<ziomki.size())
    {
        int akt=ziomki[wsk++];
        for(int i=0;i<adj[akt].size();i++)
        {
            int ss=adj[akt][i];
            if(odw[ss]==false)
            {
                odw[ss]=true;
                ziomki.push_back(ss);
                ans[ss][0]=ans[akt][0]+1;
            }
        }
    }
    ziomki.clear();
    for(int i=1;i<=n;i++) odw[i]=false;
    wsk=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]%2==1)
        {
            ziomki.push_back(i);
            odw[i]=true;
        }
    }
    wsk=0;
    while(wsk<ziomki.size())
    {
        int akt=ziomki[wsk++];
        for(int i=0;i<adj[akt].size();i++)
        {
            int ss=adj[akt][i];
            if(odw[ss]==false)
            {
                odw[ss]=true;
                ziomki.push_back(ss);
                ans[ss][1]=ans[akt][1]+1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int odp=ans[i][(1+a[i])%2];
        if(odp==0) cout<<-1<<" ";
        else cout<<odp<<" ";
    }
    return 0;
}