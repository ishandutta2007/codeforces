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
    
   map<int,int> mp;
    
    for(int i=2;(i*i) <= n;i++)
    {
        while(n % i == 0)
        {
            mp[i]++;
            n/=i;
        }
    }
    
    if(n > 1) mp[n]++;
    
    int mx = 0;
    
    for(auto x : mp) mx = max(mx,x.S);
    
    cout << mx << '\n';
   
    vector<int> res(mx,1);
    
    for(auto x : mp)
        f(i,x.S) res[i]*=x.F;
    
    reverse(res.begin(),res.end());
    
    for(auto x : res) cout << x << ' ';
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