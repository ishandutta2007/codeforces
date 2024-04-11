#include <stdio.h>
int n,i,j,k,a[55][55],p[55];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) for (j=0; j<n; j++) scanf("%d",&a[i][j]);
  for (k=1; k<=n; k++) {
    for (i=0; i<n; i++) if (p[i]==0) {
      for (j=0; j<n; j++) if (i!=j && p[j]==0 && a[i][j]!=k) break;
      if (j>=n) {
        p[i]=k;
        break;
      }
    }
  }
  for (i=0; i<n; i++) printf("%d%c",p[i],(i==n-1)?'\n':' ');
  return 0;
}