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

const int N = 103;
const int inf = 1e18;
int a[N][N];
int dp[N][N];

void solve()
{
   int n,m;
    cin >> n >> m;
    
   f(i,n) f(j,m) cin >> a[i][j]; 
    
   int res = inf;
    
   f(ii,n) f(jj,m)
   {
       //let starting height be this
       int ht = a[ii][jj] - ii - jj;
       
       f(i,n) f(j,m)
       {
           
           if(a[i][j] < ht + i + j) 
           {
               dp[i][j] = inf;
               continue;
           }
           
           dp[i][j] = a[i][j] - ht - i - j;
           
           if(i == 0 && j > 0) dp[i][j]+=dp[i][j-1];
           else if(j == 0 && i > 0) dp[i][j]+=dp[i-1][j];
           else if(i > 0 && j > 0) dp[i][j]+=min(dp[i-1][j],dp[i][j-1]);
       }
       
       res = min(res,dp[n-1][m-1]);
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