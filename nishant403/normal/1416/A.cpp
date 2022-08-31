#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}


void solve()
{
  int n;
  cin >> n;
    
  int a[n];
  f(i,n) cin >> a[i];
    
  vector<int> g[n+1];
  for(int i=1;i<=n;i++) g[i].pb(-1);  
  for(int i=0;i<n;i++) g[a[i]].pb(i);  
  for(int i=1;i<=n;i++) g[i].pb(n);  
    
  int mx = n+10; 
  int val = -1;

   vector<pii> go; 
    
  for(int i=1;i<=n;i++)  
  {
      int sz = g[i].size();
      
      int dis = 0;
      
      for(int j=1;j<sz;j++) dis = max(dis,g[i][j] - g[i][j-1]);
     
      go.pb({dis,i}); 
  }
  
  sort(go.begin(),go.end());  
    
  int id = 0;
    
//  for(auto x : go) cout << x.F << ' ' << x.S << endl;
  
  val = n + 1;  
    
  for(int i=1;i<=n;i++)
  {
      while(id < n && go[id].F <= i)
      {
          val = min(val,go[id].S);
          id++;
      }
      
      if(val == n + 1) cout << -1 << ' ';
      else cout << val << ' ';
  }
    
  cout << '\n'; 
} 

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}