#include <stdio.h>
#include <string.h>
char s[111];
int n,i,m;
int main() {
  gets(s); n=strlen(s);
  for (i=1; i<n; i++) if (s[i]!='/' || s[m]!='/') s[++m]=s[i];
  while (m>0 && s[m]=='/') m--;
  s[m+1]=0;
  puts(s);
  return 0;
}