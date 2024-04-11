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

int main(){
  cfact();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k;
  cin >> n >> k;
  if(k==1){cout << "1\n";return 0;}
  long long res=0;
  for(long long i=0;i<=n;i++){
    for(long long j=0;j<=n;j++){
      long long ce;
      ce=(calcnCr(n,i)*calcnCr(n,j))%mod;
      long long white=(n-i)*(n-j);
      long long black=n*n-white;
      ce*=power(k,white);ce%=mod;
      ce*=power(k-1,black);ce%=mod;
      if((i+j)%2){res+=(mod-ce);}
      else{res+=ce;}
      res%=mod;
    }
  }
  cout << res << '\n';
  return 0;
}