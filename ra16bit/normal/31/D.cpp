#include <cstdio>
#include <algorithm>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int n,m,k,xa,xb,ya,yb,ii,i,j,x,y,xx,yy,fi,fr,e,b[111][111],c[111],qx[111111],qy[111111];
bool a[111][111][4];
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (ii=0; ii<k; ii++) {
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    if (xa==xb) for (i=ya; i<yb; i++) {
      a[xa][i][0]=true; a[xa-1][i][2]=true;
    } else for (i=xa; i<xb; i++) {
      a[i][ya][1]=true; a[i][ya-1][3]=true;
    }
  }
  for (ii=i=0; i<n; i++) for (j=0; j<m; j++) if (b[i][j]==0) {
    ii++; b[i][j]=ii; fi=0; fr=1; qx[fi]=i; qy[fi]=j;
    while (fi<fr) {
      x=qx[fi]; y=qy[fi++];
      for (k=0; k<4; k++) if (a[x][y][k]==false) {
        xx=x+dx[k]; yy=y+dy[k];
        if (xx>=0 && xx<n && yy>=0 && yy<m && b[xx][yy]==0) {
          b[xx][yy]=ii; qx[fr]=xx; qy[fr++]=yy;
        }
      }
    }
    c[e++]=fr;
  }
  sort(c,c+e);
  for (i=0; i<e; i++) {
    if (i) putchar(' ');
    printf("%d",c[i]);
  }
  return 0;
}