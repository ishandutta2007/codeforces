#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,q,i,x,y,s,a[MX];
int main() {
  scanf("%d%d",&n,&q);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    s+=a[i];
  }
  while (q--) {
    scanf("%d%d",&x,&y);
    if (x==1) {
      s-=a[y];
      a[y]^=1;
      s+=a[y];
    } else printf("%d\n",int(s>=y));
  }
  return 0;
}