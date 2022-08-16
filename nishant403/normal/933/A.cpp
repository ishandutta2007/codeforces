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

const int N = 2004;
int dp[N][N],temp[N][N][2];
int cn[N][2],a[N],n;

void solve()
{
  cin >> n;
    
  f(i,n) cin >> a[i];
  f(i,n) a[i]--;
    
  int ans = 0;
  
  f(i,n) 
  {   
    cn[i][0] = cn[i-1][0] + !a[i];
    cn[i][1] = cn[i-1][1] + a[i];
  }
  
 for(int i=1;i<=n/2;i++) swap(a[i],a[n-i+1]);      
         
 for(int i=1;i<=n;i++) 
      if(a[i] == 0) temp[i][i][0] = 1,temp[i][i][1] = 1;
      else temp[i][i][1] = 1;
                        
  for(int i=1;i<=n;i++)
  {
     for(int j=i+1;j<=n;j++) 
     {
       if(a[j] == 0) temp[i][j][0] = temp[i][j-1][0] + 1,temp[i][j][1] = max(temp[i][j-1][1],temp[i][j-1][0]+1);
       else temp[i][j][0] = temp[i][j-1][0],temp[i][j][1] = max(temp[i][j-1][1],temp[i][j-1][0])+1;  
     }
  }
    
       
  for(int i=1;i<=n;i++)
      for(int j=i;j<=n;j++)
         dp[i][j] = temp[i][j][1];
       
  for(int l=1;l<=n;l++)
  {
    for(int r=l;r<=n;r++)
    {
        int val = 0;
        val+=cn[n][1]-cn[r][1];
        val+=cn[l-1][0];
        val+=temp[n+1-r][n+1-l][1];
        
        ans=max(ans,val);
    }
  }
    
  cout << ans;
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}