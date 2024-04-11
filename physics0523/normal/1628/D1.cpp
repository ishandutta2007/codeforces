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

long long factorial[524288];
long long invfact[524288];

void cfact(){
  long long i;
  factorial[0]=1;
  factorial[1]=1;
  for(i=2;i<524288;i++){
    factorial[i]=factorial[i-1]*i;
    factorial[i]%=mod;
  }
  invfact[524287]=modular_inverse(factorial[524287]);
  for(i=524286;i>=0;i--){
    invfact[i]=invfact[i+1]*(i+1);
    invfact[i]%=mod;
  }
}

long long calcnCr(long long n,long long k){
  if(k<0 || n<k){return 0;}
  return (factorial[n]*((invfact[k]*invfact[n-k])%mod))%mod;
}

long long inv2;
long long dp[2048][2048];
long long rep(long long n,long long m){
  if(n==m){return n;}
  if(m==0){return 0;}
  if(dp[n][m]>=0){return dp[n][m];}
  dp[n][m]=(rep(n-1,m)+rep(n-1,m-1))%mod;
  dp[n][m]*=inv2;dp[n][m]%=mod;
  return dp[n][m];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  inv2=modular_inverse(2);
  for(int i=0;i<2048;i++){
    for(int j=0;j<2048;j++){dp[i][j]=-1;}
  }
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,m,k;
    cin >> n >> m >> k;
    cout << (rep(n,m)*k)%mod << '\n';
  }
  return 0;
}