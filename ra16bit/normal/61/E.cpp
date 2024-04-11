#include <cstdio>
#include <algorithm>
using namespace std;
const int mx=1000100;
int n,m,l,r,h,i,j,d,a[mx],b[mx],s[mx];
long long f[mx],res;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    b[i]=a[i];
  }
  sort(b,b+n);
  for (i=1; i<n; i++) if (b[i]!=b[m]) b[++m]=b[i];
  for (i=0; i<n; i++) {
    l=0; r=m;
    while (l<r) {
      h=(l+r)/2;
      if (b[h]<a[i]) l=h+1; else r=h;
    }
    a[i]=r+1;
  }
  reverse(a,a+n);
  for (i=0; i<n; i++) {
    d=0;
    for (j=a[i]-1; j>0; j&=j-1) { d+=s[j]; res+=f[j]; }
    for (j=a[i]; j<mx; j=(j<<1)-(j&(j-1))) { s[j]++; f[j]+=d; }
  }
  printf("%I64d\n",res);
  return 0;
}