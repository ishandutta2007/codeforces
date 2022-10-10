#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,cur,a[111];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    for (i=1; i<n; i++) {
      cur=min(m/i,a[i]);
      a[0]+=cur;
      m-=cur*i;
    }
    printf("%d\n",a[0]);
  }
  return 0;
}