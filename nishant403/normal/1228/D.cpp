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

const int N = 1e5+10;
unordered_map<int,int> g[N];
vi ans(N);
vi vis(N,0);

void dfs(int node)
{
    vis[node] = 1;
    
    for(auto x : g[node])
        if(!vis[x.F]) dfs(x.F);  
}

bool partition(vi & temp,vi & a,vi & b)
{
    if(temp.size() == 0) return false;
    
    a.pb(temp[0]);
   
    for(int i=1;i<temp.size();i++)
    {
      if(g[temp[0]].find(temp[i]) == g[temp[0]].end()) a.pb(temp[i]);
      else b.pb(temp[i]);
    }
    
    return (b.size() > 0); 
}

bool check(vi & a, vi &b)
{
  for(auto x : a)
      for(auto y : b)
        if(g[x].find(y) == g[x].end()) return false; 

      return true;      
}

bool check2(vi & x)
{
  unordered_map<int,int> v;
    for(auto z : x) v[z] = 1;
    
  for(auto z : x)
      for(auto y : g[z])
      if(v.find(y.F) != v.end()) return 0;
  
    
    return 1;
}

void solve()
{
  int n,m,a,b;
    cin >> n >> m;
    
  f(i,m)
  {
   cin >> a >> b;
    g[a][b]=1;
    g[b][a]=1;
  }
   
  dfs(1);
    
  for(int i=1;i<=n;i++)
   if(!vis[i])
  {
      cout << -1;
      return;   
  }
      
  vi t1,t2,t3;
  vi v1,v2,v3,v4;
    
  f(i,n) t1.pb(i+1);
    
  if(!partition(t1,v1,t2))
  {
    cout << -1;
    return;
  }
   
  if(!partition(t2,v2,t3))
  {
     cout << -1;
     return;
  }
    
  if(partition(t3,v3,v4))
  {
    cout << -1;
    return;
  }
    
  //now check that v1,v2,v3 has edges
  if(!check(v1,v2))
  {
    cout<<-1;
    return;
  }
    
   if(!check(v1,v3))
  {
    cout<<-1;
    return;
  } 
    
    if(!check(v2,v3))
  {
    cout<<-1;
    return;
  }
    
  if(!check2(v1))
  {
   cout<<-1;
   return;
  }
    
    if(!check2(v2))
  {
   cout<<-1;
   return;
  }
    if(!check2(v3))
  {
   cout<<-1;
   return;
  }
    
  for(auto x : v1) ans[x] = 1;
  for(auto x : v2) ans[x] = 2;
  for(auto x : v3) ans[x] = 3;
    
  f(i,n) cout << ans[i+1] <<" ";  
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}