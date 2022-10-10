#include <bits/stdc++.h>
using namespace std;
const int MX=2020;
int t,n,i,mx,a[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    mx=a[n-1]-a[0];
    for (i=1; i<n; i++) mx=max(mx,a[i]-a[0]);
    for (i=0; i<n-1; i++) mx=max(mx,a[n-1]-a[i]);
    for (i=1; i<n; i++) mx=max(mx,a[i-1]-a[i]);
    printf("%d\n",mx);
  }
  return 0;
}