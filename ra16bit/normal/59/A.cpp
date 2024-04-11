#include <stdio.h>
#include <string.h>
int i,n,a,b;
char s[111];
int main() {
  gets(s); n=strlen(s);
  for (i=0; i<n; i++) if (s[i]>='a') a++; else b++;
  if (b<=a) {
    for (i=0; i<n; i++) if (s[i]<'a') s[i]=s[i]-'A'+'a';
  } else for (i=0; i<n; i++) if (s[i]>='a') s[i]=s[i]-'a'+'A';
  puts(s);
  return 0;
}