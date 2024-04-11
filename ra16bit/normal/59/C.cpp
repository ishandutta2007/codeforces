#include <stdio.h>
#include <string.h>
int n,k,i,j;
char s[111];
bool a[28];
int main() {
  scanf("%d",&k);
  scanf("%s",s); n=strlen(s);
  for (i=0; i<n; i++) {
    if (s[i]=='?' && s[n-1-i]!='?') s[i]=s[n-1-i];
    if (s[i]!='?') a[s[i]-'a']=true;
    if (s[n-1-i]!='?' && s[i]!=s[n-1-i]) { puts("IMPOSSIBLE"); return 0; }
  }
  for (j=k-1; j>=0 && a[j]; j--);
  for (i=(n-1)/2; i>=0; i--) if (s[i]=='?') {
    if (j<0) j=0;
    s[i]=s[n-1-i]=j+'a';
    a[j]=true;
    while (j>=0 && a[j]) j--;
  }
  if (j<0) puts(s); else puts("IMPOSSIBLE");
  return 0;
}