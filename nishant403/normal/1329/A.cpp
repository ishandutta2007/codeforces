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
  int n,m;
    cin >> n >> m;
    
   int a[m];
    f(i,m) cin >> a[i];
    
   int sum = 0; 
    
   int go[m]; 
    
  f(i,m)
  {
      int left = n - a[i];
      
      //technically if we put it at ith place how many cells are not used
      go[i] = n - a[i] - i;
      
      if(left < i) 
      {
          cout << -1;
          return;
      }
      
      sum+=a[i];
  }
    
  for(int i=m-2;i>=0;i--) go[i] = min(go[i],go[i+1]);  
    
  if(sum < n)
  {
      cout << -1;
      return;
  }
    
  int space = n - m;
  int last = -1; 
    
  vi res;  
   
  int off = 0;  
    
  f(i,m)
  {
      if(i == 0) res.pb(i);
      else
      {
          int prev = a[i-1];
          int ss = min(space,prev-1);
          ss = min(ss,go[i]-off); 
          space-=ss;
          off+=ss; 
          res.pb(res.back()+ss+1);
      }
      
      last = res.back();
  }
    
   for(auto x : res) cout << x+1 << " "; 
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}