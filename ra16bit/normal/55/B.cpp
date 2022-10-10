#include <stdio.h>
int a,b,c,d,i;
char s[5];
long long r=-1;
void rec(int l, long long a, long long b, long long c, long long d) {
  if (l==3) {
    if (r==-1 || a<r) r=a;
    return;
  }
  if (s[l]=='+') {
    rec(l+1,a+b,c,d,0);
    if (l<2) {
      rec(l+1,a+c,b,d,0);
      rec(l+1,a,b+c,d,0);
    }
    if (l==0) {
      rec(l+1,a+d,b,c,0);
      rec(l+1,a,b+d,c,0);
      rec(l+1,a,b,c+d,0);
    }
  } else {
    rec(l+1,a*b,c,d,0);
    if (l<2) {
      rec(l+1,a*c,b,d,0);
      rec(l+1,a,b*c,d,0);
    }
    if (l==0) {
      rec(l+1,a*d,b,c,0);
      rec(l+1,a,b*d,c,0);
      rec(l+1,a,b,c*d,0);
    }
  }
}
int main() {
  scanf("%d%d%d%d",&a,&b,&c,&d);
  for (i=0; i<3; i++) {
    s[i]=getchar();
    while (s[i]!='+' && s[i]!='*') s[i]=getchar();
  }
  rec(0,a,b,c,d);
  printf("%I64d\n",r);
  return 0;
}