#include <bits/stdc++.h>
using namespace std;
int t,n,i,cnt,a[55];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (cnt=i=0; i<n; i++) {
      scanf("%d",&a[i]);
      if (a[i]==2) cnt++;
    }
    printf("%d\n",n-cnt);
  }
  return 0;
}