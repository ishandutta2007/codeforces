#include <stdio.h>
int n,q,l,r,x,y,z,i,old;
long long a[100100],s[100100];
void add(int i, long long x) {
  a[i]+=x;
  for (int j=i; j<=n; j=(j<<1)-(j&(j-1))) s[j]+=x;
}
long long fs(int i) {
  long long r=0;
  for (; i>0; i&=i-1) r+=s[i];
  return r;
}
int main() {
  scanf("%d%d",&n,&q);
  l=1; r=n;
  for (i=1; i<=n; i++) add(i,1);
  while (q--) {
    scanf("%d%d",&x,&y);
    if (x==1) {
      if (l<=r) {
        if (y<=r-(l+y-1)) {
          old=l;
          l+=y;
          for (i=l-1; i>=old; i--) add(l-1+l-i,a[i]);
        } else {
          old=r;
          r=l;
          l=l+y-1;
          for (i=l+1; i<=old; i++) add(l-(i-l)+1,a[i]);
        }
      } else {
        if (y<=l-y-r+1) {
          old=l;
          l-=y;
          for (i=l+1; i<=old; i++) add(l-(i-l)+1,a[i]);
        } else {
          old=r;
          r=l;
          l=l-y+1;
          for (i=l-1; i>=old; i--) add(l-1+l-i,a[i]);
        }
      }
    } else {
      scanf("%d",&z);
      if (l<=r) printf("%I64d\n",fs(l+z-1)-fs(l+y-1));
           else printf("%I64d\n",fs(l-y)-fs(l-z));
    }
  }
  return 0;
}