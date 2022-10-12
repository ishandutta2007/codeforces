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

  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;

    long long sig=0;
    vector<long long> a(n);
    for(auto &nx : a){
      cin >> nx;
      sig+=nx;
    }

    if(sig==0){
      // all 0
      long long res=power(2,n-1);
      cout << res << "\n";
      continue;
    }

    // at least one non-zero

    map<long long,long long> lef;
    long long cur;
    cur=0;
    for(int i=0;i<n;i++){
      cur+=a[i];
      if(cur*2ll > sig){break;}
      lef[cur]++;lef[cur]%=mod;
    }

    map<long long,long long> rig;
    cur=0;
    for(int i=n-1;i>=0;i--){
      cur+=a[i];
      if(cur*2ll > sig){break;}
      rig[cur]++;rig[cur]%=mod;
    }

    long long res=1;
    for(auto &nx : lef){
      if(nx.first*2ll == sig){
        long long prod=power(2,lef[nx.first]);
        prod%=mod;
        res*=prod;res%=mod;
      }
      else{
        long long prod=0;
        long long ln=lef[nx.first];
        long long rn=rig[nx.first];
        for(long long i=0;i<=min(ln,rn);i++){
          prod+=calcnCr(ln,i)*calcnCr(rn,i);
          prod%=mod;
        }
        res*=prod;res%=mod;
      }
      res%=mod;
    }
    cout << res%mod << "\n";
  }
  return 0;
}