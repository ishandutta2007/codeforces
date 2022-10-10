#include <stdio.h>
#include <string.h>
char s[1000100];
int n,i,l,r,a[1000100];
int main() {
  scanf("%s",s);
  n=strlen(s);
  l=0; r=n-1;
  for (i=0; i<n; i++) if (s[i]=='l') a[r--]=i+1; else a[l++]=i+1;
  for (i=0; i<n; i++) printf("%d\n",a[i]);
  return 0;
}