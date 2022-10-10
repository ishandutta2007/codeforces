#include <stdio.h>
int n,k,l,m,i,j,x,e,fi,fr,a[111],b[10010],c[22],d[22][22],p[10010],q[10010],f[1100100],inf=100000000;
void add(int x, int y) {
  if (x<=0 || x>n+1 || y>=p[x]) return;
  p[x]=y; q[fr++]=x;
}
int main() {
  scanf("%d%d%d",&n,&k,&l);
  for (i=0; i<k; i++) { scanf("%d",&x); b[x]^=1; b[x+1]^=1; }
  for (i=0; i<l; i++) scanf("%d",&a[i]);
  for (i=1; i<=n+1; i++) if (b[i]==1) { b[i]=++m; c[m]=i; }
  if (m&1) { puts("-1"); return 0; }
  if (m==0) { puts("0"); return 0; }
  for (i=1; i<=m; i++) {
    for (j=0; j<=n+1; j++) p[j]=int(c[i]!=j)*inf;
    fi=0; fr=1; q[0]=c[i];
    while (fi<fr) {
      x=q[fi++];
      for (e=0; e<l; e++) {
        add(x+a[e],p[x]+1);
        add(x-a[e],p[x]+1);
      }
    }
    for (j=1; j<=m; j++) d[i-1][j-1]=p[c[j]];
  }
  for (i=0; i<(1<<m); i++) f[i]=int(i>0)*inf;
  for (i=0; i<(1<<m)-1; i++) {
    for (j=0; j<m; j++) if ((i&(1<<j))==0) break;
    for (e=j+1; e<m; e++) if ((i&(1<<e))==0 && f[i]+d[j][e]<f[i+(1<<j)+(1<<e)]) f[i+(1<<j)+(1<<e)]=f[i]+d[j][e];
  }
  if (f[(1<<m)-1]==inf) puts("-1"); else printf("%d\n",f[(1<<m)-1]);
  return 0;
}