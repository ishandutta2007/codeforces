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

const int N = 1e5 + 10;

int n,ad,d,m,eff;
int a[N];
int b[N];

int go(int x)
{
    int add = 0;
    int rm = 0;
    
    auto v = lower_bound(a,a+n,x+1) - a - 1;
    
    add = (x*(v+1)) - b[v];
    rm = b[n-1] - b[v] - (x*(n - v - 1));
    
    if(add > rm) return (rm*eff) + ( add - rm)*ad;
    return (add*eff) + (rm - add)*d; 
}

void solve()
{
    cin >> n >> ad >> d >> m;
    
    eff = min(m,ad + d);
    
    f(i,n) cin >> a[i];
    
    sort(a,a+n);
    
    f(i,n) b[i] = a[i];
    f(i,n-1) b[i+1] += b[i];
    
    int l = a[0];
    int r = a[n-1];
    
    while( (r-l) > 10)
    {
        int m1 = l + (r-l+1)/3;
        int m2 = r - (r-l+1)/3;
        
        if(go(m1) > go(m2)) l = m1;
        else r = m2;
    }
    
    int res = 4e18;
    
    for(int i=l;i<=r;i++) res = min(res,go(i));
    
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