#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MID=1010*1010;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int n,m,i,j,k,d,x,y,r,inf,fi,fr,qx[2*MID],qy[2*MID],pa[3][3],p[3][1010][1010];
char s[1010][1010];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  memset(pa,100,sizeof(pa));
  r=inf=pa[0][0];
  for (k=0; k<3; k++) {
    fi=fr=MID;
    for (i=0; i<n; i++) for (j=0; j<m; j++) if (s[i][j]=='1'+k) {
      p[k][i][j]=1;
      qx[fr]=i;
      qy[fr++]=j;
    }
    while (fi<fr) {
      i=qx[fi];
      j=qy[fi++];
      if (s[i][j]!='.') pa[k][s[i][j]-'1']=min(pa[k][s[i][j]-'1'],p[k][i][j]-1);
      for (d=0; d<4; d++) {
        x=i+dx[d];
        y=j+dy[d];
        if (x<0 || y<0 || x>=n || y>=m || s[x][y]=='#' || p[k][x][y]>0) continue;
        p[k][x][y]=p[k][i][j];
        if (s[x][y]=='.') {
          p[k][x][y]++;
          qx[fr]=x;
          qy[fr++]=y;
        } else {
          qx[--fi]=x;
          qy[fi]=y;
        }
      }
    }
  }
  for (k=0; k<3; k++) {
    for (x=i=0; i<3; i++) if (pa[k][i]<inf) x+=pa[k][i]; else break;
    if (i>=3) r=min(r,x);
  }
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (s[i][j]=='.') {
    for (x=k=0; k<3; k++) if (p[k][i][j]>0) x+=p[k][i][j]-1; else break;
    if (k>=3) r=min(r,x-2);
  }
  printf("%d\n",r==inf?-1:r);
  return 0;
}