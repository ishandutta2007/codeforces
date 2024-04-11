#include<bits/stdc++.h>
#define inf 2000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,l,k;
  cin >> n >> l >> k;
  vector<int> d(n),a(n);
  for(auto &nx : d){cin >> nx;}
  for(auto &nx : a){cin >> nx;}
  d.push_back(l);
  vector<vector<int>> dp(n,vector<int>(k+1,inf));
  dp[0][0]=d[1]*a[0];
  for(int c=1;c<n;c++){
    int seg=d[c+1]-d[c];
    vector<vector<int>> ndp(n,vector<int>(k+1,inf));
    for(int i=0;i<c;i++){
      for(int j=0;j<=k;j++){
        if(dp[i][j]>=inf){continue;}
        if(j!=k){
          ndp[i][j+1]=min(ndp[i][j+1],dp[i][j]+a[i]*seg);
        }
        ndp[c][j]=min(ndp[c][j],dp[i][j]+a[c]*seg);
      }
    }
    dp.swap(ndp);
  }

  int res=inf;
  for(int i=0;i<n;i++){
    for(int j=0;j<=k;j++){
      res=min(res,dp[i][j]);
    }
  }
  cout << res << '\n';
  return 0;
}