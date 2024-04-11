#include <bits/stdc++.h>
using namespace std;
const int inf=1000000100;
int t,n,i,a[200200];
long long x;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    x=inf-inf%n;
    if (x<inf) x+=n;
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      a[i]=(a[i]+i+x)%n;
    }
    sort(a,a+n);
    for (i=1; i<n; i++) if (a[i]!=a[i-1]+1) break;
    puts((i>=n)?"YES":"NO");
  }
  return 0;
}