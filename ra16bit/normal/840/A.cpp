#include <bits/stdc++.h>
using namespace std;
int n,i,a[200200],b[200200],k[200200],r[200200];
bool cmp(int x, int y) {
  return b[x]>b[y];
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) { scanf("%d",&b[i]); k[i]=i; }
  sort(a,a+n);
  sort(k,k+n,cmp);
  for (i=0; i<n; i++) r[k[i]]=a[i];
  for (i=0; i<n; i++) printf("%d ",r[i]);
  return 0;
}