#include <cstdio>
#include <algorithm>
using namespace std;
int n,k,lx,ly,rx,ry,al,ar,bl,br,i,a[100100],inf=1000000000;
double r;
void rec(long long s) {
  if (s>inf) return;
  a[n++]=int(s);
  rec(s*10+4);
  rec(s*10+7);
}
double intersect(int l, int r, int x, int y) {
  l=max(x,l);
  r=min(y,r);
  int z=r-l+1;
  if (z<=0) return 0;
  return double(z)/(y-x+1.0);
}
double inside(int x, int l, int r) {
  if (x<l || x>r) return 0.0;
  return 1.0/(r-l+1.0);
}
int main() {
  scanf("%d%d%d%d%d",&al,&ar,&bl,&br,&k);
  rec(4); rec(7);
  sort(a,a+n);
  for (i=0; i+k<=n; i++) {
    lx=(i==0)?1:(a[i-1]+1); rx=a[i];
    ly=a[i+k-1]; ry=(i+k==n)?inf:(a[i+k]-1);
    r+=intersect(lx,rx,al,ar)*intersect(ly,ry,bl,br);
    r+=intersect(lx,rx,bl,br)*intersect(ly,ry,al,ar);
    if (k==1) r-=inside(a[i],al,ar)*inside(a[i],bl,br);
  }
  printf("%.11lf\n",r);
  return 0;
}