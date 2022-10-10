#include <bits/stdc++.h>
using namespace std;
int t,n,i,s,a[55];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (s=i=0; i<n; i++) {
      scanf("%d",&a[i]);
      s+=a[i];
    }
    if (s==0) { puts("NO"); continue; }
    sort(a,a+n);
    if (s>0) reverse(a,a+n);
    puts("YES");
    for (i=0; i<n; i++) printf("%d ",a[i]);
    puts("");
  }
  return 0;
}