#include <stdio.h>
int n,m,i,j,r;
char s[1010][1010];
bool a[1010];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%s",s[i]);
    a[i]=true;
  }
  for (j=0; j<m; j++) {
    for (i=1; i<n; i++) if (a[i] && s[i-1][j]>s[i][j]) break;
    if (i>=n) {
      for (i=1; i<n; i++) if (a[i] && s[i-1][j]<s[i][j]) a[i]=false;
    } else r++;
  }
  printf("%d\n",r);
  return 0;
}