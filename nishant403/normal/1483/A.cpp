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
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = 1e5 + 10;
vi g[N];
int must[N];
int choice[N];

void solve()
{
   int n,m;
    cin >> n >> m;
    
  f(i,m) g[i].clear();
    
  f(i,n) must[i] = 0;  
  f(i,m) choice[i] = 0;  
    
  f(i,m)
  {
      int sz;
      cin >> sz;

      int x;
      
      f(j,sz) 
      {
          cin >> x;
          x--;
          g[i].pb(x);
      }
      
      if(sz == 1)
      {
          must[x]++;
          choice[i] = x;
      }
  }
  
  f(i,n) if(must[i] > (m+1)/2)
  {
      cout <<"NO\n";
      return;
  }
   
  f(i,m)
  {
      if(g[i].size() > 1)
      {
          int mn = 0;
          
          for(int j=0;j<g[i].size();j++)
          {
              if(must[g[i][j]] < must[g[i][mn]]) mn = j;
          }
          
          must[g[i][mn]]++;
          choice[i] = g[i][mn];
      }
  }

  cout <<"YES\n";
    
  f(i,m) cout << choice[i] + 1 << ' ';
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