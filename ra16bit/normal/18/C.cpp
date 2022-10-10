#include <stdio.h>
int n,a[100100],s,l,i,r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&a[i]); s+=a[i]; }
  for (i=0; i<n-1; i++) {
    l+=a[i];
    if (s-l==l) r++;
  }
  printf("%d\n",r);
  return 0;
}