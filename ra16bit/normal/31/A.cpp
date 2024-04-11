#include <stdio.h>
int a[111],n,i,j,k;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) for (j=0; j<n; j++) for (k=j+1; k<n; k++) if (a[i]==a[j]+a[k]) {
    printf("%d %d %d\n",i+1,j+1,k+1); return 0;
  }
  puts("-1"); return 0;
}