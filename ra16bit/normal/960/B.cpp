#include <bits/stdc++.h>
using namespace std;
int n,ka,kb,i,x,a[1010],b[1010];
long long r;
long long sqr(long long x) { return x*x; }
int solve() {
  int x=0,r=abs(b[0]-a[0]);
  for (int i=1; i<n; i++) {
    int cur=abs(b[i]-a[i]);
    if (cur>r) { r=cur; x=i; }
  }
  return x;
}
int main() {
  scanf("%d%d%d",&n,&ka,&kb);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) scanf("%d",&b[i]);
  for (i=0; i<ka; i++) {
    x=solve();
    if (b[x]<a[x]) a[x]--; else a[x]++;
  }
  for (i=0; i<kb; i++) {
    x=solve();
    if (b[x]<a[x]) b[x]++; else b[x]--;
  }
  for (i=0; i<n; i++) r+=sqr(b[i]-a[i]);
  printf("%lld\n",r);
  return 0;
}