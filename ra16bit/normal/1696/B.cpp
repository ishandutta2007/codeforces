#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,i,le,ri,a[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    le=ri=-1;
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      if (a[i]!=0) {
        if (le==-1) le=i;
        ri=i;
      }
    }
    if (le==-1) { puts("0"); continue; }
    for (i=le; i<=ri; i++) if (a[i]==0) break;
    if (i>ri) puts("1"); else puts("2");
  }
  return 0;
}