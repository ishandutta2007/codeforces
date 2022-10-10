#include <bits/stdc++.h>
using namespace std;
const int MX=1000100,inf=100000000;
int n,m,i,j,le,ri,q,b[MX];
char s[MX];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%s",s+i*m);
    for (j=0; j<m; j++) if (i>0 && j>0 && s[i*m+j-1]=='X' && s[(i-1)*m+j]=='X') b[j]=1;
  }
  for (j=1; j<m; j++) b[j]=b[j-1]+b[j];
  scanf("%d",&q);
  while (q--) {
    scanf("%d%d",&le,&ri);
    --ri; --le;
    puts((b[ri]-b[le]==0)?"YES":"NO");
  }
  return 0;
}