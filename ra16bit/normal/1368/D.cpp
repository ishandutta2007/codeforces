#include <bits/stdc++.h>
using namespace std;
int n,i,a,j,c[22];
long long cur,r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a);
    for (j=0; j<22; j++) if ((a>>j)&1) ++c[j];
  }
  for (r=i=0; i<n; i++) {
    for (cur=j=0; j<22; j++) if (c[j]>0) {
      cur+=(1<<j);
      --c[j];
    }
    r+=cur*cur;
  }
  printf("%I64d\n",r);
  return 0;
}