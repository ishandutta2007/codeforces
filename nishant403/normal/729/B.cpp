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

int dp[1001][1001]={0};

void solve()
{
int n,m;
cin >> n >> m;
    
int a[n][m];
    
f(i,n) f(j,m) cin >> a[i][j];
    
f(i,n)    
{
    
f(j,m)    
{
 if(a[i][j] == 1)
 {  
     for(;j<m;j++) if(a[i][j] == 0) dp[i][j]++;   
    break;
 }
}

for(int j=m-1;j>=0;j--)  
{
 if(a[i][j] == 1)
 {  
     for(;j>=0;j--) if(a[i][j] == 0) dp[i][j]++;   
    break;
 }
}    
 
}
    
  
f(j,m)    
{
    
f(i,n)    
{
 if(a[i][j] == 1)
 {  
     for(;i<n;i++) if(a[i][j] == 0) dp[i][j]++;   
    break;
 }
}

for(int i=n-1;i>=0;i--)  
{
 if(a[i][j] == 1)
 {  
     for(;i>=0;i--) if(a[i][j] == 0) dp[i][j]++;   
    break;
 }
}    
 
}    
 
    
     
 int ans = 0;   
    
 f(i,n) f(j,m) ans+=dp[i][j];
    
 cout << ans;
    
}

signed main()
{
    fast;
    solve();
}