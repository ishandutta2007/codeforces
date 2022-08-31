#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N  = 2e5+10;

vector<int> graph[N];
vector<int> sub(N,1);

int n,u,v,ans = 0;

void dfs(int node,int p)
{
    
 for(auto x : graph[node])
 {
     if(x!=p) 
     {
      dfs(x,node);
      sub[node]+=sub[x];      
     }
 }
  
  ans+=sub[node];    
}

void dfs1(int node,int p,int curr)
{
    ans = max(ans,curr);
    
    for(auto x : graph[node])
       if(x!=p) 
         dfs1(x,node,curr+n-2*sub[x]);   
}

void solve()
{
cin >> n;
    
f(i,n-1)
{
 cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
}
    
 dfs(1,-1);
 dfs1(1,-1,ans);
    
 cout << ans;
    
}

signed main()
{
    fast;
    solve();
}