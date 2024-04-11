#include <cstdio>
#include <algorithm>
using namespace std;
int i,j,k,n,a[20020],f[20020];
long long r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    a[n+i]=a[i];
  }
  for (i=0; i<n; i++) {
    f[0]=0;
    for (j=1; j<n; j++) {
      f[j]=f[j-1]+1;
      for (k=2; k<=a[i+j] && j-k>=0; k++) f[j]=min(f[j],f[j-k]+1);
    }
    r+=f[n-1];
  }
  printf("%I64d\n",r);
  return 0;
}