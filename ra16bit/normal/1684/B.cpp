#include <bits/stdc++.h>
using namespace std;
const int MX=1100100;
int t,n;
long long a,b,c,x;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%lld%lld%lld",&a,&b,&c);
    x=(c/b+1)*b+a;
    printf("%lld %lld %lld\n",x,b,c);
  }
  return 0;
}