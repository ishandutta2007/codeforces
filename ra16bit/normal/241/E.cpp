#include <stdio.h>
#include <memory.h>
int n,m,i,j,e,last,a[5050],b[5050],f[1010],u[1010];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) scanf("%d%d",&a[i],&b[i]);
  u[1]=1; u[n]=2;
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (u[a[j]]&1) u[b[j]]|=1;
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (u[b[j]]&2) u[a[j]]|=2;
  memset(f,120,sizeof(f));
  f[1]=0;
  for (i=0; i<2*n; i++) for (j=0; j<m; j++) if (u[a[j]]==3 && u[b[j]]==3) {
    if (f[a[j]]+2<f[b[j]]) { f[b[j]]=f[a[j]]+2; last=i; }
    if (f[b[j]]-1<f[a[j]]) { f[a[j]]=f[b[j]]-1; last=i; }
  }
  if (last<=n) {
    puts("Yes");
    for (i=0; i<m; i++) if (u[a[i]]==3 && u[b[i]]==3) printf("%d\n",f[b[i]]-f[a[i]]); else puts("1");
  } else puts("No");
  return 0;
}