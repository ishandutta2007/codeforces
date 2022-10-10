#include <stdio.h>
#include <math.h>
int a,b,c2,i,j;
double d,e,f;
bool solve() {
  for (i=1; i*i<c2; i++) if (i!=a && i!=b) {
    d=sqrt(c2-i*i);
    if (int(d)==d) {
      for (j=1; j<i; j++) {
        e=sqrt(a*a-j*j);
        f=sqrt(b*b-(i-j)*(i-j));
        if (int(e)==e && int(f)==f) {
          if (j*j+int(d+f)*int(d+f)==a*a && int(f)*int(f)+(i-j)*(i-j)==b*b) {
            puts("YES");
            printf("%d %d\n",0,int(d));
            printf("%d %d\n",i,0);
            printf("%d %d\n",j,-int(f));
            return true;
          }
          if ((i-j)*(i-j)+int(d+e)*int(d+e)==b*b && int(e)*int(e)+j*j==a*a) {
            puts("YES");
            printf("%d %d\n",0,int(d));
            printf("%d %d\n",i,0);
            printf("%d %d\n",i-j,-int(e));
            return true;
          }
        }
      }
    }
  }
  return false;
}
int main() {
  scanf("%d%d",&a,&b);
  c2=a*a+b*b;
  if (solve()) return 0;
  i=a; a=b; b=i;
  if (solve()) return 0;
  puts("NO");
  return 0;
}