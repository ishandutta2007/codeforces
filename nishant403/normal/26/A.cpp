#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define N 5000

signed main()
{
    fast;
    int n,i,j;
    cin >> n;
    
   int dp[3010]={0};
    
  for(i=2;i<=3000;i++)
  {
   int k = i;
   set<int> ss;
      
    for(j=2;j<=k;j++)
    {
     if(k%j==0) 
        ss.insert(j); 
     while(k%j==0) k/=j;
        
    }
      
      
    dp[i]+=(ss.size()==2);   
         
    dp[i]+=dp[i-1];  
  }
    
    
    cout << dp[n];
}