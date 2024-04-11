#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int ilebit(int n)
{
    int res=0;
    while(n)
    {
        n/=2; res++;
    }
    return res;
}

const int nax=2e5+5;
int a[nax];
int b[nax];
int sz[nax];
int n,k;
int roz[nax];
vector<int> adj[nax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    int res=1e9;
    int pos=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) sz[i]=ilebit(a[i]);
    for(int i=0;i<=20;i++)
    {
        for(int j=0;j<nax;j++) adj[j].clear();
        for(int j=1;j<=n;j++) b[j]=a[j];
        for(int j=1;j<=n;j++)
        {
            int akt=b[j];
            if(sz[j]>i)
            {
                int ile=sz[j]-i;
                (b[j]>>=ile);
                adj[b[j]].push_back(ile);
            }
            else
            {
                int ile=0;
                adj[b[j]].push_back(ile);
            }
        }
        //if(i==0) cout<<"XD"<<adj[0].size()<<endl;
        for(int j=0;j<nax;j++) roz[j]=0;
        for(int j=1;j<=n;j++) roz[b[j]]++;
        for(int j=0;j<nax;j++)
        {
            if(adj[j].size()>=k)
            {
                sort(adj[j].begin(),adj[j].end());
                for(int z=0;z<k;z++) pos+=adj[j][z];
                res=min(res,pos);
                pos=0;
            }
        }


    }
    cout<<res<<endl;
    return 0;
}