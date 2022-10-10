#include <stdio.h>
int n,i,j,k,r,d,a[55];
bool f[52][600000];
int main() {
  scanf("%d%d",&n,&d);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  f[0][0]=true;
  for (i=0; i<n; i++) for (j=0; j<=10000*i; j++) if (f[i][j]) f[i+1][j]=f[i+1][j+a[i]]=true;
  for (k=j=r=0, i=d; ; i=k+d, r++) {
    for (; j<=i; j++) if (f[n][j]) k=j;
	if (k+d==i) break;
  }
  printf("%d %d\n",i-d,r);
  return 0;
}