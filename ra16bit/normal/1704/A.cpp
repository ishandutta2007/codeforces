#include <bits/stdc++.h>
using namespace std;
const int MX=55;
int t,n,m,i;
char a[MX],b[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    scanf("%s",a);
    scanf("%s",b);
    if (m>n) { puts("No"); continue; }
    for (i=1; i<m; i++) if (b[m-i]!=a[n-i]) break;
    if (i<m) { puts("No"); continue; }
    for (; i<=n; i++) if (a[n-i]==b[0]) break;
    if (i>n) puts("No"); else puts("Yes");
  }
  return 0;
}