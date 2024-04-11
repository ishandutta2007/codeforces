#include <stdio.h>
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int i,j,xa,ya,xb,yb,xc,yc,xd,yd,x,y,a[9][9];
char s[9];
int main() {
  scanf("%s",s); xa=s[0]-'a'; ya=s[1]-'1';
  scanf("%s",s); xb=s[0]-'a'; yb=s[1]-'1';
  scanf("%s",s); xc=s[0]-'a'; yc=s[1]-'1';
  for (i=0; i<4; i++) {
    x=xa; y=ya;
    while (x>=0 && x<8 && y>=0 && y<8 && (x!=xc || y!=yc)) {
      a[x][y]++;
      x+=dx[i]; y+=dy[i];
    }
    a[xa][ya]--;
  }
  for (i=0; i<4; i++) {
    x=xb; y=yb;
    while (x>=0 && x<8 && y>=0 && y<8 && (x!=xc || y!=yc)) {
      a[x][y]++;
      x+=dx[i]; y+=dy[i];
    }
    a[xb][yb]--;
  }
  for (i=-1; i<2; i++) for (j=-1; j<2; j++) if (xc+i>=0 && xc+i<8 && yc+j>=0 && yc+j<8) a[xc+i][yc+j]++;
  scanf("%s",s); xd=s[0]-'a'; yd=s[1]-'1';
  for (i=-1; i<2; i++) for (j=-1; j<2; j++) if (xd+i>=0 && xd+i<8 && yd+j>=0 && yd+j<8 && a[xd+i][yd+j]<=0) {
    puts("OTHER"); return 0;
  }
  puts("CHECKMATE"); return 0;
}