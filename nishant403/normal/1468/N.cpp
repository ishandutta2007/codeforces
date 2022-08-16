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
   int c[3],a[5];
    f(i,3) cin >> c[i];
    f(i,5) cin >> a[i];
    
   f(i,3) c[i] -= a[i]; 
    
   f(i,3) if(c[i] < 0)
   {
       cout << "NO\n";
       return;
   }
    
   int m1 = min(c[0],a[3]);
   c[0] -= m1;
   a[3] -= m1;
    
   int m2 = min(c[1],a[4]);
   c[1] -= m2;
   a[4] -= m2;
    
   if(c[2] >= a[3] + a[4]) cout <<"YES\n";
    else cout <<"NO\n";
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}