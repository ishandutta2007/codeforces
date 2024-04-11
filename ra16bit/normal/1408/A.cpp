#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,a[5][111],r[444];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (j=0; j<3; j++) for (i=0; i<n; i++) scanf("%d",&a[j][i]);
    for (j=0; j<3; j++) r[j]=a[j][0];
    for (i=1; i<n; i++) {
      for (j=0; j<3; j++) if (a[j][i]!=r[i-1] && a[j][i]!=r[0]) break;
      r[i]=a[j][i];
    }
    for (i=0; i<n; i++) printf("%d ",r[i]);
    puts("");
  }
  return 0;
}