#include <stdio.h>
int n,l,cx,cy,cz,ce,i,wz,we,a[100100];
long long x,y;
bool qx,qy,qz,qe;
int main() {
  scanf("%d%d%d%d",&n,&l,&x,&y);
  for (cx=cy=cz=ce=i=0; i<n; i++) {
    scanf("%d",&a[i]);
    while (cx<=i && a[cx]<a[i]-x) cx++;
    if (cx<=i && a[cx]==a[i]-x) qx=true;
    while (cy<=i && a[cy]<a[i]-y) cy++;
    if (cy<=i && a[cy]==a[i]-y) qy=true;
    while (cz<=i && a[cz]<a[i]-x-y) cz++;
    if (cz<=i && a[cz]==a[i]-x-y) { qz=true; wz=i; }
    while (ce<=i && a[ce]<a[i]-y+x) ce++;
    if (ce<=i && a[ce]==a[i]-y+x) {
      if (a[ce]>=x) { qe=true; we=a[i]-y; }
      if (l-a[i]>=x) { qe=true; we=a[i]+x; }
    }
  }
  if (!qx && !qy && qz) {
    printf("1\n%d\n",a[wz]-x);
    return 0;
  }
  if (!qx && !qy && qe) {
    printf("1\n%d\n",we);
    return 0;
  }
  printf("%d\n",int(!qx)+int(!qy));
  if (!qx) printf("%d ",x);
  if (!qy) printf("%d ",y);
  return 0;
}