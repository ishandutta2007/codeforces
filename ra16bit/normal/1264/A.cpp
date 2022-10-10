#include <bits/stdc++.h>
using namespace std;
int t,n,i,z,g,s,a[400400];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      if (a[i]==a[0]) g=i+1;
    }
    for (i=g*2+1; i<n; i++) if (a[i]!=a[i-1]) break;
    if (i>n) { puts("0 0 0"); continue; }
    s=i-g;
    for (i+=g+1; i<n; i++) if (a[i]!=a[i-1]) break;
    if (i>n || i*2>n) puts("0 0 0"); else {
      for (z=i; i<n; i++) if (a[i]!=a[i-1] && i*2<=n) z=i;
      printf("%d %d %d\n",g,s,z-g-s);
    }
  }
  return 0;
}