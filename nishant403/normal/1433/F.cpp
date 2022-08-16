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

const int N = 80;
const int inf = 1e10;
vector<int> cur(N,0),nex(N,0);

void solve()
{
   int n,m,k;
    cin >> n >> m >> k;
    
   int a[n][m];
    f(i,n) f(j,m) cin >> a[i][j];
    
    f(i,k) cur[i] = -inf;
    cur[0] = 0;
    
   f(i,n)
   {
       //first get maximum sum for each modulo value
       int dp[N][N];
       f(p,N) f(q,N) dp[p][q] = -inf;
       dp[0][0] = 0;
       
       f(j,m) 
       {
           for(int p=m/2-1;p>=0;p--) f(q,k)
           {
               dp[p+1][(q + a[i][j])%k] = max(dp[p+1][(q + a[i][j])%k],dp[p][q] + a[i][j]);
           }
       }
       
       f(j,m/2) f(p,k) dp[m/2][p] = max(dp[m/2][p] , dp[j][p]);
       
       f(j,k) nex[j] = -inf;
       f(j,k) f(t,k) nex[(j+t)%k] = max(nex[(j+t)%k],cur[j] + dp[m/2][t]);
       swap(cur,nex);
   }
    
   cout << cur[0]; 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}