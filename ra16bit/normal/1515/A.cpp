#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,cur,w,a[111];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    w=-1;
    for (cur=i=0; i<n; i++) {
      scanf("%d",&a[i]);
      cur+=a[i];
      if (cur==m) w=i;
    }
    if (w==n-1) puts("NO"); else {
      puts("YES");
      if (w!=-1) swap(a[w],a[w+1]);
      for (i=0; i<n; i++) printf("%d ",a[i]);
      puts("");
    }
  }
  return 0;
}