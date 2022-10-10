#include <bits/stdc++.h>
using namespace std;
int n,i,j,cnt,r,a[2020],b[2020],c[2020];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    b[i]=a[i];
  }
  sort(b,b+n);
  for (i=0; i<n; i++) {
    a[i]=lower_bound(b,b+n,a[i])-b;
    if (++c[a[i]]==2) cnt++;
  }
  for (r=n, i=0; i<n; i++) {
    for (j=i; ; j++) {
      if (cnt==0) {
        r=min(r,j-i);
        break;
      }
      if (j==n) break;
      if (--c[a[j]]==1) cnt--;
    }
    for (--j; j>=i; --j) if (++c[a[j]]==2) cnt++;
  }
  printf("%d\n",r);
  return 0;
}