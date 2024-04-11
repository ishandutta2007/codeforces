#include <stdio.h>
#include <string.h>
int n,i;
char s[111],t[111];
int main() {
  scanf("%s",s);
  scanf("%s",t); n=strlen(t);
  for (i=0; i<n; i++) s[i]='0'+(s[i]!=t[i]);
  puts(s);
  return 0;
}