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

const int inf = 1e18;

void solve()
{
   int n;
    cin >> n;
    
   int a[n];
    f(i,n) cin >> a[i];
    
   int cst = 0; 
    
   int mn_od = inf;
   int mn_ev = inf;
   int res = inf;
   int sum_od = 0;
   int sum_ev = 0;
    
   f(i,n)
   {
       if(i % 2 == 0) 
       {
           mn_ev = min(mn_ev , a[i]);
           sum_ev += a[i];
       }
       else
       {
           mn_od = min(mn_od , a[i]);
           sum_od += a[i];
       }
       
       //At this point I complete it
       if(i > 0)
       {
           int e_cnt = (i + 2)/2;
           int o_cnt = (i + 1)/2;
           int x_rem = n - e_cnt;
           int y_rem = n - o_cnt;
           
           int temp = (sum_od + sum_ev) + (x_rem*mn_ev) + (y_rem*mn_od);
           res = min(res,temp);
       }
   }
    
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