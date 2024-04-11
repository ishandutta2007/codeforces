#include <stdio.h>
#include <string.h>
int i,j,r=1,n,m,a[10101][26];
char s[10101],t[1000111];
int main() {
  scanf("%s",s); n=strlen(s);
  scanf("%s",t); m=strlen(t);
  for (i=0; i<26; i++) a[n][i]=n;
  for (i=n-1; i>=0; i--) {
    for (j=0; j<26; j++) a[i][j]=a[i+1][j];
    a[i][s[i]-'a']=i;
  }
  for (i=j=0; i<m; i++, j++) {
    j=a[j][t[i]-'a'];
    if (j==n) {
      j=a[0][t[i]-'a']; r++;
      if (j==n) { puts("-1"); return 0; }
    }
  }
  printf("%d\n",r);
  return 0;
}