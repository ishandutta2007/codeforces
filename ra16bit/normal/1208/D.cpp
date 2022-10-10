#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int n,i,l,r,h,ans[MX];
long long cur,c[MX],s[MX],a[MX];
long long sum(int x) {
  long long r=0;
  for (; x>0; x&=x-1) r+=s[x];
  return r;
}
void add(int v) {
  for (int i=v; i<=n; i=(i<<1)-(i&(i-1))) s[i]+=v;
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%I64d",&a[i]);
    c[i]=c[i-1]+i;
  }
  for (i=n; i>0; i--) {
    l=0; r=n-1;
    while (l<r) {
      h=(l+r)/2+1;
      cur=c[h]-sum(h);
      if (cur<=a[i]) l=h; else r=h-1;
    }
    ans[i]=++r;
    add(r);
  }
  for (i=1; i<=n; i++) printf("%d ",ans[i]);
  return 0;
}