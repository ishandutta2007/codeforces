#include <bits/stdc++.h>
using namespace std;
int t,n,i,a[1010],b[1010];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    for (i=0; i<n; i++) scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+n);
    for (i=0; i<n; i++) printf("%d ",a[i]); puts("");
    for (i=0; i<n; i++) printf("%d ",b[i]); puts("");
  }
  return 0;
}