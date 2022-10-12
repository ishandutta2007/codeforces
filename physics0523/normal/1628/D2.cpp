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

const int FAC_LIM=1048576;

long long factorial[FAC_LIM];
long long invfact[FAC_LIM];

void cfact(){
  long long i;
  factorial[0]=1;
  factorial[1]=1;
  for(i=2;i<FAC_LIM;i++){
    factorial[i]=factorial[i-1]*i;
    factorial[i]%=mod;
  }
  invfact[FAC_LIM-1]=modular_inverse(factorial[FAC_LIM-1]);
  for(i=FAC_LIM-2;i>=0;i--){
    invfact[i]=invfact[i+1]*(i+1);
    invfact[i]%=mod;
  }
}

long long calcnCr(long long n,long long k){
  if(k<0 || n<k){return 0;}
  return (factorial[n]*((invfact[k]*invfact[n-k])%mod))%mod;
}

//https://oeis.org/A210489
long long A210489(long long n,long long m){
  long long res=0;
  for(long long i=1;i<=m;i++){
    res+=i*calcnCr(n,m-i);res%=mod;
  }
  return res;
}

int main(){
  cfact();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  long long inv2=modular_inverse(2);
  while(t>0){
    t--;
    long long n,m,k;
    cin >> n >> m >> k;
    if(m==0){cout << "0\n";continue;}
    if(n==m){cout << (k*n)%mod << '\n';continue;}
    cout << (((A210489(n,m)*k)%mod)*power(inv2,n-1))%mod << '\n';
  }
  return 0;
}