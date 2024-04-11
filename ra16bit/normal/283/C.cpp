#include <stdio.h>
const int md=1000000007;
int n,t,m,i,j,ii,i1,x,y,a[303],b[303],f[2][100010];
bool u[303],w[303],e[303],q;
void dfs(int i) {
  u[i]=true;
  w[i]=true;
  if (w[b[i]]) q=true;
  if (!u[b[i]]) dfs(b[i]);
  a[i]+=a[b[i]];
  w[i]=false;
}
int main() {
  scanf("%d%d%d",&n,&t,&m);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  while (t--) {
    scanf("%d%d",&x,&y);
	b[y]=x;
	e[x]=true;
  }
  u[0]=true;
  for (i=1; i<=n; i++) if (!u[i]) {
    dfs(i);
	if (q) { puts("0"); return 0; }
  }
  f[0][0]=1;
  for (i=1; i<=n; i++) {
    i1=i&1; ii=1-i1;
	if (e[i]) {
	  for (j=0; j<a[i] && j<=m; j++) f[i1][j]=0;
	  for (; j<=m; j++) f[i1][j]=f[ii][j-a[i]];
	} else for (j=0; j<=m; j++) f[i1][j]=f[ii][j];
	for (j=0; j+a[i]<=m; j++) f[i1][j+a[i]]=(f[i1][j+a[i]]+f[i1][j])%md;
  }
  printf("%d\n",f[n&1][m]);
  return 0;
}