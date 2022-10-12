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
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  long long a[524288],b[524288];
  while(t>0){
    t--;
    long long n,m,k;
    cin >> n >> m >> k;
    for(long long i=0;i<=n;i++){b[i]=0;}
    for(long long i=0;i<n;i++){
      cin >> a[i];
      b[a[i]]++;
    }
    for(long long i=2;i<=n;i++){b[i]+=b[i-1];}
    long long res=0;
    for(long long i=1;i<=n;i++){
      long long tg=min(n,i+k);
      res+=calcnCr(b[tg]-b[i-1],m);
      res+=mod;
      res-=calcnCr(b[tg]-b[i],m);
      res%=mod;
    }
    cout << res << '\n';
  }
}