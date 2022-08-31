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

const int MOD = 998244353;

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

const int N = 2e5 + 10;
int dp[N];

void solve()
{ 
   int odd_sum = 0,even_sum = 0;
    
   dp[0] = 1;
    
   for(int i=1;i<N;i++)
   {
      if(i % 2 == 1)
      {
          dp[i] = (1 + even_sum)%MOD;
          odd_sum = (odd_sum + dp[i])%MOD;
      }
      else
      {
          dp[i] = (dp[i] + odd_sum)%MOD;
          even_sum = (even_sum + dp[i])%MOD;
      }
   }
    
   int n;
   cin >> n;
    
   int res = dp[n];
    res = (res*mod_pow(mod_pow(2,n),MOD-2))%MOD;
    cout << res;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}