#include <stdio.h>
long long l,r,st[22];
int i,n,a[22];
long long solve(long long x) {
  if (x<10) return x;
  for (n=0; x>0; n++, x/=10) a[n]=x%10;
  long long r=9,c=0;
  for (i=2; i<n; i++) r+=st[i-2]*9;
  for (i=1; i<a[n-1]; i++) r+=st[n-2];
  for (i=n-2; i>=0; i--) c=c*10+a[i];
  r+=c/10;
  if (a[0]>=a[n-1]) r++;
  return r;
}
int main() {
  for (st[0]=i=1; i<=18; i++) st[i]=st[i-1]*10;
  scanf("%I64d%I64d",&l,&r);
  printf("%I64d\n",solve(r)-solve(l-1));
  return 0;
}