#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,i,a[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    bool was=false;
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      if (a[i]==1) was=true;
    }
    if (!was) { puts("YES"); continue; }
    sort(a,a+n);
    for (i=1; i<n; i++) if (a[i]==a[i-1]+1) break;
    puts((i<n)?"NO":"YES");
  }
  return 0;
}