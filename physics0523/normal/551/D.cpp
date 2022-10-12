#include<bits/stdc++.h>

using namespace std;

// int main(){
//   for(int n=2;;n++){
//     long long ok=0;
//     for(long long i=0;i<(1ll<<n);i++){
//       for(int j=0;j<(n-1);j++){
//         if((i&(3ll<<j))==(3ll<<j)){ok++;break;}
//       }
//     }
//     cout << n << " : ";
//     cout << (1ll<<n)-ok << ' ' << ok << '\n';
//   }
//   return 0;
// }

//(1,1,2,3,5,8...) (1-indexed)
long long fib(long long n,long long mod){
  long long f1=1,f=1;
  long long r1=1,r=0;
  while(n>0){
    if(n&1ll){
      long long nr1,nr;
      nr1=f1*r1+f*r;nr=f1*r+f*(mod+r1-r);
      r1=nr1%mod;r=nr%mod;
    }
    long long nf1,nf;
    nf1=f1*f1+f*f;nf=f*(mod+2*f1-f);
    f1=nf1%mod;f=nf%mod;
    n>>=1;
  }
  return r;
}

long long power(long long a,long long b,long long mod){
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k,l,mod;
  cin >> n >> k >> l >> mod;
  long long mbit=-100;
  for(int i=62;i>=0;i--){
    if(k&(1ll<<i)){mbit=i;break;}
  }
  if(mbit>=l){
    cout << "0\n";
    return 0;
  }
  long long res=1;
  long long f=fib(n+2,mod);
  long long p=power(2,n,mod);
  //cout << f << ' ' << p << '\n';
  for(int i=0;i<l;i++){
    if(k&(1ll<<i)){
      long long ce=(mod+p-f);
      res*=ce;res%=mod;
    }
    else{
      res*=f;
      res%=mod;
    }
  }
  cout << res%mod << '\n';
  return 0;
}