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

int dp[4001] ;    
int n,a,b,c;

int solve(int n)
{
 if(n<0) return -999999;   
 if(n==0) return 0;      
 if(dp[n]!=-1) return dp[n];   
    
 return dp[n] = max(solve(n-a)+1,max(solve(n-b)+1,solve(n-c)+1));   
}

signed main()
{
Fast;    

memset(dp,-1,sizeof(dp));
    
cin >> n >> a >> b >> c;    
cout << solve(n) << " ";        
}