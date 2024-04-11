//Lagrange kth power sum
//Educational CF R7-F
//https://codeforces.com/contest/622/problem/F
//https://ja.wikipedia.org/wiki/%E3%83%A9%E3%82%B0%E3%83%A9%E3%83%B3%E3%82%B8%E3%83%A5%E8%A3%9C%E9%96%93

#include<stdio.h>
#define mod 1000000007
#define maxdeg 1048576

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

long long factorial[maxdeg];
long long invfact[maxdeg];

void cfact(){
  long long i;
  factorial[0]=1;
  factorial[1]=1;
  for(i=2;i<maxdeg;i++){
    factorial[i]=factorial[i-1]*i;
    factorial[i]%=mod;
  }
  invfact[maxdeg-1]=modular_inverse(factorial[maxdeg-1]);
  for(i=maxdeg-2;i>=0;i--){
    invfact[i]=invfact[i+1]*(i+1);
    invfact[i]%=mod;
  }
}

// k...polynominal degree (there must be k+1 data)
// f(i) = a[i] (0 <= i <= k)
// a[i] must be 0 <= a[i] < mod
// return : f(x)
// complexity = O(k log mod)
long long lagrange_liner(long long x,long long k,long long a[]){
  if(x<=k){return a[x];}
  long long i,bsnmr=1,nmr,dmn,res=0,rev=modular_inverse(mod-1),lv;
  for(i=0;i<=k;i++){bsnmr*=(mod+x-i);bsnmr%=mod;}
  for(i=0;i<=k;i++){
    nmr=(bsnmr*modular_inverse((mod+x-i)%mod))%mod;
    dmn=invfact[i]*invfact[k-i];dmn%=mod;
    if((k-i)&1ll){dmn*=rev;dmn%=mod;}
    lv=(nmr*dmn)%mod;
    res+=lv*a[i];
    res%=mod;
  }
  return res;
}

//0^k + 1^k + 2^k + ... + n^k
long long kth_power_sum(long long n,long long k){
  long long i,deg=k+1,a[maxdeg];
  a[0]=0;
  for(i=1;i<=deg;i++){a[i]=a[i-1]+power(i,k);a[i]%=mod;}
  return lagrange_liner(n,deg,a);
}

int main(){
  cfact();
  long long n,k;
  scanf("%lld%lld",&n,&k);
  printf("%lld\n",kth_power_sum(n,k));
  return 0;
}