#include <bits/stdc++.h>
using namespace std;
int n,m,num,i,j,r,x[100100],y[100100],v[100100],b[100100],p[555],rk[555],a[555][555];
bool u[100100];
int fs(int i) {
    if (p[i]!=i) p[i]=fs(p[i]);
	return p[i];
}
void un(int x, int y) {
	if (x==y) return; else r++;
	if (rk[y]>rk[x]) p[x]=y; else {
	  p[y]=x;
	  if (rk[y]==rk[x]) rk[x]++;
	}
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
	  scanf("%d%d",&x[i],&y[i]);
	  v[x[i]]++;
	  v[y[i]]++;
  }
  for (i=j=1; i<=n; i++) if (v[i]<v[j]) j=i;
  for (i=0; i<m; i++) {
	  if (x[i]==j) u[y[i]]=true;
	  if (y[i]==j) u[x[i]]=true;
  }
  for (i=1; i<=n; i++) if (u[i]) b[i]=++num; else b[i]=0;
  for (i=0; i<m; i++) {
	  a[b[x[i]]][b[y[i]]]++;
	  a[b[y[i]]][b[x[i]]]++;
  }
  for (i=0; i<=num; i++) p[i]=i;
  for (i=1; i<=num; i++) if (a[0][i]!=n-num) un(fs(0),fs(i));
  for (i=1; i<=num; i++) for (j=i+1; j<=num; j++) if (a[i][j]==0) un(fs(i),fs(j));
  printf("%d\n",num-r);
  return 0;
}