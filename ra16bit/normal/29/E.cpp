#include <cstdio>
#include <vector>
using namespace std;
int n,m,i,j,k,x,y,z,fi,fr,p[555][555][2],v[555][555][2],qx[660000],qy[660000],qz[660000];
vector <int> g[555],r[2];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  p[1][n][0]=1;  qy[0]=n;
  qx[0]=fr=1; qz[0]=fi=0;
  while (fi<fr) {
    x=qx[fi]; y=qy[fi]; z=qz[fi++];
    if (z==0) for (j=0; j<g[x].size(); j++) {
      k=g[x][j];
      if (p[k][y][1]==0) {
        p[k][y][1]=p[x][y][z]+1; v[k][y][1]=x;
        qx[fr]=k; qy[fr]=y; qz[fr++]=1;
      }
    } else for (j=0; j<g[y].size(); j++) {
      k=g[y][j];
      if (p[x][k][0]==0 && x!=k) {
        p[x][k][0]=p[x][y][z]+1; v[x][k][0]=y;
        qx[fr]=x; qy[fr]=k; qz[fr++]=0;
      }
    }
  }
  if (p[n][1][0]) {
    printf("%d\n",(p[n][1][0]-1)/2);
    for (x=n, y=1, z=0; p[x][y][z]>0; z=1-z) if (z==0) {
      r[1].push_back(y); y=v[x][y][z];
    } else {
      r[0].push_back(x); x=v[x][y][z];
    }
    r[0].push_back(1);
    for (j=0; j<2; j++) for (i=r[j].size()-1; i>=0; i--) {
      printf("%d",r[j][i]);
      if (i) putchar(' '); else putchar('\n');
    }
  } else puts("-1");
  return 0;
}