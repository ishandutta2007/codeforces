#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,s,a[100100],b[100100];
long long x,r;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) scanf("%d%d",&a[i],&b[i]);
  sort(b,b+m);
  reverse(b,b+m);
  for (i=1; i<=m; i++) {
    x=(i*(i-1LL))/2;
    if ((i&1)==0) x+=i/2-1;
    if (x+1<=n) s=i;
  }
  for (i=0; i<s; i++) r+=b[i];
  printf("%I64d\n",r);
  return 0;
}