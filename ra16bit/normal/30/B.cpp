#include <stdio.h>
const int d[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int a[3],b[3],p[3];
bool u[3],q;
bool valid(int dd, int mm, int yy) {
  if (yy%4==0 && mm==2) return (dd>=1 && dd<=29);
  if (mm<1 || mm>12) return false;
  return (dd>=1 && dd<=d[mm-1]);
}
bool less(int dd, int mm, int yy) {
  if (yy!=b[2]) return (yy<b[2]);
  if (mm!=b[1]) return (mm<b[1]);
  return (dd<=b[0]);
}
void rec(int l) {
  if (l==3) {
    if (valid(a[p[0]],a[p[1]],a[p[2]])) q|=less(a[p[0]],a[p[1]],a[p[2]]+18);
    return;
  }
  for (int i=0; i<3; i++) if (!u[i]) {
    p[l]=i; u[i]=true; rec(l+1); u[i]=false;
  }
}
int main() {
  scanf("%d.%d.%d",&b[0],&b[1],&b[2]);
  scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
  rec(0);
  if (q) puts("YES"); else puts("NO");
  return 0;
}