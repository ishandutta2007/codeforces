#include <stdio.h>
#include <string.h>
int n,i;
char s[100100];
int main() {
  gets(s);
  n=strlen(s);
  for (i=0; i<n; i++) if (s[i]=='"') {
    putchar('<');
    for (i++; s[i]!='"' && i<n; i++) putchar(s[i]);
	puts(">");
  } else if (s[i]!=' ') {
    putchar('<');
    for (; s[i]!=' ' && i<n; i++) putchar(s[i]);
	puts(">");
  }
  return 0;
}