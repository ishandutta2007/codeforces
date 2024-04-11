#include <stdio.h>
int n,sa,m1,m2,i,a[200200],b[200200];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&a[i],&b[i]);
    sa+=a[i];
    if (b[i]>m1) {
      m2=m1; m1=b[i];
    } else if (b[i]>m2) m2=b[i];
  }
  for (i=0; i<n; i++) printf("%d%c",(sa-a[i])*(b[i]==m1?m2:m1),(i==n-1)?'\n':' ');
  return 0;
}