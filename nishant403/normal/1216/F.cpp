#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 2e5+10;
int dp[N],pos[N],n,k;
string s;

signed main ()
{
  cin >> n >> k >> s;
    
  pos[n+1] = n+1;
    
  for(int i=n;i>=1;i--)
  {
   if (s[i-1] == '1') pos[i]=i;
   else pos[i]=pos[i + 1];
  }
    
  for (int i = 1; i <= n; i++)
  {
    dp[i] = dp[i-1] + i;
	    
	int x = pos[max ((int)1, i - k)];
	if (x == n + 1 || x > i + k) continue;
	dp[i] = min (dp[i], x + dp[max ((int)1, x - k) - 1]);
  }
      
  cout << dp[n] << endl;   
}