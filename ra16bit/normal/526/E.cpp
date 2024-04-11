#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,k,c,r,best,w,a[2000002],b[2000002];
long long x,s[2000002];
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    a[n+i]=a[i];
  }
  for (i=1; i<=2*n; i++) s[i]=s[i-1]+a[i];
  while (m--) {
    scanf("%I64d",&x);
    best=r=1000000000;
    for (i=j=0; i<2*n; i++) {
      for (; j<=2*n && s[j]-s[i]<=x; j++);
      b[i+1]=j;
      if (i<=n && j-i<best) { best=j-i; w=i+1; }
    }
    for (i=w; i<=b[w]; i++) {
      k=i>n?i-n:i;
      for (j=k, c=0; j<k+n; c++) j=b[j];
      r=min(r,c);
    }
    printf("%d\n",r);
  }
  return 0;
}