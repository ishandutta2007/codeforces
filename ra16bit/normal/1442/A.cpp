#include <bits/stdc++.h>
using namespace std;
int t,n,i,le,ri,a[100100];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    le=a[0]; ri=0;
    for (i=1; i<n; i++) {
      a[i]-=ri;
      if (a[i]<0) break;
      le=min(le,a[i]);
      a[i]-=le;
      if (a[i]>0) ri+=a[i];
    }
    puts((i<n)?"NO":"YES");
  }
  return 0;
}