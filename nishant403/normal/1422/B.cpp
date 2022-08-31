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
    
    int a[n][m];
    f(i,n) f(j,m) cin >> a[i][j];
    
    bool vis[n][m];
    f(i,n) f(j,m) vis[i][j] = 0;
    
    int res = 0;
    
    f(i,n) f(j,m)
    {
       if(vis[i][j]) continue;
        
       vi go; 
       go.pb(a[i][j]); 
       vis[i][j] = 1;
        
       if(vis[n-i-1][j] == 0) 
       {
           vis[n-i-1][j] = 1;
           go.pb(a[n-i-1][j]);
       }
        
       if(vis[i][m-j-1] == 0) 
       {
           vis[i][m-j-1] = 1;
           go.pb(a[i][m-j-1]);
       }
        
        if(vis[n-i-1][m-j-1] == 0) 
       {
           vis[n-i-1][m-1-j] = 1;
           go.pb(a[n-i-1][m-1-j]);
       }
        
       sort(go.begin(),go.end()); 
        
       int sz = go.size();
       int elm = go[sz/2];
        
       for(auto x : go) res+=abs(x-elm);
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