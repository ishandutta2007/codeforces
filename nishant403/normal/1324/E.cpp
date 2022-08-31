#include <bits/stdc++.h>
using namespace std;
  
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

const int N = 2004;
int dp[N][N];

void solve()
{
   int n,h,l,r;
   cin >> n >> h >> l >> r;
    
   int a[n];
   f(i,n) cin >> a[i];
   
   f(i,2001) f(j,2001) dp[i][j] = -100000;
    
   dp[0][a[0]] = (a[0] >= l && a[0] <= r);
   dp[0][a[0]-1] = (a[0]-1 >= l && a[0]-1 <= r);
    
   for(int i=1;i<n;i++)
   {
       for(int j=0;j<h;j++)
       {
           int next = (j+a[i])%h;
           dp[i][next] = max(dp[i][next],dp[i-1][j] + (next >= l && next <= r));
           
           next = (j+a[i]-1)%h;
           dp[i][next] = max(dp[i][next],dp[i-1][j] + (next >= l && next <= r));
     
       }
   }
    
    int res = 0;
    
    for(int i=0;i<h;i++) res=max(res,dp[n-1][i]);
    
    cout << res;
    
    
}

signed main()
{
    fast;
    solve();
}