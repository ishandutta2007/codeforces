#include <stdio.h>
int n,i,a[200200],s[200200];
long long r;
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    s[i]=s[i-1]+a[i];
  }
  for (i=n; i>0; i--) if (a[i]==0) r+=s[i];
  printf("%I64d\n",r);
  return 0;
}