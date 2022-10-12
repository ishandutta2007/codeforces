#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long nCr[1024][1024]={0};

void prenCr(){
  nCr[0][0]=1;
  for(int i=1;i<=1023;i++){
    for(int j=0;j<=i;j++){
      nCr[i][j]+=nCr[i-1][j];
      if(j){nCr[i][j]+=nCr[i-1][j-1];}
      nCr[i][j]%=mod;
    }
  }
}

long long f(long long n,long long r,long long z){
  vector<long long> dp(n+1,0);
  dp[0]=1;
  for(int dg=60;dg>=0;dg--){
    vector<long long> ndp(n+1,0);
    int sta;
    if(z&(1ll<<dg)){sta=1;}else{sta=0;}
    int del;
    if(r&(1ll<<dg)){del=1;}else{del=0;}
    for(int i=0;i<=n;i++){
      for(int j=sta;j<=n;j+=2){
        int nex=min(((int)n),2*i+del-j);
        if(nex<0){continue;}
        ndp[nex]+=dp[i]*nCr[n][j];
        ndp[nex]%=mod;
      }
    }
    dp=ndp;
  }
  long long res=0;
  for(auto &nx : dp){res+=nx;}
  return res%mod;
}

int main(){
  prenCr();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,l,r,z;
  cin >> n >> l >> r >> z;
  cout << (mod+f(n,r,z)-f(n,l-1,z))%mod << '\n';
  return 0;
}