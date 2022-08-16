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

const int N = 5004;
vector<pii> g[N];
vi vis(N,0),ans(N,1);

bool cyc = 0;

void dfs(int v)
{
  vis[v] = 1;
    
    for(auto x : g[v])
    {
        if(!vis[x.F]) dfs(x.F); 
      else if(vis[x.F] == 1) { cyc=1; ans[x.S] = 2; }
    }
    
  vis[v] = 2;
   
}
void solve()
{
  int n,m,a,b;
    cin >> n >> m;
    
  f(i,m)
  {
    cin >> a >> b;
    g[a].pb({b,i});
  }
    
  f(i,n) if(!vis[i+1]) dfs(i+1);
 
  if(!cyc)
  {
      cout << "1\n";
      f(i,m) cout<< 1 <<" ";
  }
  else
  {
    cout << "2\n";
    f(i,m) cout << ans[i] <<" ";   
  }
     
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}