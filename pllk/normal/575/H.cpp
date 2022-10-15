#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<utility>

using namespace std;

int64_t invert_mod(int64_t a, int64_t b) {
  int64_t u=1, v=0, m, n, q, r;
  int64_t x=0, y=1;
  int64_t d = b;
  while(a != 0) {
    q=d/a;r=d%a;
    m=x-u*q;n=y-v*q;
    d=a;a=r;
    x=u;y=v;
    u=m;v=n;
  }
  if(d != 1) return 0;
  if(x < 0) return x+b;
  return x;
}

int main(void) {
  const int64_t MOD=1000000007;
  int64_t N;
  cin >> N;
  int64_t res=1;
  for(int64_t i=2*N+2-N-1+1;i<=2*N+2;i++) {
    res*=i;
    res%=MOD;
  }
  for(int64_t i=1;i<=N+1;i++) {
    res*=invert_mod(i,MOD);
    res%=MOD;
  }
  if(res == 0) cout << MOD - 1 << endl;
  else cout << res - 1 << endl;
  return 0;
}