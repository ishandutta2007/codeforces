#include <stdio.h>
int n,m,i,j,a,b,c[105][105];
int main() {
  scanf("%d%d%d",&n,&a,&b);
  m=n-1;
  for (i=0; i<a; i++) for (j=0; j<b; j++) if ((i+j)&1) {
    if (m>0) { c[i][j]=m; m-=2; }
  } else {
    if (n>0) { c[i][j]=n; n-=2; }
  }
  if (m<=0 && n<=0) for (i=0; i<a; i++) for (j=0; j<b; j++)
    printf("%d%c",c[i][j],(j==b-1)?'\n':' '); else puts("-1");
  return 0;
}