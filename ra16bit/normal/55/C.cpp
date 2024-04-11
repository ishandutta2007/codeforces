#include <stdio.h>
int n,m,k,i,x,y;
bool q=false;
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=0; i<k; i++) {
    scanf("%d%d",&x,&y);
    if (x<=5 || y<=5 || x>n-5 || y>m-5) q=true;
  }
  if (q) puts("YES"); else puts("NO");
  return 0;
}