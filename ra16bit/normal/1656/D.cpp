#include <bits/stdc++.h>
using namespace std;
const int MX=1100100;
int t;
long long cur,i,z,n;
set<long long> s;
int main() {
  for (i=0; i<=60; i++) s.insert(1LL<<i);
  scanf("%d",&t);
  while (t--) {
    scanf("%lld",&n);
    if (s.count(n)) { puts("-1"); continue; }
    long long mx=1;
    for (i=1; i<32; i++) {
      z=cur=(1LL<<i);
      cur=(cur*(cur-1))/2;
      if (n>cur && (n-cur)%z==0) break;
      if (n%z==0) mx=z;
    }
    if (i<32) printf("%lld\n",z); else {
      z=cur=n/mx;
      cur=(cur*(cur-1))/2;
      if (n>cur && (n-cur)%z==0) {
        printf("%lld\n",z);
      } else for (i=2; i*i<=z; i++) {
        cur=(i*(i-1))/2;
        if (n>cur && (n-cur)%i==0) {
          printf("%lld\n",i);
          break;
        }
      }
    }
  }
  return 0;
}