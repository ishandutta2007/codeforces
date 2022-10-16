#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct seg
{
    int a,b,c;
};

const int N=1e5+5;
vector<pair<int,int> > adj[N];
vector<int> worek;
vector<int> indeg(N,0);
vector<int> poczatek(N,0);
vector<seg> kraw;
int n,m;


bool czy(int k,bool xd=false)
{
    for(int i=1;i<=n;i++) indeg[i]=poczatek[i];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            if(adj[i][j].second<=k) indeg[adj[i][j].first]--;
        }
    }
    int ile=0;
    worek.clear();
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0) {worek.push_back(i);}
    }
    while(ile!=worek.size())
    {
        int t=worek[ile++];
        for(int j=0;j<adj[t].size();j++)
        {
            if(adj[t][j].second>k) indeg[adj[t][j].first]--;
            if(adj[t][j].second>k && indeg[adj[t][j].first]==0)
            {
                worek.push_back(adj[t][j].first);
            }
        }
    }
    if(ile==n) return true;
    return false;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c; cin>>a>>b>>c;
        adj[a].push_back({b,c});
        seg t; t.a=a; t.b=b; t.c=c;
        kraw.push_back(t);
        indeg[b]++;
        poczatek[b]++;
    }
    int lo=1;
    int hi=1e9;
    while(lo+2<hi)
    {
        int mid=(lo+hi)/2;
        if(czy(mid)==true) hi=mid;
        else lo=mid+1;
    }
    while(czy(hi)==true && hi>=0) hi--;
    hi++;
    czy(hi);
    cout<<hi<<" ";
    vector<int> ktore(N,0);
    vector<int> ans;
    for(int i=0;i<worek.size();i++)
    {
        int t=worek[i];
        ktore[t]=i;
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c; a=kraw[i].a; b=kraw[i].b; c=kraw[i].c;
        if(c<=hi && ktore[a]>ktore[b]) {ans.push_back(i+1);}
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";



    return 0;
}