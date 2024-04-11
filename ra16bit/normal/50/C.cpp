#include <stdio.h>
int nx,mx,ny,my,na,ma,nb,mb,x,y,a,b,i,n,r;
void add(int x, int y) {
  a=x+y; b=x-y;
  if (x<nx) nx=x; if (x>mx) mx=x;
  if (y<ny) ny=y; if (y>my) my=y;
  if (a<na) na=a; if (a>ma) ma=a;
  if (b<nb) nb=b; if (b>mb) mb=b;
}
int main() {
  nx=ny=na=nb=+1000000000;
  mx=my=ma=mb=-1000000000;
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x,&y);
    add(x+1,y); add(x,y+1);
    add(x-1,y); add(x,y-1);
  }
  r=2*(mx-nx)+2*(my-ny);
  r-=na-nx-ny;
  r-=mx+my-ma;
  r-=nb-nx+my;
  r-=mx-ny-mb;
  printf("%d\n",r);
  return 0;
}