#include <bits/stdc++.h>
using namespace std;
int n,m,k,ta,tb,i,j,res,a[200200],b[200200];
int main() {
  scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<m; i++) scanf("%d",&b[i]);
  if (k>=n || k>=m) { puts("-1"); return 0; }
  for (i=0; i<=k; i++) {
    j=lower_bound(b,b+m,a[i]+ta)-b+k-i;
    if (j>=m) { puts("-1"); return 0; }
    res=max(res,b[j]+tb);
  }
  printf("%d\n",res);
  return 0;
}