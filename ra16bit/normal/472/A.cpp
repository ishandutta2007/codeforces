#include <stdio.h>
int n,i,j;
bool a[1000100];
int main() {
  scanf("%d",&n);
  for (i=2; i<=n; i++) if (!a[i]) for (j=i+i; j<=n; j+=i) a[j]=true;
  for (i=2; i<=n-i; i++) if (a[i] && a[n-i]) { printf("%d %d\n",i,n-i); break; }
  return 0;
}