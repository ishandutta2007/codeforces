#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<long long>> a(n,vector<long long>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
    }
  }

  vector<vector<long long>> dp(n,vector<long long>(n,-8e18));
  dp[0][0]=a[0][0];
  for(int s=1;s<=2*(n-1);s++){
    vector<vector<long long>> ndp(n,vector<long long>(n,-8e18));
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(dp[i][j] < -4e18){continue;}
        for(int di=0;di<=1;di++){
          for(int dj=0;dj<=1;dj++){
            int ni=i+di,nj=j+dj;
            int ri=s-ni,rj=s-nj;
            if(!(0<=ni && ni<n)){continue;}
            if(!(0<=nj && nj<n)){continue;}
            if(!(0<=ri && ri<n)){continue;}
            if(!(0<=rj && rj<n)){continue;}
            long long add;
            if(ni==nj){
              add=a[ni][ri];
            }
            else{
              add=a[ni][ri]+a[nj][rj];
            }
            ndp[ni][nj]=max(dp[i][j]+add,ndp[ni][nj]);
          }
        }
      }
    }
    dp=ndp;
  }
  cout << dp[n-1][n-1] << "\n";
  return 0;
}