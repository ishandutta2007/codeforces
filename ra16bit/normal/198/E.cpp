#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int inf=2000000000,MX=250250;
struct Ship { LL d,r; int m,p; } a[MX];
pair<LL,int> b[MX],q[MX];
pii mini,c[4*MX];
int i,x,y,X,Y,P,n,fi,fr;
LL D,R;
LL sqr(LL x) { return x*x; }
void init(int i, int l, int r) {
  if (l==r) {
    c[i]=make_pair(a[b[l].second].m,l);
    return;
  }
  int h=(l+r)/2;
  init(i*2,l,h);
  init(i*2+1,h+1,r);
  c[i]=min(c[i*2],c[i*2+1]);
}
pii findmin(int i, int L, int R, int l, int r) {
  if (l==L && r==R) return c[i];
  int h=(L+R)/2;
  if (r<=h) return findmin(i*2,L,h,l,r);
  if (l>h) return findmin(i*2+1,h+1,R,l,r);
  return min(findmin(i*2,L,h,l,h),findmin(i*2+1,h+1,R,h+1,r));
}
void destroy(int i, int l, int r, int x) {
  if (l==r) { c[i]=make_pair(inf,i); return; }
  int h=(l+r)/2;
  if (x<=h) destroy(i*2,l,h,x); else destroy(i*2+1,h+1,r,x);
  c[i]=min(c[i*2],c[i*2+1]);
}
int main() {
  scanf("%d%d%d%I64d%d",&X,&Y,&P,&R,&n);
  R=sqr(R);
  for (i=0; i<n; i++) {
    scanf("%d%d%d%d%I64d",&x,&y,&a[i].m,&a[i].p,&a[i].r);
    a[i].d=sqr(x-X)+sqr(y-Y);
    a[i].r=sqr(a[i].r);
    b[i]=make_pair(a[i].d,i);
  }
  sort(b,b+n);
  init(1,0,n-1);
  for (q[fi=0]=make_pair(R,P), fr=1; fi<fr; fi++) {
    y=upper_bound(b,b+n,make_pair(q[fi].first+1,0))-b-1;
    while (y>=0) {
      mini=findmin(1,0,n-1,0,y);
      if (mini.first>q[fi].second) break;
      destroy(1,0,n-1,mini.second);
      i=b[mini.second].second;
      q[fr++]=make_pair(a[i].r,a[i].p);
    }
  }
  printf("%d\n",fr-1);
  return 0;
}