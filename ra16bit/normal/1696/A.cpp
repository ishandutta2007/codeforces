#include <bits/stdc++.h>
using namespace std;
const int MX=2020;
int t,n,r,z,i,a[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&z);
    r=0;
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      r=max(r,a[i]);
      r=max(r,(a[i]|z));
    }
    printf("%d\n",r);
  }
  return 0;
}