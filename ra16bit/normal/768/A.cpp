#include <stdio.h>
int n,i,j,k,r,a[100100];
int main() {
  scanf("%d",&n);
  for (i=j=k=0; i<n; i++) {
    scanf("%d",&a[i]);
    if (a[i]<a[j]) j=i;
    if (a[i]>a[k]) k=i;
  }
  for (i=0; i<n; i++) if (a[i]>a[j] && a[i]<a[k]) r++;
  printf("%d\n",r);
  return 0;
}