#include <stdio.h>
int i,n,a[100010],b[100010],c[100010];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    b[a[i]]++;
  }
  for (i=1; i<100010; i++) {
    if (b[i]<b[i+1]) { puts("-1"); return 0; }
    c[i]=1;
  }
  printf("%d\n",b[1]);
  for (i=0; i<n; i++) {
    if (i) putchar(' ');
    printf("%d",c[a[i]]++);
  }
  return 0;
}