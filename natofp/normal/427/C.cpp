#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;
vector<int> adj[N];
vector<int> adj2[N];
vector<bool> visited(N,0);
vector<int> S;
vector<int> SCC[N];
vector<int> jaka(N,0);


void dfs(int v)
{
    visited[v]=true;
    for(int i=0;i<adj[v].size();i++)
    {
        if(visited[adj[v][i]]==false) dfs(adj[v][i]);
    }
    S.push_back(v);
}

void dfs2(int v,int ile)
{
    visited[v]=true;
    SCC[ile].push_back(v);
    for(int i=0;i<adj2[v].size();i++)
    {
        if(visited[adj2[v][i]]==false) dfs2(adj2[v][i],ile);
    }
}

int main()
{
   int n; cin>>n;
   long long int * a=new long long int[n];
   for(int i=0;i<n;i++) cin>>a[i];
   int m; cin>>m;
   for(int i=0;i<m;i++)
   {
       int x,y; cin>>x>>y;
       adj[x].push_back(y);
   }
   for(int i=1;i<=n;i++)
   {
       if(visited[i]==false) dfs(i);
   }
   for(int i=1;i<=n;i++) visited[i]=false;
   for(int i=1;i<=n;i++)
   {
       for(int j=0;j<adj[i].size();j++)
       {
           adj2[adj[i][j]].push_back(i);
       }
   }
   reverse(S.begin(),S.end());
   int ile=1;
   for(int i=0;i<S.size();i++)
   {
       if(visited[S[i]]==false) {dfs2(S[i],ile); ile++;}
   }
   int i=1;
   while(SCC[i].size()>0)
   {
       for(int j=0;j<SCC[i].size();j++)
       {
           jaka[SCC[i][j]]=i;
       }
       i++;
   }
   long long ans=0;
   ile--;
   vector<long long int> wynik(ile+1,1000000001);
   for(int i=1;i<=n;i++)
   {
       long long int t=a[i-1];
       wynik[jaka[i]]=min(wynik[jaka[i]],t);
   }
   for(int i=1;i<=ile;i++)
   {
        ans+=wynik[i];
   }
   cout<<ans;
   long long int mod=1e9+7;
   long long int c=1;
   for(int i=1;i<=ile;i++)
   {
       long long t=wynik[i];
       long long int b=0;
       for(int j=0;j<SCC[i].size();j++)
       {
           if(a[SCC[i][j]-1]==t) b++;
       }
       c*=(b);
       c%=mod;
   }
   cout<<" "<<c;

    return 0;
}