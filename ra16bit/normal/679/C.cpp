#include <bits/stdc++.h>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int n,m,i,j,d,x,y,nx,ny,tot,t,cc,r,fi,fr,qx[515*515],qy[515*515],cur[515*515],cnt[515*515],u[515*515],a[515][515];
char s[515][515];
void add(int x, int y) {
  int z=a[x][y];
  if (cur[z]++==0) tot+=cnt[z];
}
void dec(int x, int y) {
  int z=a[x][y];
  if (--cur[z]==0) tot-=cnt[z];
}
bool ned(int x) {
  return x!=-1 && x!=m;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) scanf("%s",s[i]+1);
  for (i=1; i<=n; i++) for (j=1; j<=n; j++) if (s[i][j]=='.' && a[i][j]==0) {
    fi=0; fr=1; qx[0]=i; qy[0]=j;
    a[i][j]=++cc; cnt[cc]=1;
    while (fi<fr) {
      x=qx[fi]; y=qy[fi++];
      for (d=0; d<4; d++) {
        nx=x+dx[d];
        ny=y+dy[d];
        if (nx>0 && nx<=n && ny>0 && ny<=n && s[nx][ny]=='.' && a[nx][ny]==0) {
          qx[fr]=nx; qy[fr++]=ny;
          a[nx][ny]=cc; cnt[cc]++;
        }
      }
    }
  }
  for (x=1; x+m<=n+1; x++) {
    for (tot=i=0; i<=cc; i++) cur[i]=0;
    for (i=-1; i<=m; i++) for (j=-1; j<=m; j++) if (a[x+i][1+j] && (ned(i) || ned(j))) add(x+i,1+j);
    for (fr=i=0; i<m; i++) for (j=0; j<m; j++) if (a[x+i][1+j]==0) fr++;
    r=max(r,tot+fr);
    for (j=1; j+m<=n; j++) {
      if (a[x-1][j]) dec(x-1,j);
      if (a[x-1][j+m]) add(x-1,j+m);
      if (a[x+m][j]) dec(x+m,j);
      if (a[x+m][j+m]) add(x+m,j+m);
      for (i=0; i<m; i++) {
        if (a[x+i][j]==0) fr--;
        if (a[x+i][j+m]==0) fr++;
        if (a[x+i][j-1]) dec(x+i,j-1);
        if (a[x+i][j+m+1]) add(x+i,j+m+1);
      }
      r=max(r,tot+fr);
    }
  }
  printf("%d\n",r);
  return 0;
}