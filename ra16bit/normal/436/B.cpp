#include <stdio.h>
int n,m,k,i,j,a[2020];
char s[2020];
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=0; i<n; i++) {
    scanf("%s",s);
    for (j=0; j<m; j++) if (s[j]=='U') {
      if (i%2==0) a[j]++;
    } else if (s[j]=='L') {
      if (j-i>=0) a[j-i]++;
    } else if (s[j]=='R') {
      if (j+i<m) a[j+i]++;
    }
  }
  for (i=0; i<m; i++) printf("%d%c",a[i],(i==m-1)?'\n':' ');
  return 0;
}