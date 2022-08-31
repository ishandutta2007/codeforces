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


const int BT = 60;
int pw[BT];

void solve()
{
   int n;
    cin >> n;
    
   int a[n];
    f(i,n) cin >> a[i];
    
   vector<int> cnt(BT,0); 
   
    f(i,n) f(j,BT)
        if((a[i] >> j) & 1) cnt[j]++; 
    
   int res = 0;
    
   f(i,n) 
   {
      int and_sum = 0;
      int or_sum = 0;
        
      f(j,BT)
      {
          if((a[i] >> j) & 1)
          {
              and_sum+=pw[j]*cnt[j];
              and_sum%=MOD;
              
              or_sum+=n*pw[j];
              or_sum%=MOD;
          }
          else
          {
             or_sum+=pw[j]*cnt[j];
             or_sum%=MOD;
                 
          }
      }
       
      res+=(and_sum*or_sum)%MOD;
       res%=MOD;
   }
    
   cout << res << '\n'; 
}

signed main()
{
    pw[0]  =1;
    for(int i=1;i<BT;i++) pw[i] = (pw[i-1] + pw[i-1])%MOD;
    
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}