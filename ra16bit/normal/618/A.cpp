#include <stdio.h>
int n,i,t,a[100100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    a[++t]=1;
    while (t>1 && a[t]==a[t-1]) a[--t]++;
  }
  for (i=1; i<=t; i++) printf("%d%c",a[i],i==t?'\n':' ');
  return 0;
}