#include <stdio.h>
int i,p;
long long n,k,l,r,h,x;
int main() {
  scanf("%I64d%I64d%d",&n,&k,&p);
  if (k>1 && k<n) {
    if (k*2>n+1) {
      l=0; r=n/2;
      while (l<r) {
        h=(l+r)/2+1;
        if (n-h<k) r=h-1; else l=h;
      }
      l=0; r+=r;
    } else {
      r=n-(n&1);
      l=r-2*(k-(n&1));
    }
  }
  for (i=0; i<p; i++) {
    scanf("%I64d",&x); x--;
    if (k<2 || k==n) putchar((k==n || (k==1 && n-1==x))?'X':'.'); else
      if (x<l) putchar('.'); else if (x<r) putchar(((x&1)!=(l&1))?'X':'.'); else putchar('X');
  }
  return 0;
}