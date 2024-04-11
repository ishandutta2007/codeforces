#include <stdio.h>
#include <string.h>
int n,i;
char s[111111];
long long a[270],r;
int main() {
  scanf("%s",s); n=strlen(s);
  for (i=0; i<n; i++) a[s[i]]++;
  for (i=0; i<270; i++) r+=a[i]*a[i];
  printf("%I64d\n",r);
  return 0;
}