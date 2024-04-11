#include <bits/stdc++.h>
using namespace std;
const int MX=2000200;
int t,n,m,z,nz,i,j,r,res,a[MX],c[MX],d[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for (z=m=i=0; i<n; i=j) {
      for (j=i; j<n && a[i]==a[j]; j++);
      c[m++]=j-i;
    }
    if (m==1) {
      puts("1");
      continue;
    }
    sort(c,c+m);
    for (i=1; i<=c[0]; i++) if (c[0]%(i+1)==0 || c[0]/i>=c[0]%i) d[z++]=i;
    for (j=1; j<m; j++) if (z>0) {
      for (nz=i=0; i<z; i++) if (c[j]%(d[i]+1)==0 || c[j]/d[i]>=c[j]%d[i]) d[nz++]=d[i];
      z=nz;
    }
    if (z>0) {
      res=n;
      for (j=0; j<z; j++) {
        for (r=i=0; i<m; i++) r+=(c[i]+d[j])/(d[j]+1);
        res=min(res,r);
      }
      printf("%d\n",res);
    } else printf("%d\n",n);
  }
  return 0;
}