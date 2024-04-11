#include <cstdio>
#include <algorithm>
using namespace std;
int d,i,j,l,r,n,a[5555],b[5555],c[5555];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&a[i],&b[i]);
    for (j=0; j<i; j++) {
      l=max(a[i],a[j]);
      r=min(b[i],b[j]);
      if (l<r) { c[i]++; c[j]++; }
    }
  }
  for (i=0; i<n; i++) if (c[i]) break;
  if (i==n) {
    printf("%d\n",n);
    for (i=1; i<=n; i++) {
      printf("%d",i);
      if (i==n) putchar('\n'); else putchar(' ');
    }
    return 0;
  }
  for (l=i+1; i<n; i++) if (c[i]) { r=i+1; d+=c[i]; }
  if (d==2) {
    printf("%d\n%d %d\n",2,l,r);
    return 0;
  }
  for (i=0; i<n; i++) if (c[i]>1) break;
  if (d%2==0 && i!=n && d/2==c[i]) {
    printf("%d\n%d\n",1,i+1);
    return 0;
  }
  puts("0");
  return 0;
}