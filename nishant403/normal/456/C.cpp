#include <bits/stdc++.h>
using namespace std;

#define int long long 

int dp[100005] = {0};

signed main()
{
 int n,x;
    cin >> n;
    
    int c[100001]={0};
    
    for(int i=0;i<n;i++) 
    {
        cin >> x;
        c[x]++;
    }
    
int N = 100000;
    
  dp[0] = 0;  
  dp[1] = c[1];
  dp[2] = max(2*c[2],c[1]);
    
    for(int i=3;i<=N;i++)
        dp[i] = max(dp[i-1],(c[i]*i)+dp[i-2]);
    
    cout << max(dp[N],dp[N-1]);
    
}