// 1 1 1 1 1 ... 1
// 0 0 .. 0 1 1 ... 1 2 2 ... 2 i i ... i (i+2) {i or (i+2)} ... {i or (i+2)}
#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> fp(n+5,0),sp(n+5,0);
    fp[0]=1;
    for(auto &nx : a){
      cin >> nx;
      nx++;
      fp[nx]*=2;fp[nx]%=mod;
      sp[nx]*=2;sp[nx]%=mod;
      sp[nx+2]*=2;sp[nx+2]%=mod;
      fp[nx]+=fp[nx-1];fp[nx]%=mod;
      if(nx>=2){sp[nx]+=fp[nx-2];sp[nx]%=mod;}
    }
    long long res=0;
    for(auto &nx : fp){res+=nx;res%=mod;}
    for(auto &nx : sp){res+=nx;res%=mod;}
    res+=(mod-1);res%=mod;
    cout << res << '\n';
  }
  return 0;
}