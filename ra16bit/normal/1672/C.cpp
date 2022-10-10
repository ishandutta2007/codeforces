#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int t,n,le,ri,i,a[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (le=-1, i=0; i<n; i++) {
      scanf("%d",&a[i]);
      if (i>0 && a[i]==a[i-1]) {
        if (le==-1) le=i-1;
        ri=i;
      }
    }
    if (le==-1 || le+1==ri) { puts("0"); continue; }
    printf("%d\n",max(1,ri-le-2));
  }
  return 0;
}