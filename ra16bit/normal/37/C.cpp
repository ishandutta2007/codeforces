#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,p,a[1111],r[1111][1111],c[1111],k[1111];
bool cmp(int i, int j) { return a[i]<a[j]; }
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&a[i]); k[i]=i; }
  sort(k,k+n,cmp);
  for (i=1; i<=1000; i++) for (; j<n; j++) {
    if (a[k[j]]!=i) break;
    for (p=0; p<i; p++) r[k[j]][p]=c[p];
    for (p=i-1; p>=0; p--) if (c[p]==0) break; else c[p]=0;
    if (p<0) {
      if (j<n-1) { puts("NO"); return 0; }
    } else c[p]=1;
  }
  puts("YES");
  for (i=0; i<n; i++,puts("")) for (j=0; j<a[i]; j++) printf("%d",r[i][j]);
  return 0;
}