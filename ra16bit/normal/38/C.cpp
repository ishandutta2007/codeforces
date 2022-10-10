#include <stdio.h>
int n,l,a[111],c,r,i,j;
int main() {
  scanf("%d%d",&n,&l);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=l; i<=111; i++) {
    for (c=j=0; j<n; j++) c+=a[j]/i;
    if (i*c>r) r=i*c;
  }
  printf("%d\n",r);
  return 0;
}