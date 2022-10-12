#include<bits/stdc++.h>

using namespace std;

long long mod;
long long res=0;

vector<long long> fractal(long long n,long long ce){
  if(n==1){
    vector<long long> a={1};
    return a;
  }
  vector<long long> cur=fractal(n-1,(ce*n)%mod);
  long long nsz=cur.size()+(n-1);
  vector<long long> nv(nsz,0);
  for(long long i=n-1;i>=0;i--){
    long long del=0;
    for(long long j=0;j<i;j++){del+=nv[j];del%=mod;}
    for(long long j=0;j<cur.size();j++){
      long long fdel=((del*cur[j])%mod)*ce;
      res+=fdel;res%=mod;
      del+=nv[i+j];del%=mod;
      nv[i+j]+=cur[j];nv[i+j]%=mod;
    }
  }
  return nv;
}

int main(){
  long long n;
  cin >> n >> mod;
  fractal(n,1);
  cout << res << '\n';
  return 0;
}