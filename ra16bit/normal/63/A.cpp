#include <stdio.h>
int n,i,j,a[111];
char s[111][22],t[11];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",s[i]);
    scanf("%s",t);
    if (t[0]=='c') {
       if (t[1]=='a') a[i]=3; else a[i]=1;
    } else if (t[0]=='w') a[i]=1; else if (t[0]=='m') a[i]=2;
  }
  for (j=0; j<4; j++) for (i=0; i<n; i++) if (a[i]==j) puts(s[i]);
  return 0;
}