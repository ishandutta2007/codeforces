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

const int BT = 20;

//count of integers from [0,n] where bit b is set 
int get(int n,int b)
{
    int res = 0;
    
    for(int i=BT-1;i>=b;i--)
    {
        if((n >> i) & 1)
        {
            n ^= (1LL<<i);
            
            if(i > b)
            {
                res += (1LL<<(i - 1));
            }
            else
            {
                res += n + 1;
            }
            
        }
    }
    
    return res;
}

void solve()
{
    int l,r;
    cin >> l >> r;
    
    int res = r - l + 1;
    
    for(int i=0;i<BT;i++)
        res = min(res,(r-l+1) - (get(r,i) - get(l-1,i)));
    
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