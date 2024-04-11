#include <bits/stdc++.h>
using namespace std;
int n,l,r,p,q;
char a[300300],c;
int main() {
  scanf("%s",a);
  n=strlen(a);
  p=l=0; q=r=n-1;
  while (l<=r) {
    if (a[l]!=a[r]) break; else c=a[l];
    for (; l<=r && a[l]==c; l++);
    for (; l<=r && a[r]==c; r--);
    if (l>r) {
      if (q-p>0) printf("%d\n",q-p+2); else puts("0");
      return 0;
    } else {
      if (l-p+q-r<3) break;
    }
    p=l; q=r;
  }
  puts("0");
  return 0;
}