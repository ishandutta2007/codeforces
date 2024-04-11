#include <stdio.h>
int i,j,n,a[1111];
char s[1111];
int main() {
  scanf("%d",&n); scanf("%s",s); a[0]=1;
  for (i=1; i<n; i++) {
    if (s[i-1]=='L') a[i]=1; else if (s[i-1]=='R') a[i]=a[i-1]+1; else a[i]=a[i-1];
    for (j=i-1; j>=0; j--) {
      if (s[j]=='L' && a[j]<=a[j+1]) a[j]++;
      if (s[j]=='=' && a[j]!=a[j+1]) a[j]++;
    }
  }
  for (i=0; i<n; i++) {
    printf("%d",a[i]);
    if (i==n-1) putchar('\n'); else putchar(' ');
  }
  return 0;
}