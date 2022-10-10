#include <stdio.h>
int n,i,j,k,c,d,a[100100],b[100100],x[100100],r[100100];
int main() {
  scanf("%d",&n);
  for (i=3; i<=n; i++) {
    for (j=2; ; j++) {
      k=(j*(j-1))/2;
      if (k>i) break;
      if ((i-k)%j!=0) continue;
      c=(i-k)/j;
      if (c<=0) break;
      d=x[c+j-1]^x[c-1];
      b[d]=i;
      if (d==0 && r[i]==0) r[i]=j;
    }
    for (a[i]=0; b[a[i]]==i; a[i]++);
    x[i]=x[i-1]^a[i];
  }
  if (a[n]==0) puts("-1"); else printf("%d\n",r[n]);
  return 0;
}