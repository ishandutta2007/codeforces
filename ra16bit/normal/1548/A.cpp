#include <bits/stdc++.h>
using namespace std;
int n,m,i,x,y,q,t,r,cnt[200200];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    if (x>y) swap(x,y);
    if (++cnt[x]==1) ++r;
  }
  scanf("%d",&q);
  while (q--) {
    scanf("%d",&t);
    if (t==3) printf("%d\n",n-r); else {
      scanf("%d%d",&x,&y);
      if (x>y) swap(x,y);
      if (t==1) {
        if (++cnt[x]==1) ++r;
      } else {
        if (--cnt[x]==0) --r;
      }
    }
  }
  return 0;
}