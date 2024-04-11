#include<bits/stdc++.h>

using namespace std;

long long mod;

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

long long nCr[512][512];
long long p2[512];

int main(){
  long long n;
  cin >> n >> mod;

  nCr[0][0]=1;
  for(int i=0;i<511;i++){
    for(int j=0;j<511;j++){
      nCr[i+1][j]+=nCr[i][j];nCr[i+1][j]%=mod;
      nCr[i+1][j+1]+=nCr[i][j];nCr[i+1][j+1]%=mod;
    }
  }
  p2[0]=1;
  for(int i=1;i<512;i++){p2[i]=(p2[i-1]+p2[i-1])%mod;}

  long long res=0;
  vector<vector<long long>> dp(n+2,vector<long long>(n+1,0));
  for(int i=0;i<=n;i++){dp[0][i]=1;}

  for(int j=0;j<=n;j++){//already decided
    for(int k=1;k<=n;k++){//life
      if((j+k)>n){break;}
      if(dp[j][k]==0){continue;}
      for(int l=1;l<=k;l++){
        if((j+l)>n){break;}
        long long del=dp[j][k];
        del*=nCr[k][l];del%=mod;
        del*=p2[l-1];del%=mod;
        dp[j+l+1][k-l]+=del;dp[j+l+1][k-l]%=mod;
      }
    }
  }

  cout << dp[n+1][0] << '\n';
  return 0;
}