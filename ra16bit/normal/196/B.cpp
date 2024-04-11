#include <stdio.h>
#include <memory.h>
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int i,j,k,n,m,si,sj,rx[1515][1515],ry[1515][1515];
char s[1515][1515];
bool f[1515][1515],w[1515][1515],u[1515][1515];
bool dfs(int i, int j, int Rx, int Ry) {
  //printf("dfs %d %d %d %d %c\n",i,j,Rx,Ry,s[i][j]);
  if (w[i][j]) {
    //if ((rx[i][j]!=Rx || ry[i][j]!=Ry)) printf("%d %d %d %d\n",(rx[i][j]),Rx,ry[i][j],(Ry));
    return f[i][j]|=(rx[i][j]!=Rx || ry[i][j]!=Ry);
  }
  if (u[i][j]) return f[i][j];
  f[i][j]=false;
  w[i][j]=true;
  u[i][j]=true;
  rx[i][j]=Rx;
  ry[i][j]=Ry;
  int d;
  for (d=0; d<4; d++) {
    int x=i+dx[d];
    int y=j+dy[d];
    int nx=Rx+dx[d];
    int ny=Ry+dy[d];
    if (x==-1) x=n-1; if (x==n) x=0;
    if (y==-1) y=m-1; if (y==m) y=0;
    if (s[x][y]!='#' && dfs(x,y,nx,ny)) break;
  }
  w[i][j]=false;
  if (d<4) return f[i][j]=true;
  return false;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%s",s[i]);
    for (j=0; j<m; j++) if (s[i][j]=='S') {
      si=i; sj=j;
    }
  }
  if (dfs(si,sj,si,sj)) puts("Yes"); else puts("No");
  return 0;
}