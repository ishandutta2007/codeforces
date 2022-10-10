#include <stdio.h>
#include <memory.h>
int n,m,i,z,f[42][42][42][42];
char s[22][22];
int solve(int sx, int sy, int rx, int ry) {
  if (sx>sy || rx>ry) return 0;
  if (f[sx][sy][rx][ry]>=0) return f[sx][sy][rx][ry];
  bool u[515];
  int i,j,S,R;
  memset(u,false,sizeof(u));
  for (i=0; i<n; i++) for (j=0; j<m; j++) {
    S=i+j; R=j-i+n-1;
    if ((S&1)==z && S>=sx && S<=sy && R>=rx && R<=ry) {
      if (s[i][j]=='L') u[solve(sx,S-2,rx,ry)^solve(S+2,sy,rx,ry)]=true;
       else if (s[i][j]=='R') u[solve(sx,sy,rx,R-2)^solve(sx,sy,R+2,ry)]=true;
       else if (s[i][j]=='X') u[solve(sx,S-2,rx,R-2)^solve(sx,S-2,R+2,ry)^solve(S+2,sy,rx,R-2)^solve(S+2,sy,R+2,ry)]=true;
    }
  }
  for (i=0; u[i]; i++);
  return f[sx][sy][rx][ry]=i;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  memset(f,255,sizeof(f));
  if (n&1) {
    z=0;
    i=solve(0,(n+m-2)-((n+m-2)&1),0,(n+m-2)-((n+m-2)&1));
    z=1;
    i^=solve(1,(n+m-2)-((n+m-1)&1),1,(n+m-2)-((n+m-1)&1));
  } else {
    z=0;
    i=solve(0,(n+m-2)-((n+m-2)&1),1,(n+m-2)-((n+m-1)&1));
    z=1;
    i^=solve(1,(n+m-2)-((n+m-1)&1),0,(n+m-2)-((n+m-2)&1));
  }
  puts(i?"WIN":"LOSE");
  return 0;
}