#include <stdio.h>
int i,c,n;
bool a[1111];
int main() {
  scanf("%d",&n);
  for (i=c=0; i<=2000000; i++) {
    c=(c+i)%n;
    a[c]=true;
  }
  for (i=0; i<n; i++) if (!a[i]) { puts("NO"); return 0; }
  puts("YES");
  return 0;
}