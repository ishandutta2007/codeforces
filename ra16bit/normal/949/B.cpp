#include <bits/stdc++.h>
long long n,x;
int q;
int main() {
  scanf("%lld%d",&n,&q);
  while (q--) {
    scanf("%lld",&x);
    while (x%2!=1) x+=n-x/2;
    printf("%lld\n",(x+1)/2);
  }
  return 0;
}