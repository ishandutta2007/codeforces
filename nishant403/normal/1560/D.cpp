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

vector<int> dg(int x)
{
    vector<int> vs;
    
    while(x > 0)
    {
        vs.pb(x % 10);
        x/=10;
    }
    
    reverse(all(vs));
    
    return vs;
}

int go(int x,int y)
{
    vector<int> X = dg(x), Y = dg(y);
    
    int match = 0;
    
    for(auto z : X)
    {
        if(Y[match] == z) match++;
        
        if(match == Y.size()) break;
    }
    
    int rm = (int)X.size() - match;
    int ad = (int)Y.size() - match;
    
    return rm + ad;
}

void solve()
{
   int n;
   cin >> n;
    
   int res = 100000;
    
   f(i,60)
   {
       res = min(res,go(n,(1LL<<i)));
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