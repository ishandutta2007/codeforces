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

const int MOD = 998244353;

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

const int N = 2e5 + 10;
int fct[N];

void solve()
{
   int n;
   cin >> n;
    
   vi a(n);
    f(i,n) cin >> a[i];
       
   sort(all(a));
    
   if(a[n-1] - a[n-2] >= 2)
   {
       cout << 0 << '\n';
       return;
   }
   else if(a[n-1] == a[n-2])
   {
       cout << fct[n] << '\n';
       return;
   }
   else
   {
       int res = fct[n];
       
       int cnt = 1;
       for(auto x : a) if(x == a[n-1] - 1) cnt++;
           
       int sub = (res*mod_pow(cnt,MOD-2))%MOD;
       
       res = (res + MOD - sub)%MOD;
       
       cout << res << '\n';
   }
   
}

signed main()
{
    fct[0] = 1;
    for(int i=1;i<N;i++) fct[i] = (fct[i-1]*i)%MOD;
    
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}