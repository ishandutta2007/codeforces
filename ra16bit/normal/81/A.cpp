#include <stdio.h>
#include <string.h>
int n,m,i;
char s[200200],t[200200];
int main() {
  scanf("%s",s); n=strlen(s);
  m=0; t[0]=s[0];
  for (i=1; i<n; i++) {
    t[++m]=s[i];
    while (m>0 && t[m]==t[m-1]) m-=2;
  }
  for (i=0; i<=m; i++) putchar(t[i]);
  return 0;
}