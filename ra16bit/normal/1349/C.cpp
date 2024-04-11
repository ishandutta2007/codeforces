#include <bits/stdc++.h>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
const int MX=1010*1010;
int n,m,t,d,i,j,x,y,nx,ny,fi,fr,qx[MX],qy[MX],a[1010][1010];
char s[1010][1010];
long long p;
int main() {
  scanf("%d%d%d",&n,&m,&t);
  for (i=0; i<n; i++) {
    scanf("%s",s[i]);
    for (j=0; j<m; j++) a[i][j]=-1;
  }
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (a[i][j]==-1) {
    for (d=0; d<4; d++) {
      nx=i+dx[d];
      ny=j+dy[d];
      if (nx>=0 && nx<n && ny>=0 && ny<m && s[nx][ny]==s[i][j]) break;
    }
    if (d>=4) continue;
    fi=0; fr=1; qx[0]=i; qy[0]=j; a[i][j]=0;
    while (fi<fr) {
      x=qx[fi];
      y=qy[fi++];
      for (d=0; d<4; d++) {
        nx=x+dx[d];
        ny=y+dy[d];
        if (nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny]==-1 && s[nx][ny]==s[x][y]) {
          a[nx][ny]=0;
          qx[fr]=nx;
          qy[fr++]=ny;
        }
      }
    }
  }
  for (fi=fr=i=0; i<n; i++) for (j=0; j<m; j++) if (a[i][j]==0) {
    qx[fr]=i; qy[fr++]=j;
  }
  while (fi<fr) {
    x=qx[fi];
    y=qy[fi++];
    for (d=0; d<4; d++) {
      nx=x+dx[d];
      ny=y+dy[d];
      if (nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny]==-1) {
        a[nx][ny]=a[x][y]+1;
        qx[fr]=nx;
        qy[fr++]=ny;
      }
    }
  }
  //for (i=0; i<n; i++, puts("")) for (j=0; j<m; j++) printf("%d ",a[i][j]);
  while (t--) {
    scanf("%d%d",&i,&j);
    scanf("%I64d",&p);
    --i; --j;
    x=s[i][j]-'0';
    if (a[i][j]>=0 && p>a[i][j] && ((p-a[i][j])&1)) x^=1;
    printf("%d\n",x);
  }
  return 0;
}