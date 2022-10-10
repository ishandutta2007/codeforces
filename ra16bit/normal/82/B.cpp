#include <stdio.h>
int n,m,i,j,k,a[202],b[202][202];
bool f[202],u[202];
int main() {
  scanf("%d",&n);
  for (i=0; i<(n*(n-1))/2; i++) {
    scanf("%d",&m);
    for (j=0; j<m; j++) {
      scanf("%d",&a[j]);
      if (n==2) {
        if (j==0) printf("1 %d\n",a[j]); else
         if (j==1) printf("%d %d",m-1,a[j]); else printf(" %d",a[j]);
      }
      f[a[j]]=true;
      for (k=0; k<j; k++) { b[a[k]][a[j]]++; b[a[j]][a[k]]++; }
    }
  }
  if (n==2) return 0;
  for (i=1; i<=200; i++) if (f[i] && !u[i]) {
    for (m=j=1; j<=200; j++) if (b[i][j]==n-1) m++;
    printf("%d %d",m,i); u[i]=true;
    for (j=1; j<=200; j++) if (b[i][j]==n-1) { printf(" %d",j); u[j]=true; }
    puts("");
  }
  return 0;
}