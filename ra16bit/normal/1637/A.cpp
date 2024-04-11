#include <bits/stdc++.h>
using namespace std;
const int MX=10100;
int t,n,i,a[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    for (i=1; i<n; i++) if (a[i]<a[i-1]) break;
    puts((i<n)?"YES":"NO");
  }
  return 0;
}