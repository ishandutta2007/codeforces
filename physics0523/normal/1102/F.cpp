#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<vector<int>> a(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){cin >> a[i][j];}
  }
  vector<vector<int>> f(n,vector<int>(n,1e9));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int v=1e9;
      for(int k=0;k<m;k++){
        v=min(v,abs(a[i][k]-a[j][k]));
      }
      f[i][j]=v;
    }
  }
  int res=0;
  for(int h=0;h<n;h++){
    vector<vector<int>> dp(1<<n,vector<int>(n,0));
    dp[(1<<h)][h]=1e9;
    for(int i=0;i<(1<<n);i++){
      for(int j=0;j<n;j++){
        if(dp[i][j]==0){continue;}

        for(int k=0;k<n;k++){
          if(i&(1<<k)){continue;}
          dp[i|(1<<k)][k]=max(dp[i|(1<<k)][k],min(dp[i][j],f[j][k]));
        }
      }
    }

    for(int t=0;t<n;t++){
      int cur=dp[(1<<n)-1][t];
      for(int i=1;i<m;i++){
        cur=min(cur,abs(a[h][i]-a[t][i-1]));
      }
      // if(cur==1){cout << h << ' ' << t << '\n';}
      res=max(res,cur);
    }
  }
  cout << res << '\n';
  return 0;
}