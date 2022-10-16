#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=2e5+5;
vector<int> adj[nax];
int ile[nax];
bool ok [nax];
const int mod=1e9+7;
bool martwy[nax];
int jaka[nax];
int sz=1;
ll wynik[nax];
ll rozmiar[nax];
ll listki[nax];

void dfs(int v)
{
    ok[v]=true;
    rozmiar[sz]++;
    for(int i=0;i<adj[v].size();i++)
    {
        int akt=adj[v][i];
        if(ok[akt]==false) dfs(akt);
    }
    jaka[v]=sz;
}

ll pot(ll a,ll b)
{
    ll res=1;
    for(int i=0;i<b;i++)
    {
        res*=a;
        res%=mod;
    }
    return res;
}

int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
        ile[i]++;
        ile[x]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(ok[i]==false)
        {
            dfs(i); sz++;
        }
    }
    sz--;
    int wsk=0;
    vector<int> xd;
    for(int i=1;i<=n;i++)
    {
        if(ile[i]==1)
        {
            xd.push_back(i);
            listki[jaka[i]]++;
        }
    }
    while(wsk<xd.size())
    {
        int akt=xd[wsk++];
        martwy[akt]=true;
        for(int i=0;i<adj[akt].size();i++)
        {
            int ziomal=adj[akt][i];
            if(martwy[ziomal]==true) continue;
            ile[ziomal]--;
            if(ile[ziomal]==1)
            {
                xd.push_back(ziomal);
                listki[jaka[ziomal]]++;
            }
        }
    }
    ll res=1;
    //cout<<rozmiar[1]<<" "<<listki[1]<<endl;
    for(int i=1;i<=sz;i++)
    {
        ll cyc=rozmiar[i]-listki[i];
        ll akt=pot(2,cyc)-2;
        akt*=pot(2,listki[i]);
        akt%=mod;
        res*=akt;
        res%=mod;
    }
    cout<<res;

    return 0;
}