#include <bits/stdc++.h>
using namespace std;
const char c[2]={'R','W'};
int t,n,m,i,j,k;
char s[55][55];
bool ok;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) scanf("%s",s[i]);
    for (k=0; k<2; k++) {
      ok=true;
      for (i=0; i<n && ok; i++) for (j=0; j<m && ok; j++) if (s[i][j]!='.') {
        if (s[i][j]!=c[k^((i+j)&1)]) ok=false;
      }
      if (ok) {
        puts("YES");
        for (i=0; i<n; i++, puts("")) for (j=0; j<m; j++) putchar(c[k^((i+j)&1)]);
        break;
      }
    }
    if (!ok) puts("NO");
  }
  return 0;
}