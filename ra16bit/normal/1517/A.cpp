#include <bits/stdc++.h>
using namespace std;
int t;
long long n,tot;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%lld",&n);
    if (n%2050) { puts("-1"); continue; }
    n/=2050;
    tot=0;
    while (n>0) {
      tot+=n%10;
      n/=10;
    }
    printf("%lld\n",tot);
  }
  return 0;
}