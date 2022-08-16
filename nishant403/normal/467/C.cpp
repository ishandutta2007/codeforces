#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define vi vector<int>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int m;
const int N = 5001;

int dp[N][N],p[N],pref[N+2];

int solve(int n,int k)
{   
 if(k==0) return 0;
 if(n<0) return 0;
    
  if(dp[n][k] != -1) return dp[n][k];  
 
  int ans = 0;
    
  if(n>0) ans = solve(n-1,k);
    
  if(n>=m-1) ans =max( pref[n+1] - pref[n+1-m] + solve(n-m,k-1) , ans );  
    
  return dp[n][k] = ans;  
}


signed main ()
{
  Fast;
  
    int n,k;
    
  cin >> n >> m >> k;  
  
  memset(dp,-1,sizeof(dp));  
    
  f(i,n) cin >> p[i];
    
  pref[0] = 0;
    
  f(i,n) pref[i+1] = pref[i] + p[i];  
    
  cout << solve(n-1,k);  
}