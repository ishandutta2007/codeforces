#include <bits/stdc++.h>
using namespace std;
int n,i,j,a[100100],c[30],w[30];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    for (j=0; j<30; j++) if ((a[i]>>j)&1) {
      c[j]++;
      w[j]=i;
    }
  }
  for (j=29; j>=0; j--) if (c[j]==1) {
    printf("%d",a[w[j]]);
    for (i=0; i<n; i++) if (i!=w[j]) printf(" %d",a[i]);
    return 0;
  }
  for (i=0; i<n; i++) printf("%d ",a[i]);
  return 0;
}