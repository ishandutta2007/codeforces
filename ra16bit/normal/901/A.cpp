#include <bits/stdc++.h>
using namespace std;
int h,i,j,x,l,r,pa[200200],pb[200200];
bool ans;
int main() {
  scanf("%d",&h);
  for (j=0; j<=h; j++) {
    scanf("%d",&x);
    for (i=1; i<=x; i++) {
      pa[r+i]=l;
      pb[r+i]=min(l+i-1,r);
      if (pa[r+i]!=pb[r+i]) ans=true;
    }
    l=r+1;
    r=r+x;
  }
  if (ans) {
    puts("ambiguous");
    for (i=1; i<=r; i++) printf("%d ",pa[i]); puts("");
    for (i=1; i<=r; i++) printf("%d ",pb[i]); puts("");
  } else puts("perfect");
  return 0;
}