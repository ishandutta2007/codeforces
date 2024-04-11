#include <cstdio>
#include <algorithm>
using namespace std;
int i,j,d,k,e,f[369369];
long long l,r,zl,zr;
int gcd(int a, int b) { return b?gcd(b,a%b):a; }
long long solve(long long l, long long r) {
  for (i=1; i<=r-l; i++) {
    f[i]=f[i-1];
    for (j=2; j<=k; j++) {
      e=i-(i+l)%j;
      if (e>=0) f[i]=min(f[i],f[e]);
    }
    f[i]++;
  }
  return f[r-l];
}
int main() {
  scanf("%I64d%I64d%d",&r,&l,&k);
  for (d=2, i=3; i<=k; i++) d=(d*i)/gcd(d,i);
  zl=l;
  if (l%d) zl+=d-(l%d);
  zr=r-(r%d);
  printf("%I64d\n",(r-l<=d)?solve(l,r):(solve(l,zl)+solve(zr,r)+solve(0,d)*((zr-zl)/d)));
  return 0;
}