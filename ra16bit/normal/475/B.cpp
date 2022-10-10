#include <stdio.h>
int n,m,i,j,x,y,it,r,fi,fr,qx[22*22],qy[22*22],u[22][22];
char s[22],t[22];
void add(int x, int y) {
  if (u[x][y]==it) return;
  qx[fr]=x; qy[fr++]=y;
  u[x][y]=it; r++;
}
int main() {
  scanf("%d%d",&n,&m);
  scanf("%s",s);
  scanf("%s",t);
  for (i=0; i<n; i++) for (j=0; j<m; j++) {
    fi=fr=0; qx[fr]=i; qy[fr++]=j;
    u[i][j]=++it; r=1;
    while (fi<fr) {
      x=qx[fi]; y=qy[fi++];
      if (s[x]=='<' && y>0) add(x,y-1);
      if (s[x]=='>' && y<m-1) add(x,y+1);
      if (t[y]=='^' && x>0) add(x-1,y);
      if (t[y]=='v' && x<n-1) add(x+1,y);
    }
    if (r!=n*m) { puts("NO"); return 0; }
  }
  puts("YES");
  return 0;
}