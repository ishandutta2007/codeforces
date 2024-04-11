#include <bits/stdc++.h>
using namespace std;
int t,a,b,c,i;
long long d,e,x,y;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d",&a,&b,&c);
    for (d=i=1; i<c; i++) d*=10;
    for (e=d, i=c; i<a; i++) e*=10;
    for (x=d; x<e; x*=2);
    for (e=d, i=c; i<b; i++) e*=10;
    for (y=d; y<e; y*=3);
    printf("%lld %lld\n",x,y);
  }
  return 0;
}