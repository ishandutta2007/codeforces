#include <stdio.h>
#include <string.h>
int n,m,i,j,r,cur;
char s[2020],t[2020];
int main() {
  scanf("%s",s); n=strlen(s);
  scanf("%s",t); r=m=strlen(t);
  for (i=-m; i<n; i++) {
    cur=m;
    for (j=0; j<m; j++) if (i+j>=0 && i+j<n && s[i+j]==t[j]) cur--;
    if (cur<r) r=cur;
  }
  printf("%d\n",r);
  return 0;
}