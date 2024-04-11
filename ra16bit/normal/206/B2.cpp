#include <cstdio>
#include <algorithm>
using namespace std;
int i,j,k,l,b,n,mn,a[20020],f[20020];
long long r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    a[n+i]=a[i];
  }
  for (i=n-1; i<2*n-1; i++) {
    f[i]=0; l=i-1; mn=i-n+1;
    for (j=i; j>mn; j--) {
      b=max(mn,j-a[j]);
      for (; l>=b; l--) f[l]=f[j]+1;
    }
    r+=f[mn];
  }
  printf("%I64d\n",r);
  return 0;
}