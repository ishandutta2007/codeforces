#include <cstdio>
#include <algorithm>
using namespace std;
const int inf=1000000000;
int n,m,i,j,x,y,z,g1,g2,s1,s2,it,d[55],k[55],g[55][55],u[55][55][55];
long long f[55][55][55],r;
bool more(int i, int ii, int j, int jj) {
  return (g[i][ii]<g[j][jj] || (i<j && g[i][ii]==g[j][jj]));
}
bool cmp(int i, int j) {
  return more(i,n-1,j,n-1);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) g[i][j]=inf;
    g[i][i]=0;
  }
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x,&y,&z);
    x--; y--;
    g[x][y]=g[y][x]=z;
  }
  scanf("%d%d%d%d",&g1,&g2,&s1,&s2);
  for (z=0; z<n; z++) for (i=0; i<n; i++) for (j=0; j<n; j++) g[i][j]=min(g[i][j],g[i][z]+g[z][j]);
  for (i=0; i<n; i++) {
    sort(g[i],g[i]+n);
    reverse(g[i]+1,g[i]+n);
    d[i]=n-1;  k[i]=i;
  }
  sort(k,k+n,cmp);
  for (x=0; x<n; x++) {
    for (i=0; i<n; i++) while (d[i]>0 && more(i,d[i],k[x],n-1)) d[i]--;
    for (y=0; y<n; y++) if (x!=y && more(k[x],n-1,k[y],1)) {
      u[0][0][0]=++it; f[0][0][0]=1;
      for (i=0; i<=n; i++) for (j=0; j<=i; j++) for (z=0; j+z<=i; z++) if (u[i][j][z]==it) {
        if (i==k[x]) {
          if (u[i+1][j+1][z]!=it) { u[i+1][j+1][z]=it; f[i+1][j+1][z]=0; }
          f[i+1][j+1][z]+=f[i][j][z];
        } else if (i==k[y]) {
          if (u[i+1][j][z]!=it) { u[i+1][j][z]=it; f[i+1][j][z]=0; }
          f[i+1][j][z]+=f[i][j][z];
        } else {
          if (more(i,n-1,k[x],n-1)) {
             if (u[i+1][j+1][z]!=it) { u[i+1][j+1][z]=it; f[i+1][j+1][z]=0; }
             f[i+1][j+1][z]+=f[i][j][z];
          }
          if (d[i]>0 && more(i,d[i],k[y],1)) {
             if (u[i+1][j][z+1]!=it) { u[i+1][j][z+1]=it; f[i+1][j][z+1]=0; }
             f[i+1][j][z+1]+=f[i][j][z];
          }
          if (more(k[y],1,i,1)) {
             if (u[i+1][j][z]!=it) { u[i+1][j][z]=it; f[i+1][j][z]=0; }
             f[i+1][j][z]+=f[i][j][z];
          }
        }
      }
      for (i=g1; i<=g2; i++) for (j=s1; j<=s2; j++) if (u[n][i][j]==it) r+=f[n][i][j];
    }
  }
  printf("%I64d\n",r);
  return 0;
}