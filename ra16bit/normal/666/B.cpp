#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,e,k,x,y,z,ra,rb,re,rk,rc,fi,fr,q[3003],lst[3003],a[3003][3],ac[3003][3],b[3003][3],bc[3003][3],f[3003][3003];
vector<int> g[3003];
int main() {
  scanf("%d%d",&n,&m);
  while (m--) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
  }
  for (i=1; i<=n; i++) {
    fi=0; fr=1; q[0]=i; f[i][i]=1;
    while (fi<fr) {
      x=q[fi++];
      z=f[i][x]+1;
      for (j=0; j<g[x].size(); j++) {
        y=g[x][j];
        if (f[i][y]==0) { f[i][y]=z; q[fr++]=y; }
      }
    }
    for (j=0; j<3 && fr-j-1>=0; j++) { a[i][j]=x=q[fr-j-1]; ac[i][j]=f[i][x]-1; }
  }
  for (i=1; i<=n; i++) for (x=0; x<3; x++) {
    b[i][x]=bc[i][x]=0;
    for (j=1; j<=n; j++) if (f[j][i]>bc[i][x] && lst[j]!=i) { bc[i][x]=f[j][i]; b[i][x]=j; }
    lst[b[i][x]]=i;
    bc[i][x]--;
  }
  for (i=1; i<=n; i++) for (x=0; x<3; x++) {
    e=b[i][x];
    if (e!=0 && e!=i) for (j=1; j<=n; j++) if (i!=j && e!=j && f[i][j]>0) for (y=0; y<3; y++) {
      k=a[j][y];
      if (k!=0 && k!=j && k!=i && k!=e) {
        z=bc[i][x]+ac[j][y]+f[i][j];
        if (z>rc) { re=e; ra=i; rb=j; rk=k; rc=z; }
      }
    }
  }
  printf("%d %d %d %d\n",re,ra,rb,rk);
  return 0;
}