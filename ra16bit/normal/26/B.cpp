#include <stdio.h>
#include <string.h>
int i,n,c,d;
char s[1111111];
int main() {
  gets(s); n=strlen(s);
  for (i=0; i<n; i++) if (s[i]=='(') c++; else if (c>0) c--; else d++;
  printf("%d\n",n-c-d);
  return 0;
}