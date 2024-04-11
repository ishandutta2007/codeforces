#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,i,mx,mn,a[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (mn=mx=i=0; i<n; i++) {
      scanf("%d",&a[i]);
      if (a[i]<a[mn]) mn=i;
      if (a[i]>a[mx]) mx=i;
    }
    printf("%d %d\n",mn+1,mx+1);
  }
  return 0;
}