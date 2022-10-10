#include <bits/stdc++.h>
using namespace std;
int n,m,x,i,j,c[200200],a[1010];
long long b[1010],r;
long long pw(long long a, long long b) {
  if (b==0) return 1LL%m;
  if (b&1) return (pw(a,b-1)*a)%m;
  long long x=pw(a,b/2);
  return (x*x)%m;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d",&c[i]);
  sort(c,c+n);
  for (i=0; i<n; i++) {
    x=c[i]%m;
    for (j=0; j<=x; ++j) b[x-j]+=a[j];
    a[x]++; x+=m;
    for (; j<m; ++j) b[x-j]+=a[j];
  }
  r=1%m;
  for (i=0; i<m; i++) if (b[i]) r=(r*pw(i,b[i]))%m;
  printf("%d\n",int(r));
  return 0;
}