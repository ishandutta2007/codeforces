#include <stdio.h>
#include <string.h>
int t,n,i;
char s[100100],b[100100];
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<n; i++) {
    b[++t]=s[i];
    while (t>1 && b[t]==b[t-1]) t-=2;
  }
  puts(t?"No":"Yes");
  return 0;
}