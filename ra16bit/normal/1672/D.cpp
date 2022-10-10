#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int t,n,i,j,a[MX],b[MX],cnt[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=1; i<=n; i++) cnt[i]=0;
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    for (i=0; i<n; i++) scanf("%d",&b[i]);
    for (i=j=0; i<n; i++) if (i>0 && b[i]==b[i-1] && cnt[b[i]]>0) --cnt[b[i]]; else {
      for (; j<n; j++) {
        if (a[j]==b[i]) break;
        ++cnt[a[j]];
      }
      if (j>=n) break;
      ++j;
    }
    puts((i<n)?"NO":"YES");
  }
  return 0;
}