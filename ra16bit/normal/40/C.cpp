#include <cstdio>
#include <algorithm>
using namespace std;
int n,x,m,y,ly,ry,i;
long long r;
int main() {
  scanf("%d%d%d%d",&n,&x,&m,&y);
  if (x>y) { swap(x,y); swap(n,m); }
  for (r=n+1,i=1; i<=m; i++) {
    ly=y-i-x; ry=y+i-x;
    if (ly>=n || ly<=-n) r++; else if (ly>=0 && ry>=0) {
      ry=min(n,ry-1);
      r+=2*(ry-ly);
    } else {
      ry=min(n,ry-1);
      r+=2*(ry+ly)+1;
    }
  }
  printf("%I64d\n",r);
  return 0;
}