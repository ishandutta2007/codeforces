#include <stdio.h>
int a[110000],s,i,n,l,c;
long long r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&a[i]); s+=a[i]; }
  if (s%3!=0) { puts("0"); return 0; } else s/=3;
  for (i=0; i<n-1; i++) {
    c+=a[i];
    if (c==2*s) r+=l;
    if (c==s) l++;
  }
  printf("%I64d\n",r);
  return 0;
}