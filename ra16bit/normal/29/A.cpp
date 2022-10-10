#include <stdio.h>
const int mx=22000;
int n,i,x,y,d[mx*2],r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x,&y);
    d[x+mx]=x+y+mx;
    if (d[x+y+mx]==x+mx) r++;
  }
  if (r) puts("YES"); else puts("NO");
  return 0;
}