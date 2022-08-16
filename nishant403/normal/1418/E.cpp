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

const int MOD = 998244353;

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

const int N = 2e5 + 10;
int n,m;
int a[N];
int sums[N];

signed main()
{
    fast;
  
    cin >> n >> m;
    f(i,n) cin >> a[i];
    sort(a,a+n);
    
    f(i,n) sums[i] = a[i];
    f(i,n-1) sums[i+1]+=sums[i];
    
    while(m--)
    {
       int x,y;
        cin >> x >> y;
       
       int id = lower_bound(a,a+n,y) - a; 
       int more = n - id;
       int less = id;
       
       int sumless = 0;
       int summore = sums[n-1];
        
       if(id > 0)
       {
       sumless+=sums[id-1];
       summore-=sums[id-1];
       }
       
       if(more < x)
       {
           cout << 0 << '\n';
           continue;
       }
        
        
       int t1 = ((more - x)*mod_pow(more,MOD-2))%MOD; 
       int t2 = ((more - x + 1)*mod_pow(more+1,MOD-2))%MOD;
        
        sumless%=MOD;
        summore%=MOD;
        
       int res = (t1*summore) + (t2*sumless);
        res%=MOD;
        cout << res << '\n';
        
    }
        
}