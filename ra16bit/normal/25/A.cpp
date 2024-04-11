#include <stdio.h>
int n,a[111],i,z,d[2];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<3; i++) d[a[i]%2]++;
  if (d[0]>1) z=1; else z=0;
  for (i=0; i<n; i++) if (a[i]%2==z) { printf("%d\n",i+1); break; }
  return 0;
}