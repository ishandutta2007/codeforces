#include <stdio.h>
int n,k,i,j,p,z,a[1010],b[1010];
bool q,u[2010];
int main() {
  scanf("%d%d",&n,&k);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
	b[a[i]]=i;
  }
  u[0]=true;
  for (i=1; i<=n; i++) if (a[i]==0) {
    q=false;
    for (p=i, j=1; p!=0; j++, p=b[p]) if (p==k) { q=true; z=j; }
	if (!q) for (int i=n; i>=0; i--) if (u[i]) u[i+j-1]=true;
  }
  for (i=0; i<=n; i++) if (u[i]) printf("%d\n",i+z);
  return 0;
}