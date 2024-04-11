#include <bits/stdc++.h>
using namespace std;
int t,n,m,i;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    if (n>m) { puts("No"); continue; }
    m-=n;
    if (n&1) {
      puts("Yes");
      printf("%d",m+1);
      for (i=1; i<n; i++) printf(" 1");
      puts("");
    } else if (m%2==0) {
      puts("Yes");
      printf("%d %d",m/2+1,m/2+1);
      for (i=2; i<n; i++) printf(" 1");
      puts("");
    } else puts("No");
  }
  return 0;
}