#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

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

long long modular_inverse(long long n){
  return power(n,mod-2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k;
  cin >> n >> k;
  long long minv[512];
  for(int i=1;i<512;i++){minv[i]=modular_inverse(i);}
  //dp[hand][elem]
  long long dp[256][512]={0},ndp[256][512]={0};
  dp[0][0]=1;
  for(int i=2;i<=k+1;i++){//cycle size=i
    long long ce=1,div=minv[i];
    for(int j=1;(i-1)*j<=k;j++){//cicle pcs
      ce*=minv[j];ce%=mod;
      ce*=div;ce%=mod;
      for(int p=k-(i-1)*j;p>=0;p--){
        for(int q=0;(q+i*j)<=n && q<=2*p;q++){
          if(dp[p][q]==0){continue;}
          ndp[p+(i-1)*j][q+i*j]+=(dp[p][q]*ce);
          ndp[p+(i-1)*j][q+i*j]%=mod;
        }
      }
    }
    for(int p=0;p<256;p++){
      for(int q=0;q<512;q++){
        dp[p][q]+=ndp[p][q];
        dp[p][q]%=mod;
        ndp[p][q]=0;
      }
    }
  }

  long long res[512]={0};
  for(int i=0;i<256;i++){
    long long ce=1;
    for(int j=0;j<512;j++){
      dp[i][j]*=ce;dp[i][j]%=mod;
      res[i]+=dp[i][j];res[i]%=mod;
      //if(dp[i][j]){cerr << i << ' ' << j << ':' << dp[i][j] << '\n';}
      ce*=(n-j);ce%=mod;
      if(ce==0){break;}
    }
  }

  for(int i=1;i<=k;i++){
    if(i-1){cout << ' ';}
    if(i>=2){res[i]+=res[i-2];res[i]%=mod;}
    cout << res[i];
  }cout << '\n';
  return 0;
}