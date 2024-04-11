#include <stdio.h>
int i,n,x,last,a[200200],b[200200];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=1; i<=n; i++) { scanf("%d",&x); b[x]=i; }
  for (last=0, i=1; i<=n; i++) {
    if (b[a[i]]<last) break;
    last=b[a[i]];
  }
  printf("%d\n",n-i+1);
  return 0;
}