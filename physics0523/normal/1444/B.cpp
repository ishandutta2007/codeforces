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

long long fact(long long x){
  long long res=1;
  for(int i=1;i<=x;i++){res*=i;res%=mod;}
  return res%mod;
}

long long nCr(long long n,long long r){
  long long res=fact(n);
  long long k=fact(r);
  k*=fact(n-r);k%=mod;
  return (res*modular_inverse(k))%mod;
}

int main(){
  int n;
  cin >> n;
  vector<long long> a(2*n);
  for(int i=0;i<2*n;i++){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  long long res=0,k;
  k=nCr(2*n,n);
  for(int i=0;i<n;i++){
    res+=a[n+i];
    res-=a[i];
  }
  res%=mod;
  res*=k;res%=mod;
  cout << res << '\n';
  return 0;
}