#include <stdio.h>
#include <string.h>
int i,j,n,m,a[200020],b[200020],c[200020][26];
char s[200020],t[200020];
int main() {
  scanf("%s",s); n=strlen(s);
  scanf("%s",t); m=strlen(t);
  for (i=j=0; i<n; i++) {
    if (j<m && s[i]==t[j]) j++;
    a[i]=j-1;
  }
  for (i=n-1, j=m-1; i>=0; i--) {
    if (j>=0 && s[i]==t[j]) j--;
    b[i]=j+1;
  }
  for (i=0; i<m; i++) {
    for (j=0; j<26; j++) c[i+1][j]=c[i][j];
	c[i+1][t[i]-'a']++;
  }
  for (i=0; i<n; i++) if (b[i]>a[i] || c[a[i]+1][s[i]-'a']-c[b[i]][s[i]-'a']<=0) { puts("No"); return 0; }
  puts("Yes");
  return 0;
}