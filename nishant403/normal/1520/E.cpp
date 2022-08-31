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


void solve()
{
   int n;
    cin >> n;
    
   string s;
    cin >> s;
    
   vector<int> a;
    
   f(i,n) if(s[i] == '*') a.pb(i);
       
   int res = 0;
    
   int sum_l = 0,cnt_l = 0,sum_r = 0,cnt_r = 0;
   
   n =  a.size();
    
   f(i,n) cnt_r += 1,sum_r += a[i];
    
   res = n*1e6; 
    
   f(i,n)
   {
       cnt_r -= 1;
       sum_r -= a[i];
       
       int tmp = (sum_r) - (cnt_r*a[i]) - (cnt_r*(cnt_r+1))/2;
       tmp += (cnt_l*a[i]) - (sum_l) - (cnt_l*(cnt_l + 1))/2;
       
       res = min(res,tmp);
       
       cnt_l += 1;
       sum_l += a[i];
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