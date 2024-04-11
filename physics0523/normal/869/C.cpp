#include<stdio.h>
#define mod 998244353

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

long long calc(long long a,long long b){
  long long res=0;
  for(long long i=0;(i<=a && i<=b);i++){
    long long del;
    del=(calcnCr(a,i)*calcnCr(b,i))%mod;
    del*=factorial[i];del%=mod;
    res+=del;res%=mod;
  }
  return res;
}

int main(){
  cfact();
  long long a,b,c;
  scanf("%lld%lld%lld",&a,&b,&c);
  printf("%lld\n",(((calc(a,b)*calc(a,c))%mod)*calc(b,c))%mod);
}