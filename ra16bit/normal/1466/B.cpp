#include <bits/stdc++.h>
using namespace std;
int t,n,i,mx,r,x[100100];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (r=mx=i=0; i<n; i++) {
      scanf("%d",&x[i]);
      if (i>0) {
        if (x[i]<mx) continue;
        if (x[i]==mx) ++x[i];
        ++r;
      } else ++r;
      mx=max(mx,x[i]);
    }
    printf("%d\n",r);
  }
  return 0;
}