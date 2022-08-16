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

const int N = 2005;

pii dp[N][N];
int box[N][N];
pii hor[N],ver[N];
vi freehor,freever;

int checkhor(int r,int l1,int l2)
{
  if(hor[r].F == 1e5) return 1;   
  if(hor[r].F >= l1 && l2 >= hor[r].S) return 1;
  return 0;
}

int checkver(int c,int l1,int l2)
{
  if(ver[c].F == 1e5) return 1;
  if(ver[c].F >= l1 && ver[c].S <= l2) return 1;
  return 0;
}

int free(int i,int j,int k)
{
    int h1 = i;
    int h2 = i+k;
    
    int hans = freehor.size();
    
    auto x1 = lower_bound(freehor.begin(),freehor.end(),h2);
    
    if(x1 == freehor.end()) hans = 0;
    else hans-=(x1-freehor.begin());
    
    auto x2 = lower_bound(freehor.begin(),freehor.end(),h1);
    
    if(x2 == freehor.end()) hans += (int)freehor.size();
    else hans+=(x2-freehor.begin());
    
    int v1 = j;
    int v2 = j+k;
    
    int vans = freever.size();
                           
    x1 = lower_bound(freever.begin(),freever.end(),v2);
    
    if(x1 == freever.end()) vans = 0;
    else vans-=(x1-freever.begin());
    
    x2 = lower_bound(freever.begin(),freever.end(),v1);
    
    if(x2 == freever.end()) vans += (int)freever.size();
    else vans+=(x2-freever.begin());
   
   return (hans+vans); 
}

void solve()
{
 int n,k,ans=0;
 string s;
    
 cin >> n >> k;   
    
 f(i,n)
 {
  cin >> s;
  f(j,n)   
  if(s[j]=='B') box[i][j] = 1;
  else box[i][j] = 0;
 }
 
 f(i,n)
 {
   hor[i].F = 1e5;  
     
     f(j,n) if(box[i][j]) 
     {
         hor[i].F = min(hor[i].F,j);
         hor[i].S = j;   
     }
     
     if(hor[i].F == 1e5) freehor.pb(i);
  
  ver[i].F = 1e5;
     
    f(j,n) if(box[j][i])
    {
      ver[i].F = min(ver[i].F,j);   
      ver[i].S = j;  
    }
     
    if(ver[i].F == 1e5) freever.pb(i);   
 }
    
    f(i,k) 
    { 
        dp[0][0].F+=checkhor(i,0,k-1); 
        dp[0][0].S+=checkver(i,0,k-1);
    }
    
  for(int i=1;i<n-k+1;i++) 
  {
      dp[i][0].F = dp[i-1][0].F - checkhor(i-1,0,k-1) + checkhor(i+k-1,0,k-1);
      f(j,k) dp[i][0].S+=checkver(j,i,i+k-1);
  }
    
  for(int i=1;i<n-k+1;i++)
  {
      dp[0][i].S = dp[0][i-1].S - checkver(i-1,0,k-1) + checkver(i+k-1,0,k-1);   
      f(j,k) dp[0][i].F+=checkhor(j,i,i+k-1);  
  }
    
  for(int i=1;i<n-k+1;i++)
      for(int j=1;j<n-k+1;j++)
  {
     dp[i][j].F = dp[i-1][j].F - checkhor(i-1,j,j+k-1) + checkhor(i+k-1,j,j+k-1);
     dp[i][j].S = dp[i][j-1].S - checkver(j-1,i,i+k-1) + checkver(j+k-1,i,i+k-1);     
  }
    
    
  f(i,n-k+1)
      f(j,n-k+1) ans=max(ans,dp[i][j].F + dp[i][j].S + free(i,j,k));
    
    cout <<ans;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}