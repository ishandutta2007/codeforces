#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,i,j,best,cur,a[4444];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d",&n,&m,&k);
    for (i=1; i<=n; i++) scanf("%d",&a[i]);
    k=min(k,m-1);
    for (best=i=0; i<=k; i++) {
      cur=1000000000;
      for (j=0; j<=m-1-k; j++) cur=min(cur,max(a[n-i-j],a[m-i-j]));
      best=max(best,cur);
    }
    printf("%d\n",best);
  }
  return 0;
}