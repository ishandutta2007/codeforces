#include <bits/stdc++.h>
using namespace std;
int n,m,i,it,r,x[55],y[55],a[9],was[7][7];
void rec(int l) {
  if (l>n) {
    ++it;
    int cnt=0;
    for (int i=0; i<m; i++) {
      int le=min(a[x[i]],a[y[i]]);
      int ri=max(a[x[i]],a[y[i]]);
      if (was[le][ri]!=it) {
        was[le][ri]=it;
        cnt++;
      }
    }
    r=max(r,cnt);
    return;
  }
  for (int i=1; i<=6; i++) {
    a[l]=i;
    rec(l+1);
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) scanf("%d%d",&x[i],&y[i]);
  rec(1);
  printf("%d\n",r);
  return 0;
}