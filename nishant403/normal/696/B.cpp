#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N =1e5+10;
vi g[N];
double val[N];
int sz[N];

void dfs(int node,int par = -1)
{
   sz[node] = 1; 
    
   for(auto x : g[node])
       if(x!=par)
   {
       dfs(x,node);
       sz[node]+=sz[x];
   }
    
}

void dfs2(int node,int par = -1)
{
    
   for(auto x : g[node])
       if(x!=par)
   {
       val[x] = val[node] + (((double)sz[node] - sz[x])/2.000000) + 0.500000;
   }
    
   for(auto x : g[node])
       if(x!=par) dfs2(x,node);
}

void solve()
{
  int n;
  cin >> n;
    
  int x;
   
  f(i,n-1)
  {
      cin >> x;
      g[i+1].pb(x);
      g[x].pb(i+1);
  }
    
  val[1] = 1.00000000;  
    
  dfs(1);
  dfs2(1);
    
  f(i,n) cout << fixed << setprecision(6) << val[i] << " ";  
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}