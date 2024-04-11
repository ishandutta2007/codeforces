#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;

int zt(int a,int b){return max(a,b)-min(a,b);}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n,a[128],c=0;
  int d[128][128];
  cin >> n;
  
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(a[i]==1){
      for(int j=0;j<n;j++){
        d[c][j]=zt(i,j);
      }
      c++;
    }
  }
  
  int dp[81][81][3232],ndp[81][81][3232],tr=0;
  
  for(int i=0;i<81;i++){
    for(int j=0;j<81;j++){
      for(int k=0;k<3232;k++){
        dp[i][j][k]=10000;
        ndp[i][j][k]=10000;
      }
    }
  }
  dp[0][0][0]=0;
  
  for(int i=0;i<n;i++){
    int mj=min(i,c);
    for(int j=0;j<=mj;j++){
      for(int k=0;(j+k)<=i;k++){
        for(int l=0;l<=tr;l++){
          if(dp[j][k][l]==10000){continue;}
          //put 0
          ndp[j][k][k+l]=min(dp[j][k][l],ndp[j][k][k+l]);
          tr=max(k+l,tr);
          //put 1
          ndp[j+1][i-j][l]=min(dp[j][k][l]+d[j][i],ndp[j+1][i-j][l]);
        }
      }
    }
    
    mj=min(i+1,c);
    for(int j=0;j<=mj;j++){
      for(int k=0;(j+k)<=(i+1);k++){
        for(int l=0;l<=tr;l++){
          dp[j][k][l]=ndp[j][k][l];
          ndp[j][k][l]=10000;
        }
      }
    }
  }
  
  int res[3232];
  for(int i=0;i<3232;i++){
    res[i]=-10000;
  }
  for(int i=0;i<81;i++){
    for(int j=0;j<=tr;j++){
      if(dp[c][i][j]==10000){continue;}
      res[dp[c][i][j]]=max(res[dp[c][i][j]],j);
    }
  }
  
  int lim=(n*(n-1))/2;
  for(int i=0;i<=lim;i++){
    if(i){cout << ' ';}
    cout << res[i];
    res[i+1]=max(res[i],res[i+1]);
  }cout << '\n';
  return 0;
}