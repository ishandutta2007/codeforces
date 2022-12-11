#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = (ll)1e9 + 7;
const int N = 5005;
ll dp[N][N];

int main(){
  int n;
  cin >> n;
  dp[0][0]=1;
  char l,cur;
  cin >> l;
  for(int i = 1;i<n;i++){
    cin >> cur;
    if(l=='f')
      for(int j = 1;j<N;j++)
        dp[i][j]=dp[i-1][j-1];
    else
      for(int j = n;j>=0;j--)
        dp[i][j]=(dp[i-1][j]+dp[i][j+1])%mod;
    l=cur;
  }
  ll ans = 0;
  for(int i = 0;i<N;i++)
    ans+=dp[n-1][i],ans%=mod;
  cout << ans;
  return 0;
}