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
   int u,v;
    cin >> u >> v;
    
    if(u == 0 && v == 0)
    {
        cout << 0;
        return;
    }
    
    if(u == v)
    {
        cout << 1 << endl; // fucked up
        cout << u;
        return;
    }
    
    if((v%2) != (u%2))
    {
        cout << -1;
        return;
    }
    
    if(v < u)
    {
        cout << -1;
        return;
    }
    
    //check 2 element
    int x = 0;
    int y = 0;
    
    int sum = v;
    
    for(int i=59;i>=0;i--)
    {
        if((u&(1LL<<i)) > 0)
        {
            x|=(1LL<<i);
            sum-=(1LL<<i);
        }
        else if(sum >= (1LL<<(i+1)))
        {
            x|=(1LL<<i);
            y|=(1LL<<i);
            sum-=(1LL<<(i+1));
        }
    }
    
    if((x+y) == v && ((x^y) == u))
    {
        cout << 2 << '\n';
        cout << x <<" "<<y;
        return;
    }
    
    cout << 3 << endl;;
    cout << u <<" "<<(v-u)/2 << " "<<(v-u)/2 << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}