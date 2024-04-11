#include <stdio.h>
int i,j,n,a[1111],r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) {
    for (j=i; j<n-1 && a[j+1]>=a[j]; j++);
    for (; j<n-1 && a[j+1]<=a[j]; j++);
    if (j-i+1>r) r=j-i+1;
  }
  printf("%d\n",r);
  return 0;
}