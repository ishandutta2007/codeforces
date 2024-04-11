#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

map<pl,long long> mem;

long long find(long long n,long long k){
  if(mem.find({n,k})!=mem.end()){return mem[{n,k}];}
  long long res=0;
  for(long long i=max(0ll,k);i<=n;i++){
    if((n|i)==n){res++;}
  }
  mem[{n,k}]=res%2;
  return (res%2);
}

long long mdg=(1<<20);
long long pp(long long a,long long b){
  if(b>=20){return (1ll<<20);}
  b=(1ll<<b);
  double est=a;est*=b;
  if(est>=1e9){return (1ll<<20);}
  return min((1ll<<20),a*b);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  vector<long long> a(n);
  for(auto &nx : a){cin >> nx;}
  vector<long long> res(mdg,0);
  if(k==0){
    long long val=a[0];
    for(int i=1;i<n;i++){
      val=pp(val,a[i]);
      if(val>=(1ll<<20)){break;}
    }
    if(val<(1ll<<20)){res[val]^=1;}
  }
  for(long long sl=0;sl<22;sl++){
    for(int i=0;i<n-sl;i++){
      long long ce;
      if(i==0 || i==n-sl-1){ce=find((n-1)-sl-1,k-1);}
      else{ce=find((n-1)-sl-2,k-2);}
      if(ce==0){continue;}
      // cout << i << ':' << sl << '\n';
      long long val=a[i];
      for(int j=i+1;j<=i+sl;j++){
        val=pp(val,a[j]);
        if(val>=(1ll<<20)){break;}
      }
      if(val<(1ll<<20)){res[val]^=1;}
    }
  }

  bool out=false;
  for(int i=mdg-1;i>=0;i--){
    if(res[i]%2){out=true;}
    if(out){cout << res[i]%2;}
  }
  if(!out){cout << "0";}
  cout << '\n';

  return 0;
}