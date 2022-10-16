#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=3e5+5;

vector<int> adj[N];
vector<int> p;
vector<bool> czyok(N,false);
int pozycja[N];
int ile[N];
vector<int> special;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        p.push_back(x);
        pozycja[x]=i;
    }
    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        if(b==p[n-1]) special.push_back(a);
    }
    int pos=p[n-1];
    czyok[pos]=true;
    for(int i=0;i<special.size();i++)
    {
        int val=special[i];
        czyok[val]=true;
    }
    int licz=0;
    for(int i=n-1;i>=0;i--)
    {
        int val=p[i];
        if(czyok[val]==false) licz++;
        ile[p[i]]=licz;
    }
    int odp=0;
    int jakduzo=0;
    for(int i=n-2;i>=0;i--)
    {
        int akt=p[i];
        if(czyok[akt]==false)
        {
            jakduzo++;
            continue;
        }
        int licz=0;
        for(int j=0;j<adj[akt].size();j++)
        {
            int val=adj[akt][j];
            if(czyok[val]==false)
            {

                if(pozycja[val]>pozycja[akt]) licz++;
            }

        }
        if(licz==jakduzo) odp++;
        else
        {
            czyok[akt]=false;
            jakduzo++;
        }

    }
    cout<<odp;
    return 0;
}