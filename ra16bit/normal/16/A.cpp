#include <stdio.h>
int n,m,i,j;
char s[110],p='-';
bool q=true;
int main() {
  scanf("%d%d",&n,&m); gets(s);
  for (i=0; i<n; i++) {
    gets(s);
    if (s[0]<'0' || s[0]>'9' || s[0]==p) q=false; else p=s[0];
    for (j=1; j<m; j++) if (s[j]!=p) q=false;
  }
  if (q) puts("YES"); else puts("NO");
  return 0;
}