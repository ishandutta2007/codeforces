#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,w,cnt,a[50050][5];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) for (j=0; j<5; j++) scanf("%d",&a[i][j]);
    w=0;
    for (i=1; i<n; i++) {
      for (cnt=j=0; j<5; j++) if (a[i][j]<a[w][j]) ++cnt;
      if (cnt>=3) w=i;
    }
    for (i=0; i<n; i++) if (i!=w) {
      for (cnt=j=0; j<5; j++) if (a[w][j]<a[i][j]) ++cnt;
      if (cnt<3) break;
    }
    printf("%d\n",(i<n)?-1:(w+1));
  }
  return 0;
}