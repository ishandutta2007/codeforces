#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 2005;
const int inf = 2e18;

pii go[N][N];
int dp[N];
int n,k;
int l[N],r[N],a[N];

void solve()
{
   cin >> n >> k;
    
   for(int i=1;i<=n;i++) cin >> l[i] >> r[i] >> a[i];
    
   int tot = 0;
    f(i,n) tot+=a[i];
    
   for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++) go[i][j] = {-1,-1};
       
   for(int i=1;i<=n;i++)
   {
       int blts = k;
       
       for(int j=i;j<=n;j++)
       {
           if(go[i][j-1].S != -1 && go[i][j-1].S < l[j])
           {
               if(blts == 0) blts = k;
           }
           
           if(a[j] - blts > (r[j] - l[j])*k) break;
           
           int orr = blts;
           
           if(a[j] < blts) blts-=a[j];
           else
           {
               blts = (k - ((a[j]-blts) % k))%k;
           }
       
           if((r[j] - l[j] -1)*k >= a[j] - orr)
           {
               if(blts == 0) blts = k;   
               go[i][j].F = blts;
               go[i][j].S = r[j] - 1;
           }
           else
           {
               go[i][j].F = blts;
               go[i][j].S = r[j] ;
           }
       }
   }
    
   l[n+1] = r[n+1] = inf;
    
   for(int i=1;i<=n;i++) dp[i] = inf;
   dp[0] = 0;
       
   //0 means can not take neww 
   //1 means can take new
    
   for(int i=0;i<n;i++)
    for(int j=i;j<n;j++)
   {
       if(go[i+1][j+1].F == -1) continue;
       
       if(dp[i] == inf) continue;
       
       if(j + 1 < n)
       {
       if(go[i+1][j+1].S < l[j+2]) dp[j+1] = min(dp[j+1],dp[i] + go[i+1][j+1].F);
       }
       else dp[j+1] = min(dp[j+1] , dp[i]);
   }
    
    int res = dp[n];
    
   if(res == inf) cout << -1;
   else cout << res + tot;
}


signed main()
{
    fast;
    solve();
}