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
    int n,w;
    cin >> n >> w;
    
    pii a[n];
    f(i,n) cin >> a[i].F;
    f(i,n) a[i].S = i;
    sort(a,a+n);
    
    int mn = (w + 1)/2;
    
    vector<pii> chosen;
    f(i,n) if(a[i].F <= w) chosen.pb(a[i]);
    
    int sum = 0;
    for(auto x : chosen) sum+=x.F;
         
    if(sum < mn || chosen.empty())
    {
        cout << -1 << '\n';
    }
    else
    {
        int sum1 = 0;
        vector<int> id1;
        for(auto x : chosen)
            if(sum1 + x.F <= w) sum1+=x.F,id1.pb(x.S);;
            
        if(sum1 >= mn)
        {
            cout << id1.size() << '\n';
            for(auto v : id1) cout << v + 1 << ' ';
            cout << '\n';
        }
        else
        {
            cout << 1 << '\n';
            cout << chosen.back().S + 1 << '\n';
        }
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