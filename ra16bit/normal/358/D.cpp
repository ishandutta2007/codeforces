#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,a[3003],b[3003],c[3003],best[3003],s[3003],f[3003];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=1; i<=n; i++) { scanf("%d",&b[i]); s[i]=s[i-1]+b[i]; }
  for (i=1; i<=n; i++) scanf("%d",&c[i]);
  for (i=n; i>1; i--) {
    f[i]=b[i]+f[i+1];
    best[i]=c[i]-b[i];
    for (j=i+1; j<=n; j++) best[j]=max(best[j-1],c[j]-b[j]);
    for (j=i+1; j<=n; j++) f[i]=max(f[i],s[j-1]-s[i-1]+best[j-1]+a[j]+f[j+1]);
  }
  f[1]=a[1]+f[2];
  for (j=2; j<=n; j++) f[1]=max(f[1],s[j-1]+a[j]+f[j+1]);
  printf("%d\n",f[1]);
  return 0;
}