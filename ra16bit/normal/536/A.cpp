#include <stdio.h>
int a,b,n,st,t,m;
long long l,r,h,mx,fi,la,s;
int main() {
  scanf("%d%d%d",&a,&b,&n);
  while (n--) {
    scanf("%d%d%d",&st,&t,&m);
    l=--st; r=t+1;
    mx=t; mx*=m;
    fi=a+b*l;
    while (l<r) {
      h=(l+r)/2;
      la=a+b*h;
      s=((fi+la)*(h-st+1LL))/2;
      if (la>t || s>mx) r=h; else l=h+1;
    }
    printf("%I64d\n",r<=st?-1LL:r);
  }
  return 0;
}