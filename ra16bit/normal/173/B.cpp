#include <stdio.h>
const int MX=1010,MG=MX*MX,MQ=4*MG;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int n,m,num,fi,fr,i,j,k,x,y,qx[2*MQ],qy[2*MQ],a[MX][MX],g[MG][4],p[MG][4];
char s[MX][MX];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (s[i][j]=='#') a[i][j]=++num;
  fi=MQ; fr=MQ;
  ++num;
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (a[i][j]>0) for (k=0; k<4; k++) {
    x=i+dx[k];
    y=j+dy[k];
    while (x>=0 && y>=0 && x<n && y<m && a[x][y]==0) {
      x+=dx[k];
      y+=dy[k];
    }
    if (x>=0 && y>=0 && x<n && y<m) g[a[i][j]][k]=a[x][y];
    if (k==1 && x==0 && y<0) g[a[i][j]][k]=num;
    if (k==3 && x==n-1 && y>=m) {
      qx[fr]=a[i][j];
      qy[fr++]=1;
      p[a[i][j]][1]=1;
    }
  }
  while (fi<fr) {
    x=qx[fi];
    y=qy[fi++];
    if (x==num) { printf("%d\n",p[x][y]-1); return 0; }
    for (k=0; k<4; k++) if (g[x][k]) {
      i=g[x][k];
      if (p[i][k]==0) {
        if (k==y) {
          qx[--fi]=i;
          qy[fi]=k;
          p[i][k]=p[x][y];
        } else {
          qx[fr]=i;
          qy[fr++]=k;
          p[i][k]=p[x][y]+1;
        }
      }
    }
  }
  puts("-1");
  return 0;
}