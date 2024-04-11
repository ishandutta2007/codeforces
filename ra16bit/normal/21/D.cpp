#include <stdio.h>
#include <memory.h>
int n,m,x,y,z,s,i,g[17][17],v[17],f[265000];
int main() {
  scanf("%d%d",&n,&m);
  for (x=1; x<=n; x++) {
    for (y=1; y<=n; y++) g[x][y]=1000000000;
    g[x][x]=0;
  }
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x,&y,&z);
    if (z<g[x][y]) g[x][y]=g[y][x]=z;
    v[x]++; v[y]++; s+=z;
  }
  for (z=1; z<=n; z++) for (x=1; x<=n; x++) for (y=1; y<=n; y++) if (g[x][z]+g[z][y]<g[x][y]) g[x][y]=g[x][z]+g[z][y];
  if (v[1]==0 && s>0) { puts("-1"); return 0; }
  for (i=1; i<=n; i++) if (v[i]>0) for (x=i; i<=n; i++) if (v[i]>0 && g[x][i]==1000000000) { puts("-1"); return 0; }
  memset(f,120,sizeof(f));
  z=0; f[0]=0;
  for (i=1; i<=n; i++) if (v[i]&1) z+=(1<<(i-1));
  for (i=0; i<z; i++) if (f[i]<1000000000) for (x=1; x<=n; x++) if ((v[x]&1) && (i&(1<<(x-1)))==0)
   for (y=x+1; y<=n; y++) if ((v[y]&1) && (i&(1<<(y-1)))==0 && g[x][y]<1000000000)
    if (f[i]+g[x][y]<f[i+(1<<(x-1))+(1<<(y-1))]) f[i+(1<<(x-1))+(1<<(y-1))]=f[i]+g[x][y];
  if (f[z]>=1000000000) puts("-1"); else printf("%d\n",s+f[z]);
  return 0;
}