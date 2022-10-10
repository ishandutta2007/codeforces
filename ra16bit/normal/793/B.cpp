#include <bits/stdc++.h>
using namespace std;
const int MX=1010*1010*4;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int n,m,i,j,x,y,nx,ny,tx,ty,z,e,fi,fr,qx[MX*2],qy[MX*2],qz[MX*2],d[1010][1010][4];
bool u[1010][1010][4];
char s[1010][1010];
int main() {
  fi=fr=MX;
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) for (j=0; j<m; j++) for (e=0; e<4; e++) d[i][j][e]=1000000000;
  for (i=0; i<n; i++) {
    scanf("%s",s[i]);
    for (j=0; j<m; j++) {
     if (s[i][j]=='S') for (e=0; e<4; e++) {
      qx[fr]=i; qy[fr]=j; qz[fr++]=e;
      d[i][j][e]=0;
     }
     if (s[i][j]=='T') { tx=i; ty=j; }
    }
  }
  while (fi<fr) {
    x=qx[fi];
    y=qy[fi];
    z=qz[fi++];
    if (d[x][y][z]>2) break;
    if (u[x][y][z]) continue;
    u[x][y][z]=true;
    for (e=0; e<4; e++) if (d[x][y][e]>d[x][y][z]+1) {
      d[x][y][e]=d[x][y][z]+1;
      qx[fr]=x;
      qy[fr]=y;
      qz[fr++]=e;
    }
    nx=x+dx[z];
    ny=y+dy[z];
    if (nx<0 || nx>=n || ny<0 || ny>=m || s[nx][ny]=='*') continue;
    if (d[nx][ny][z]>d[x][y][z]) {
      d[nx][ny][z]=d[x][y][z];
      qx[--fi]=nx;
      qy[fi]=ny;
      qz[fi]=z;
    }
  }
  for (e=0; e<4; e++) if (d[tx][ty][e]<=2) { puts("YES"); return 0; }
  puts("NO");
  return 0;
}