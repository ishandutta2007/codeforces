#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,a[300300],s[300300];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n); m=0;
    for (i=1; i<=n; i++) {
      scanf("%d",&a[i]);
      if (m==0 || a[i]<s[m]) s[++m]=a[i]; else {
        while (m>1 && a[i]>s[m-1]) --m;
      }
    }
    //for (i=1; i<=m; i++) printf("%d ",s[i]); puts("s");
    puts((m==1)?"YES":"NO");
  }
  return 0;
}