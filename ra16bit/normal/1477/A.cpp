#include <bits/stdc++.h>
using namespace std;
int t,n,i;
long long d,e,m,a[200200];
long long gcd(long long a, long long b) {
  return b?gcd(b,a%b):a;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%I64d",&m);
    for (i=0; i<n; i++) scanf("%I64d",&a[i]);
    sort(a,a+n);
    d=a[1]-a[0];
    for (i=2; i<n; i++) d=gcd(d,a[i]-a[0]);
    e=m-a[0];
    if (e<0) e=-e;
    puts((e%d)?"NO":"YES");
  }
  return 0;
}