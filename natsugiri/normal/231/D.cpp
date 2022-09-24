#include<cstdio>
int x, y, z, x1, y1, z1;;
int a[6], r;
int main(){
    scanf("%d%d%d%d%d%d", &x, &y, &z, &x1, &y1, &z1);
    for (int i=0; i<6; i++) scanf("%d",  a+i);
    if (x<0) r+=a[4];
    if (x1<x) r+=a[5];
    if (y<0) r+=a[0];
    if (y1<y) r+=a[1];
    if (z<0) r+=a[2];
    if (z1<z) r+=a[3];
    printf("%d\n", r);
  return 0;
}