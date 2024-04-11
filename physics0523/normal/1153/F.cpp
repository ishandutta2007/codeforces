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
  long long n,k,l;
  cin >> n >> k >> l;
  vector<vector<long long>> dp(n+1,vector<long long>(2,0));
  dp[0][0]=1;
  for(int cp=0;cp<=(2*n);cp++){
    vector<vector<long long>> ndp(n+1,vector<long long>(2,0));
    for(int i=0;i<=n;i++){
      for(int j=0;j<=1;j++){
        if(dp[i][j]==0){continue;}
        if(i<n){ // open
          ndp[i+1][j]+=dp[i][j];
          ndp[i+1][j]%=mod;
        }
        if(i>0){ // close
          ndp[i-1][j]+=dp[i][j]*((long long)i);
          ndp[i-1][j]%=mod;
        }
        if(i>=k && j==0){ // put
          ndp[i][j+1]+=dp[i][j];
          ndp[i][j+1]%=mod;
        }
      }
    }
    dp.swap(ndp);
  }
  long long res=dp[0][1];
  long long div;
  div=factorial[2*n+1];
  div*=modular_inverse(power(2,n));div%=mod;
  div*=invfact[n];div%=mod;
  res*=modular_inverse(div);res%=mod;
  res*=l;res%=mod;
  cout << res << '\n';
  return 0;
}