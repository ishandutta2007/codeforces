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

const int MOD = 998244353;

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

const int N = 3e5 + 10;

int n,m;
string s[N];

int go2(int n)
{
    n--;
    
    int res = (n + n + n + 1);
    res = (res*mod_pow(2,n))%MOD;
    
    if((n & 1) == 0) res = (res + MOD - 1)%MOD;
    else res = (res + 1)%MOD;
    
    res = (res*mod_pow(9,MOD-2))%MOD;
    
    return res;
}

int go(int tot,int x)
{
    if(x <= 1) return 0;
    
    int ways = mod_pow(2,tot-x);
    ways = (ways*go2(x))%MOD;
    
    return ways;
}

void solve()
{
    cin >> n >> m;   
    
    f(i,n) cin >> s[i];
    
    int tot = 0;
    
    f(i,n) f(j,m) tot += (s[i][j] == 'o');
    
    int res = 0;
    
    //horizontal
    f(i,n)
    {
        int cnt = 0;
        
        f(j,m)
        {
            if(s[i][j] == '*')
            {
                res = (res + go(tot,cnt))%MOD;
                cnt = 0;
            }
            else cnt++;
        }
        
        res = (res + go(tot,cnt))%MOD;
    }
    
    //vertical
    
    //horizontal
    f(j,m)
    {
        int cnt = 0;
        
        f(i,n)
        {
            if(s[i][j] == '*')
            {
                res = (res + go(tot,cnt))%MOD;
                cnt = 0;
            }
            else cnt++;
        }
        
        res = (res + go(tot,cnt))%MOD;
    }
    
    cout << res ;
}

signed main()
{
    fast;
    solve();
}