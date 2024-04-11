#include <bits/stdc++.h>
using namespace std;
const int MX=1010;
int t,n,i,j,r,a[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    r=0;
    for (i=0; i<n; i++) for (j=i+1; j<n; j++) r=max(r,a[i]+a[j]);
    printf("%d\n",r);
  }
  return 0;
}