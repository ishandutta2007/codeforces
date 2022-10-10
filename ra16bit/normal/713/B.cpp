#include <bits/stdc++.h>
using namespace std;
int n,l,r,h,c,xa,ya,xb,yb,xa2,ya2,xb2,yb2;
int print(int xa, int ya, int xb, int yb) {
  printf("? %d %d %d %d\n",xa,ya,xb,yb);
  fflush(stdout);
  int r;
  scanf("%d",&r);
  return r;
}
int print2(int _xa, int _ya, int _xb, int _yb) {
  int r=print(_xa,_ya,_xb,_yb);
  if (xa>=_xa && xb<=_xb && ya>=_ya && yb<=_yb) r--;
  return r;
}
int main() {
  scanf("%d",&n);
  l=1; r=n;
  while (l<r) {
    h=(l+r)/2;
    c=print(1,1,n,h);
    if (c==0) l=h+1; else r=h;
  }
  yb=r; l=1; r=n;
  while (l<r) {
    h=(l+r)/2;
    c=print(1,1,h,yb);
    if (c==0) l=h+1; else r=h;
  }
  xb=r; l=1; r=yb;
  while (l<r) {
    h=(l+r)/2+1;
    c=print(1,h,xb,yb);
    if (c==0) r=h-1; else l=h;
  }
  ya=r; l=1; r=xb;
  while (l<r) {
    h=(l+r)/2+1;
    c=print(h,ya,xb,yb);
    if (c==0) r=h-1; else l=h;
  }
  xa=r; l=1; r=n;
  while (l<r) {
    h=(l+r)/2;
    c=print2(1,1,n,h);
    if (c==0) l=h+1; else r=h;
  }
  yb2=r; l=1; r=n;
  while (l<r) {
    h=(l+r)/2;
    c=print2(1,1,h,yb2);
    if (c==0) l=h+1; else r=h;
  }
  xb2=r; l=1; r=yb2;
  while (l<r) {
    h=(l+r)/2+1;
    c=print2(1,h,xb2,yb2);
    if (c==0) r=h-1; else l=h;
  }
  ya2=r; l=1; r=xb2;
  while (l<r) {
    h=(l+r)/2+1;
    c=print2(h,ya2,xb2,yb2);
    if (c==0) r=h-1; else l=h;
  }
  xa2=r;
  printf("! %d %d %d %d %d %d %d %d\n",xa,ya,xb,yb,xa2,ya2,xb2,yb2);
  fflush(stdout);
  return 0;
}