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
    
    int neg = 0;
    int zr = 0;
   
    f(i,n) f(j,m) if(a[i][j] < 0) neg++;
                  else if(a[i][j] == 0) zr = 1;
    
    int sum = 0;
    f(i,n) f(j,m) sum+=abs(a[i][j]);

    if(zr > 0 || (neg % 2 == 0))
    {
        cout << sum << '\n';
    }
    else
    {
        //minimum absolute value 
        int mn = abs(a[0][0]);
        f(i,n) f(j,m) mn = min(mn,abs(a[i][j]));
        sum-=mn+mn;
        cout << sum << '\n';
    }
    
     
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}