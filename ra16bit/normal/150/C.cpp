#include <cstdio>
#include <algorithm>
using namespace std;
struct Node { double s,b,l,r; } d[525525];
int N,n,m,c,x,y,i,a[200200],b[200200],p[200200];
double cur[200200],r;
Node merge(Node l, Node r) {
  Node b;
  b.s=l.s+r.s;
  b.b=max(l.r+r.l,max(l.b,r.b));
  b.l=max(l.l,l.s+r.l);
  b.r=max(r.r,r.s+l.r);
  return b;
}
void init(int i, int L, int R) {
  if (L<R) {
    int h=(L+R)/2;
    init(i*2,L,h);
    init(i*2+1,h+1,R);
    d[i]=merge(d[i*2],d[i*2+1]);
  } else {
    d[i].s=cur[L];
    d[i].b=d[i].l=d[i].r=max(0.0,d[i].s);
  }
}
Node best(int i, int L, int R, int l, int r) {
  if (L==l && R==r) return d[i];
  int h=(L+R)/2;
  if (r<=h) return best(i*2,L,h,l,r);
  if (l>h) return best(i*2+1,h+1,R,l,r);
  return merge(best(i*2,L,h,l,h),best(i*2+1,h+1,R,h+1,r));
}
int main() {
  scanf("%d%d%d",&n,&m,&c);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=1; i<n; i++) scanf("%d",&p[i]);
  for (i=1; i<n; i++) cur[i]=0.5*(a[i]-a[i-1])-0.01*p[i]*c;
  for (N=1; N<n; N*=2);
  init(1,1,N);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    double o=r;
    r+=best(1,1,N,x,y-1).b;
  }
  printf("%.8lf\n",r);
  return 0;
}