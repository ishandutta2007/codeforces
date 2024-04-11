#include <stdio.h>
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
const char dz[4]={'v','>','^','<'};
int n,m,i,j,k,x,y,fi,fr,qx[2002*2002],qy[2002*2002],a[2002][2002];
char s[2002][2002];
bool dfs(int i, int j, int pk) {
  s[i][j]='~';
  for (int k=0; k<4; k++) if (k!=pk) {
    int x=i+dx[k];
    int y=j+dy[k];
    if (x<0 || x>=n || y<0 || y>=m || s[x][y]=='*') continue;
    if (s[x][y]!='.') return false;
    if (!dfs(x,y,(k+2)%4)) return false;
  }
  if (s[i][j]=='~' && pk>=0) {
    s[i+dx[pk]][j+dy[pk]]=dz[(pk+2)%4];
    s[i][j]=dz[pk];
  }
  return (s[i][j]!='~');
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (s[i][j]=='.') {
    for (k=0; k<4; k++) {
      x=i+dx[k];
      y=j+dy[k];
      if (x<0 || x>=n || y<0 || y>=m || s[x][y]=='*') continue;
      a[i][j]++;
    }
    if (a[i][j]==0) { puts("Not unique"); return 0; }
    if (a[i][j]==1) { s[i][j]='~'; qx[fr]=i; qy[fr++]=j; }
  }
  while (fi<fr) {
    i=qx[fi]; j=qy[fi++];
    if (s[i][j]!='~') continue;
    bool was=false;
    for (k=0; k<4; k++) {
      x=i+dx[k];
      y=j+dy[k];
      if (x<0 || x>=n || y<0 || y>=m) continue;
      if (s[x][y]=='.' || s[x][y]=='~') {
        was=true;
        s[i][j]=dz[k];
        s[x][y]=dz[(k+2)&3];
        break;
      }
    }
    if (!was) { puts("Not unique"); return 0; }
    for (k=0; k<4; k++) {
      i=x+dx[k];
      j=y+dy[k];
      if (i>=0 && i<n && j>=0 && j<m && s[i][j]=='.') {
        a[i][j]--;
        if (a[i][j]==0) { puts("Not unique"); return 0; }
        if (a[i][j]==1) { s[i][j]='~';  qx[fr]=i; qy[fr++]=j; }
      }
    }
  }
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (s[i][j]=='.' || s[i][j]=='~') { puts("Not unique"); return 0; }
  for (i=0; i<n; i++) puts(s[i]);
  return 0;
}