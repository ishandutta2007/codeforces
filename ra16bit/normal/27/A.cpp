#include <stdio.h>
int a,n,i;
bool u[3010];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&a); u[a]=true; }
  for (i=1; i<=n+1; i++) if (!u[i]) { printf("%d\n",i); return 0; }
}