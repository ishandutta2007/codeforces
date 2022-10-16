#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
vector<bool> visited(100001,false);
vector<bool> czy(100001,false);
vector<int> ile(100001,0);

void dfs(int v)
{
    visited[v]=true;
    if(v!=1 && adj[v].size()==1)
    {
        czy[v]=true;
    }
    for(int i=0;i<adj[v].size();i++)
    {
        if(visited[adj[v][i]]==false)
        {
            dfs(adj[v][i]);
            if(czy[adj[v][i]]==true) ile[v]++;
        }
    }
    return ;

}


int main()
{
   int n;
   double s;
   cin>>n>>s;
   if(n==2) {cout<<s<<endl; return 0;}
   for(int i=0;i<n-1;i++)
   {
       int x,y;
       cin>>x>>y;
       adj[x].push_back(y);
       adj[y].push_back(x);
   }
   dfs(1);
   int ans=0;
   bool glob;
   glob=false;
   if(adj[1].size()==1) glob=true;
   int wynik=0;
   for(int i=1;i<=n;i++)
   {
       if(czy[i]==true) ans++;
   }
   wynik=ans;
   for(int i=2;i<=n;i++)
   {
       int akt=ans;
       if(czy[i]==true) akt--;
       if(glob) akt++;
       wynik=max(wynik,akt);
   }
   cout<<setprecision(15)<<s*1.0/wynik*2;
    return 0;
}