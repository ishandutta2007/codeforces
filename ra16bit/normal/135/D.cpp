#include <stdio.h>
const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,-1,1,-1,0,1};
const int di[4]={-1,0,1,0};
const int dj[4]={0,-1,0,1};
int N,r,n,m,i,j,x,y,k,p,c,it,px[1000010],py[1000010],col[1010][1010],v[1010][1010];
bool u[1010][1010];
char s[1010][1010];
void dfs(int i, int j, int it) {
  u[i][j]=true;
  for (int k=0; k<8; k++) {
    int x=i+dx[k];
    int y=j+dy[k];
    if (x<0 || y<0 || x>=n || y>=m || u[x][y]) continue;
    if (s[x][y]=='1') {
      if (v[x][y]!=it) { px[N]=x; py[N++]=y; v[x][y]=it; }
    } else dfs(x,y,it);
  }
}
void cfs(int i, int j) {
  col[i][j]=it;
  for (int k=0; k<4; k++) {
    int x=i+di[k];
    int y=j+dj[k];
    if (x<0 || y<0 || x>=n || y>=m || v[x][y]!=it || col[x][y]==it) continue;
    cfs(x,y);
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=0; i<n; i++) {
    if (s[i][0]=='0' && (!u[i][0])) { N=0; dfs(i,0,0); }
    if (s[i][m-1]=='0' && (!u[i][m-1])) { N=0; dfs(i,m-1,0); }
  }
  for (i=0; i<m; i++) {
    if (s[0][i]=='0' && (!u[0][i])) { N=0; dfs(0,i,0); }
    if (s[n-1][i]=='0' && (!u[n-1][i])) { N=0; dfs(n-1,i,0); }
  }
  for (i=0; i<n-1; i++) for (j=0; j<m-1; j++) if (s[i][j]=='1' && s[i+1][j]=='1' && s[i][j+1]=='1' && s[i+1][j+1]=='1') r=4;
  /*for (i=0; i<n; i++) {
    for (j=0; j<m; j++) printf("%d",u[i][j]);
    puts("");
  }
  puts("----");*/
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (s[i][j]=='0' && (!u[i][j])) {
    N=0; ++it;
    dfs(i,j,it);
    if (N>r) {
      for (p=0; p<N; p++) {
        for (c=k=0; k<4; k++) {
          x=px[p]+di[k];
          y=py[p]+dj[k];
          if (x>=0 && x<n && y>=0 && y<m && v[x][y]==it) c++;
        }
        if (c!=2) break;
      }
      if (p>=N) {
        cfs(px[0],py[0]);
        for (p=0; p<N; p++) if (col[px[p]][py[p]]!=it) break;
        if (p>=N) r=N;
      }
    }
  /*for (int i=0; i<n; i++) {
  for (int j=0; j<m; j++) printf("%d",v[i][j]);
  puts("");
  }
  puts("v---");
    for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) printf("%d",col[i][j]);
    puts("");
  }
  puts("-c--");
    for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) printf("%d",u[i][j]);
    puts("");
  }
  puts("-u--");*/
  }
  printf("%d\n",r);
  return 0;
}