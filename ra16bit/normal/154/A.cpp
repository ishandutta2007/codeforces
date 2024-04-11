#include <stdio.h>
#include <string.h>
int n,m,i,j,cur,best,f[26];
char s[100100],t[11];
bool g[26][26];
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<n; i++) s[i]-='a';
  scanf("%d",&m);
  for (i=0; i<m; i++) {
    scanf("%s",&t);
    for (j=0; j<2; j++) t[j]-='a';
    for (j=0; j<2; j++) g[t[j]][t[1-j]]=true;
  }
  for (i=0; i<n; i++) {
    cur=1;
    for (j=0; j<26; j++) if ((!g[j][s[i]]) && f[j]+1>cur) cur=f[j]+1;
    if (cur>f[s[i]]) {
      f[s[i]]=cur;
      if (cur>best) best=cur;
    }
  }
  printf("%d\n",n-best);
  return 0;
}