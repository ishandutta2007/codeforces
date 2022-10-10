#include <stdio.h>
int n,i,j;
char s[111];
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  for (i=0; i<n; i++) if (s[i]=='*') for (j=1; i+j*4<n; j++)
    if (s[i+j]=='*' && s[i+2*j]=='*' && s[i+3*j]=='*' && s[i+4*j]=='*') {
      puts("yes");
      return 0;
    }
  puts("no");
  return 0;
}