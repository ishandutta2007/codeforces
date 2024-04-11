#include <stdio.h>
int n,m,i,x,y,z,cur,fi,fr,qx[325325],qy[325325],qz[325325],g[402][402],p[402][402][2];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x][y]=g[y][x]=1;
  }
  qx[0]=qy[0]=fr=1;
  p[1][1][0]=1;
  while (fi<fr) {
    x=qx[fi];
    y=qy[fi];
    z=qz[fi++];
    cur=p[x][y][z]+1;
    if (z) {
      for (i=1; i<=n; i++) if ((y==n && i==n) || ((i!=x || x==n) && g[y][i] && p[x][i][0]==0)) {
        p[x][i][0]=cur;
        qx[fr]=x;
        qy[fr]=i;
        qz[fr++]=0;
      }
    } else for (i=1; i<=n; i++) if ((x==n && i==n) || (i!=x && g[x][i]==0 && p[i][y][1]==0)) {
      p[i][y][1]=cur;
      qx[fr]=i;
      qy[fr]=y;
      qz[fr++]=1;
    }
    if (p[n][n][0]>0) {
      printf("%d\n",(p[n][n][0]-1)/2);
      return 0;
    }
  }
  puts("-1");
  return 0;
}