#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int n,m,i;
long long a[MX],b[MX],g;
long long gcd(long long a, long long b) {
  return b?gcd(b,a%b):a;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%I64d",&a[i]);
  for (i=0; i<m; i++) scanf("%I64d",&b[i]);
  sort(a,a+n);
  for (i=1; i<n; i++) g=gcd(g,a[i]-a[0]);
  for (i=0; i<m; i++) printf("%I64d ",gcd(g,a[0]+b[i]));
  return 0;
}