#include <bits/stdc++.h>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int n,m,i,j,k,d,x,y,nx,ny,ca,cb,cnt,fi,fr,a[1010][1010],qx[1010*1010],qy[1010*1010];
char s[1010][1010];
int main() {
  scanf("%d%d",&n,&m);
  for (ca=i=0; i<n; i++) {
    scanf("%s",s[i]);
    for (k=j=0; j<m; j++) if ((j==0 || s[i][j-1]=='.') && s[i][j]=='#') k++;
    if (k>1) { puts("-1"); return 0; }
    if (k==0) ca++;
  }
  for (cb=j=0; j<m; j++) {
    for (k=i=0; i<n; i++) if ((i==0 || s[i-1][j]=='.') && s[i][j]=='#') k++;
    if (k>1) { puts("-1"); return 0; }
    if (k==0) cb++;
  }
  if (ca==0 && cb!=0) { puts("-1"); return 0; }
  if (cb==0 && ca!=0) { puts("-1"); return 0; }
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (s[i][j]=='#' && a[i][j]==0) {
    qx[0]=i; qy[0]=j; a[i][j]=++cnt;
    for (fi=0, fr=1; fi<fr; fi++) {
      x=qx[fi];
      y=qy[fi];
      for (d=0; d<4; d++) {
        nx=x+dx[d];
        ny=y+dy[d];
        if (nx>=0 && nx<n && ny>=0 && ny<m && s[nx][ny]=='#' && a[nx][ny]==0) {
          qx[fr]=nx;
          qy[fr++]=ny;
          a[nx][ny]=cnt;
        }
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
}