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

int dp[34][34];

void solve()
{
  int d,m;
   cin >> d >> m;
 
  int bts = 0;  
    
  int cp = d;
    
  while(cp > 0)
  {
      cp>>=1;
      bts++;
  }
    
   int adder[bts+1];
   adder[1] = 1;
   for(int i=2;i<bts;i++) adder[i] = (adder[i-1]*2);
 
   int tt = 0;
   for(int i=1;i<bts;i++) tt+=adder[i];
    
   adder[bts] = (d - tt)%m;
   for(int i=1;i<bts;i++) adder[i]%=m;   
    
    
  memset(dp,0,sizeof(dp));
    
  for(int j=0;j<=bts;j++) dp[0][j] = 1; 
     
  //this is for length  
  for(int i=1;i<=bts;i++)
  {
     //this is for bits 
      for(int j=1;j<=bts;j++)
      {
          dp[i][j] = (dp[i-1][j-1]*(adder[j]))%m;
          dp[i][j] = (dp[i][j] + dp[i][j-1])%m;
      }
  }
 
   int res = 0;
    
  for(int i=1;i<=bts;i++) res = (res + dp[i][bts])%m;
    
   cout << res << '\n';
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}