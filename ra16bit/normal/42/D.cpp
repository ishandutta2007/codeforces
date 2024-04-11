#include <stdio.h>
int e,i,j,k,n,a[22][22];
bool u[2222],q;
int main() {
  scanf("%d",&n);
  a[1][2]=1; a[1][3]=2; a[2][3]=3;
  u[1]=u[2]=u[3]=true;
  for (k=4; k<=n; k++) {
    for (e=1; e<=1000; e++) if (!u[e]) {
      q=true;
      for (j=2; j<k; j++) if (u[e+a[1][j]]) { q=false; break; }
      if (q) {
        a[1][k]=e; u[e]=true;
        for (j=2; j<k; j++) {
          a[j][k]=e+a[1][j];
          u[e+a[1][j]]=true;
        }
        break;
      }
    }
  }
  for (i=1; i<=n; i++) {
    for (j=1; j<=n; j++) {
      printf("%d",a[i][j]+a[j][i]);
      if (j<n) putchar(' ');
    }
    puts("");
  }
  return 0;
}