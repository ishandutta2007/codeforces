#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 18;
const int F = (1<<N);

ll bef[N][N];
ll dp[F][N];

int main(){
  int n,m,k; 
  cin >> n >> m >> k;
  ll a[n];
  for(int i =0;i<n;i++)
    cin >> a[i];
  int x,y;
  ll z;
  while(k--){
    cin >> x >> y >> z;
    bef[x-1][y-1]=z;
  }
  for(int v = 0;v<n;v++)
    dp[(1<<v)][v]=a[v];
  for(int mask = 1;mask<(1<<n);mask++){
    for(int i = 0;i<n;i++)
      if((mask&(1<<i)))
        for(int j = 0;j<n;j++)
          if((mask&(1<<j))==0)
            dp[(mask|(1<<j))][j]=max(dp[(mask|(1<<j))][j],dp[mask][i]+bef[i][j]+a[j]);
  }
  ll ans = 0;
  for(int i = 0;i<(1<<n);i++){
    if(__builtin_popcount(i)==m)
      for(int j = 0;j<n;j++)
        ans=max(ans,dp[i][j]);
  }
  cout << ans << "\n";
  return 0;
}