#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,ii,i1,i,j,k,e,nk,ne,a,r,f[2][202][3][4],u[2][202][3][4];
void upd(int j, int k, int e, int v) {
  if (e!=0) {
    if (k==1) v+=a; else if (k==2) v-=a;
    if (e==1) v-=a; else if (e==2) v+=a;
  }
  if (j==m && e==3) r=max(r,v);
  if (u[ii][j][k][e]!=i+1) {
    u[ii][j][k][e]=i+1;
    f[ii][j][k][e]=v;
    return;
  }
  f[ii][j][k][e]=max(f[ii][j][k][e],v);
}
int main() {
  scanf("%d%d",&n,&m);
  u[0][0][0][0]=1;
  for (i=1; i<=n; i++) {
    ii=i&1; i1=1-ii;
    scanf("%d",&a);
    for (j=0; j<=i-1 && j<=m; j++) for (k=0; k<3; k++) for (e=0; e<4; e++) if (u[i1][j][k][e]==i) {
      if (e) {
        upd(j,k,e,f[i1][j][k][e]);
        upd(j,e,0,f[i1][j][k][e]);
        if (e!=3) for (ne=1; ne<4; ne++) upd(j+1,e,ne,f[i1][j][k][e]);
      } else {
        upd(j,k,0,f[i1][j][k][e]);
        for (ne=1; ne<4; ne++) upd(j+1,k,ne,f[i1][j][k][e]);
      }
    }
  }
  printf("%d\n",r);
  return 0;
}