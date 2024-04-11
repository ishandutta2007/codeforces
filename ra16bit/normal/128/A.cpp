#include <stdio.h>
const int dx[9]={-1,-1,-1,0,0,0,1,1,1};
const int dy[9]={-1,0,1,-1,0,1,-1,0,1};
int i,j,k,x,y,d,f[34][11][11];
char s[11][11];
bool check(int x, int y) {
  return (x<0 || s[x][y]!='S');
}
int main() {
  for (i=0; i<8; i++) scanf("%s",s[i]);
  f[0][7][0]=true;
  for (k=0; k<33; k++) for (i=0; i<8; i++) for (j=0; j<8; j++) if (f[k][i][j]) {
    if (i==0 && j==7) { puts("WIN"); return 0; }
    for (d=0; d<9; d++) {
      x=i+dx[d];
      y=j+dy[d];
      if (x>=0 && x<8 && y>=0 && y<8 && check(x-k,y) && check(x-k-1,y)) f[k+1][x][y]=true;
    }
  }
  puts("LOSE");
  return 0;
}