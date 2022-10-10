#include <cstdio>
#include <algorithm>
using namespace std;
int i,j,x[11],y[11],a[11],d[11][11];
bool q,u[11];
long long sc(long long xa, long long xb, long long ya, long long yb) {
  return xa*xb+ya*yb;
}
void rec(int l) {
  if (l==8) {
    if (d[a[0]][a[1]]!=d[a[1]][a[2]]) return;
    if (d[a[0]][a[1]]!=d[a[2]][a[3]]) return;
    if (d[a[0]][a[1]]!=d[a[3]][a[0]]) return;
    for (int i=0; i<4; i++) {
      int X=a[i],Y=a[(i+1)%4],Z=a[(i+2)%4];
      if (sc(x[Y]-x[X],x[Z]-x[Y],y[Y]-y[X],y[Z]-y[Y])) return;
      X=a[i+4],Y=a[4+(i+1)%4],Z=a[4+(i+2)%4];
      if (sc(x[Y]-x[X],x[Z]-x[Y],y[Y]-y[X],y[Z]-y[Y])) return;
    }
    puts("YES"); q=true;
    for (int i=0; i<8; i++) printf("%d%c",a[i]+1,(i%4==3?'\n':' '));
    return;
  }
  for (int i=0; i<8; i++) if (!u[i]) {
    u[i]=true; a[l]=i; rec(l+1); u[i]=false;
    if (q) return;
  }
}
int main() {
  for (i=0; i<8; i++) scanf("%d%d",&x[i],&y[i]);
  for (i=0; i<8; i++) for (j=0; j<8; j++) d[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
  rec(0);
  if (!q) puts("NO");
  return 0;
}