#include <cstdio>
#include <algorithm>
using namespace std;
const int MN=52,MX=MN*MN;
const int dx[4]={1,0,0,-1};
const int dy[4]={0,-1,1,0};
int n,m,ii,jj,i,j,k,x,y,nx,ny,it,r,cnt,cur,fi,fr,qx[MX],qy[MX],u[MN][MN];
char s[MN][MN];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (s[i][j]=='#') cnt++;
  if (cnt<3) { puts("-1"); return 0; }
  for (ii=0; ii<n; ii++) for (jj=0; jj<m; jj++) if (s[ii][jj]=='#') {
    bool q=true;
    s[ii][jj]='.';
    for (i=0; i<n && q; i++) for (j=0; j<m && q; j++) if (s[i][j]=='#') {
      fi=0; fr=1; q=false;
      qx[0]=i; qy[0]=j; cur=0;
      u[i][j]=++it;
      while (fi<fr) {
        x=qx[fi];
        y=qy[fi++];
        if (s[x][y]=='#') cur++;
        for (k=0; k<4; k++) {
          nx=x+dx[k];
          ny=y+dy[k];
          if (nx<0 || nx>=n || ny<0 || ny>=m || u[nx][ny]==it || s[nx][ny]=='.') continue;
          u[nx][ny]=it;
          qx[fr]=nx;
          qy[fr++]=ny;
        }
      }
      if (cnt!=cur+1) { puts("1"); return 0; }
    }
    s[ii][jj]='#';
  }
  puts("2");
  return 0;
}