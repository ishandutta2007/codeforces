#include <stdio.h>
int n,m,q,i,j,l,r,x,y,ans,a[10010],e[10010],p[10010][505],rk[10010][505],b[10010][505],bk[10010][505],c[1010],ck[1010];
int fsp(int j, int i) {
  if (i!=p[j][i]) p[j][i]=fsp(j,p[j][i]);
  return p[j][i];
}
int fsb(int j, int i) {
  if (i!=b[j][i]) b[j][i]=fsb(j,b[j][i]);
  return b[j][i];
}
int fsc(int i) {
  if (i!=c[i]) c[i]=fsc(c[i]);
  return c[i];
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) scanf("%d%d",&a[i],&e[i]);
  for (i=1; i<=n; i++) {
    p[0][i]=i; rk[0][i]=0;
	b[m][i]=i; bk[m][i]=0;
  }
  for (j=1; j<=m; j++) {
    for (i=1; i<=n; i++) { p[j][i]=p[j-1][i]; rk[j][i]=rk[j-1][i]; }
	x=fsp(j,a[j-1]);
	y=fsp(j,e[j-1]);
	if (x==y) continue;
    if (rk[j][x]<rk[j][y]) p[j][x]=y; else {
      p[j][y]=x;
	  if (rk[j][x]==rk[j][y]) rk[j][x]++;
    }
  }
  for (j=m-1; j>=0; j--) {
    for (i=1; i<=n; i++) { b[j][i]=b[j+1][i]; bk[j][i]=bk[j+1][i]; }
	x=fsb(j,a[j]);
	y=fsb(j,e[j]);
	if (x==y) continue;
    if (bk[j][x]<bk[j][y]) b[j][x]=y; else {
      b[j][y]=x;
	  if (bk[j][x]==bk[j][y]) bk[j][x]++;
    }
  }
  scanf("%d",&q);
  while (q--) {
    scanf("%d%d",&l,&r);
	for (i=1; i<=n; i++) {
	  c[i]=fsp(l-1,i);
	  ck[i]=rk[l-1][i];
	  c[n+i]=fsb(r,i)+n;
	  ck[n+i]=bk[r][i];
	}
	for (i=1; i<=n; i++) {
	  x=fsc(i);
	  y=fsc(n+i);
	  if (ck[x]<ck[y]) c[x]=y; else {
        c[y]=x;
	    if (ck[x]==ck[y]) ck[x]++;
      }
	}
	ans=0;
    for (i=1; i<=2*n; i++) if (fsc(i)==i) ans++;
	printf("%d\n",ans);
  }
  return 0;
}