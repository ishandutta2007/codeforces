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
  vector<long long> a(n);
  for(auto &nx : a){cin >> nx;}
  vector<long long> b;
  for(int i=1;i<n;i++){b.push_back(a[i]);}
  b.push_back(a[0]);

  if(k==1){cout << "0\n";return 0;}

  long long eq=0;
  for(int i=0;i<n;i++){
    if(a[i]==b[i]){eq++;}
  }
  long long res=power(k,n);
  long long df=n-eq;
  for(long long i=0;2*i<=df;i++){
    long long rem=df-2*i;
    long long ce=calcnCr(df,i);
    ce*=calcnCr(df-i,i);ce%=mod;
    ce*=power(k-2,rem);ce%=mod;
    ce*=power(k,eq);ce%=mod;
    res+=(mod-ce);res%=mod;
  }
  cout << (res*modular_inverse(2))%mod << '\n';
  return 0;
}