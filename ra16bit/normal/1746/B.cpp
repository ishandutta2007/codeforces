#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,i,s,c,res,a[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (s=i=0; i<n; i++) {
      scanf("%d",&a[i]);
      s+=a[i];
    }
    if (s==0 || s==n) { puts("0"); continue; }
    res=n;
    for (c=i=0; i<n; i++) {
      res=min(res,max(c,(n-s-(i-c))));
      c+=a[i];
    }
    printf("%d\n",res);
  }
  return 0;
}