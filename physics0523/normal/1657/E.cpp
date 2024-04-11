#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define mod 998244353

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

int main(){
  cfact();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k;
  cin >> n >> k;
  n--;
  vector<vector<long long>> dp(k+1,vector<long long>(n+1,0));
  for(int i=1;i<=k;i++){dp[i][1]=1;}

  for(int c=2;c<=n;c++){
    vector<vector<long long>> ndp(k+1,vector<long long>(n+1,0));
    for(int i=1;i<=k;i++){
      for(int j=1;j<=n;j++){
        if(dp[i][j]==0){continue;}
        if(j+1<=n){ndp[i][j+1]+=dp[i][j];ndp[i][j+1]%=mod;}
        if(i+1<=k && j+1<=n){ndp[i+1][j+1]+=(mod-dp[i][j]);ndp[i+1][j+1]%=mod;}
        long long en=((c-1-j)*j)+(j*(j-1))/2;
        long long ce=power(k-i+1,en);
        ce*=invfact[j];ce%=mod;
        if(i+1<=k){ndp[i+1][1]+=dp[i][j]*ce;ndp[i+1][1]%=mod;}
      }
    }
    for(int i=1;i<=k;i++){
      for(int j=1;j<=n;j++){
        ndp[i][j]+=ndp[i-1][j];
        ndp[i][j]%=mod;
      }
    }
    dp.swap(ndp);
  }

  long long res=0;
  for(int i=1;i<=k;i++){
    for(int j=1;j<=n;j++){
      //cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
      long long en=((n-j)*j)+(j*(j-1))/2;
      long long ce=power(k-i+1,en);
      ce*=invfact[j];ce%=mod;
      res+=dp[i][j]*ce;
      res%=mod;
    }
  }
  cout << (res*factorial[n])%mod << '\n';
  return 0;
}