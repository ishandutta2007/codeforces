#include<bits/stdc++.h>
#define inf 1072114514

using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  vector<int> a(n),b(n);
  double sw=0.0;
  for(int i=0;i<n;i++){
    scanf("%d%d",&a[i],&b[i]);
    sw+=b[i];
  }
  int dp[128][16384];
  for(int i=0;i<128;i++){
    for(int j=0;j<16384;j++){dp[i][j]=-inf;}
  }
  dp[0][0]=0;
  for(int i=0;i<n;i++){
    for(int j=i;j>=0;j--){
      for(int k=0;k<=100*j;k++){
        if(dp[j][k]==-inf){continue;}
        dp[j+1][k+a[i]]=max(dp[j+1][k+a[i]],dp[j][k]+b[i]);
      }
    }
  }
  vector<double> res(n+1,0.0);
  for(int i=0;i<128;i++){
    for(int j=0;j<16384;j++){
      if(dp[i][j]==-inf){continue;}
      double cw=((double)dp[i][j]),pw;
      pw=sw-cw;
      res[i]=max(min(cw+(pw/2.0),((double)j)),res[i]);
    }
  }
  for(int i=1;i<=n;i++){
    if(i!=1){printf(" ");}
    printf("%.12lf",res[i]);
  }printf("\n");
  return 0;
}