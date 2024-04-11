#include <stdio.h>
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int n,m,k,i,j,cnt,a[505][505];
char s[505][505];
void dfs(int i, int j) {
  a[i][j]=++cnt;
  for (int k=0; k<4; k++) {
    int x=i+dx[k];
    int y=j+dy[k];
    if (x>=0 && y>=0 && x<n && y<m && s[x][y]=='.' && a[x][y]==0) dfs(x,y);
  }
}
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (s[i][j]=='.' && a[i][j]==0) dfs(i,j);
  for (i=0; i<n; i++) {
    for (j=0; j<m; j++) if (s[i][j]=='.' && a[i][j]>cnt-k) putchar('X'); else putchar(s[i][j]);
    putchar('\n');
  }
  return 0;
}