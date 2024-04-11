#include <bits/stdc++.h>
using namespace std;
int t,x,y,p,q;
long long z;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d%d",&x,&y,&p,&q);
    if (p==0) {
      puts(x?"-1":"0");
      continue;
    }
    if (p==q) {
      puts((x<y)?"-1":"0");
      continue;
    }
    z=max(max((x+p-1)/p,(y+q-1)/q),(y-x+q-p-1)/(q-p));
    printf("%lld\n",z*q-y);
  }
  return 0;
}