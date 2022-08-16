#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int M = 1e8;

int dp[101][101][2][11];
int k1,k2;

int solve(int n1,int n2,bool flag ,int streak)
{
 
 if(dp[n1][n2][flag][streak] != -1 ) return dp[n1][n2][flag][streak];   

    int a=0,b=0,c=0,d=0;
    
 if(streak != k1 && flag == 0 && n1>0)
   a=solve(n1-1,n2,0,streak+1); 
    
       
 if(streak!=k2 && flag==1 && n2>0)   
    b=solve(n1,n2-1,1,streak+1);
    
    
 if(flag==0 && n2>0)   
    c=solve(n1,n2-1,1,1);
    
 if(flag==1 && n1>0)
    d=solve(n1-1,n2,0,1);
    
  return dp[n1][n2][flag][streak]=(a+b+c+d)%M;  
}

signed main()
{
 fast;

 int n1,n2;

 cin >> n1 >> n2 >> k1 >> k2;

 memset(dp,-1,sizeof(dp));   
    
  for(int i=0;i<=10;i++)  
dp[0][0][0][i] = dp[0][0][1][i] = 1;
    
cout << (solve(n1-1,n2,0,1) + solve(n1,n2-1,1,1) )%M;
}