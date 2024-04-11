#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,j,a,s[1010];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (m=i=0; i<n; i++) {
      scanf("%d",&a);
      if (a==1) s[++m]=a; else {
        while (m>0 && s[m]+1!=a) --m;
        if (m==0) s[++m]=a; else s[m]=a;
      }
      for (j=1; j<m; j++) printf("%d.",s[j]);
      printf("%d\n",a);
    }
  }
  return 0;
}