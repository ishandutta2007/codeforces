#include <stdio.h>
#include <string.h>
int n,i,k,p[1000100];
char s[1000100];
bool a[1000100];
int main() {
  scanf("%s",s+1);
  n=strlen(s+1);
  for (i=2; i<=n; i++) {
    for (k=p[i-1]; k>0 && s[k+1]!=s[i]; k=p[k]);
	p[i]=k+int(s[k+1]==s[i]);
  }
  for (i=2; i<n; i++) a[p[i]]=true;
  for (k=p[n]; k>0; k=p[k]) if (a[k]) break;
  if (k==0) puts("Just a legend"); else for (i=1; i<=k; i++) putchar(s[i]);
  return 0;
}