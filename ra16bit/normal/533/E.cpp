#include <stdio.h>
int n,i,j,k,r;
char s[100100],t[100100];
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  scanf("%s",t);
  for (i=0; i<n; i++) if (s[i]!=t[i]) break;
  for (j=n-1; j>=0; j--) if (s[j]!=t[j]) break;
  if (i<j) {
    for (k=i; k<j; k++) if (s[k]!=t[k+1]) break;
    if (k>=j) r++;
    for (k=i; k<j; k++) if (t[k]!=s[k+1]) break;
    if (k>=j) r++;
  } else r=2;
  printf("%d\n",r);
  return 0;
}