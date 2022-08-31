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

const int N = 1e3 + 10;
int n;
int a[N];
int res = 0;

unordered_map<int,int> get(vector<int> & a)
{
    unordered_map<int,int> cur,nex,res;
    
    cur[0] = 1;
    
    for(auto x : a)
    {
        nex.clear();
        
        for(auto z : cur)
        {
            nex[x + z.F] += z.S;
            nex[- x + z.F] += z.S;
            nex[x + z.F] %= MOD;
            nex[- x + z.F] %= MOD;
        }
        
        swap(cur,nex);
        
        for(auto z : cur) 
        {
            res[z.F] += z.S;
            res[z.F] %= MOD;
        }
    }
    
    return res;
}

void go(int l,int r)
{
    if(l >= r) return;
    
    int mid = (l + r)/2;
    
    go(l,mid); go(mid + 1,r);
    
    vi pref,suf;
    
    for(int i=mid;i>=l;i--) pref.pb(a[i]);
    for(int i=mid+1;i<=r;i++) suf.pb(a[i]);
    
    auto P = get(pref);
    auto S = get(suf);
    
    for(auto x : P)
    {
        res += (x.S)*S[-x.F]; 
        res %= MOD;
    }
}

void solve()
{
   cin >> n;
   f(i,n) cin >> a[i];
    
   go(0,n-1);
    
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