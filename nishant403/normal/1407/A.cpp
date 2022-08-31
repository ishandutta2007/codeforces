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
   int n;
    cin >> n;
    
   int a[n];
    f(i,n) cin >> a[i];
 
   vi res;
    f(i,n) if(a[i] == 1) res.pb(i);
        
   if(res.empty())
    {
        cout << n << '\n';
        f(i,n) cout << 0 << ' ';
        cout << '\n';
        return;
    }
    else if(res.size() == 1)
    {
        cout << n-1 << '\n';
        f(i,n-1) cout << 0 << ' ';
        cout << '\n';
        return;
    }
    
    if(res.size() % 2 == 1) res.pop_back();
    
    int fir = res[0];
    int last = res.back();
    
    int ss = res.size();
    
    f(i,fir) if(a[i] == 0) res.pb(i);
    for(int i=last+1;i<n;i++) if(a[i] == 0)res.pb(i);
        
    //take zeroes between ones 
    for(int i=0;i<ss-1;i++)
    {
        //b/w res[i] and res[i+1]
        for(int j=res[i]+1;j<res[i+1];j+=2)
        {
            if(j + 1 < res[i+1])
                res.pb(j),res.pb(j+1);
        }
    }
        
    sort(res.begin(),res.end());    
        
    cout << res.size() << '\n';
    for(auto x : res) cout << a[x] << ' ';
    cout << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}