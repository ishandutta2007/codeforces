#include <bits/stdc++.h>
using namespace std;
int t,n,m,mx,i,a;
bool was;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (was=mx=i=0; i<n; i++) {
      scanf("%d",&a);
      mx=max(mx,a);
      if (a==m) was=true;
    }
    if (was) puts("1"); else printf("%d\n",max(2,(m+mx-1)/mx));
  }
  return 0;
}