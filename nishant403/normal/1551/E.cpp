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

const int N = 2e3 + 10;
int dp[N][N];
int a[N];

//solve(i,j) => returns maximum number of fixed points when,
//              processed i elements and 
//              used j operations    

int solve(int i,int j)
{
    if(i <= 0) return 0;
        
    int & res = dp[i][j];
    if(res != -1) return res;
    else res = 0;
    
    //now we focus on what to do with element at index (i-1)
    
    //perform operation
    if(j > 0) res = max(res,solve(i-1,j-1));
    
    //not perform operation, also do not benefit from it
    res = max(res,solve(i-1,j));
    
    //not perform operation, try to benefit if possible
    int ind = (i-1) - j;
    
    if(ind == a[i-1]) res = max(res,solve(i-1,j) + 1);
    
    return res;
}

void solve()
{
   int n,k;
   cin >> n >> k;
    
   for(int i=0;i<n;i++) 
   {
       cin >> a[i]; 
       a[i]--;
   }
    
   for(int i=0;i<=n+5;i++)
    for(int j=0;j<=n+5;j++) 
       dp[i][j] = -1;
       
   int res = -1;
    
   for(int i=n-1;i>=0;i--)
       if(solve(n,i) >= k) res = i;
    
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