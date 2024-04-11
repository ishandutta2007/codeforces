#include <cstdio>
#include <algorithm>
using namespace std;
struct tube { int s,f,l,h,a; } a[22];
int n,m,i,x,b[7],c[7],r1,r2;
void rec(int l, int s) {
  if (l==m) {
    r1=x;
    if (s>r2) r2=s;
    return;
  }
  if (l==m-1 || a[l].s!=a[l+1].s) {
    int i=b[a[l].s]-c[a[l].s];
    if (i>=a[l].l && i<=a[l].h) {
      c[a[l].s]+=i; b[a[l].f]+=i;
      rec(l+1,s+i*i+((i==0)?0:a[l].a));
      c[a[l].s]-=i; b[a[l].f]-=i;
    }
  } else for (int i=a[l].l; i<=a[l].h; i++) {
    if (c[a[l].s]+i>b[a[l].s]) return;
    c[a[l].s]+=i; b[a[l].f]+=i;
    rec(l+1,s+i*i+((i==0)?0:a[l].a));
    c[a[l].s]-=i; b[a[l].f]-=i;
  }
}
bool cmp(tube x, tube y) { return (x.s<y.s || (x.s==y.s && x.f<y.f)); }
int main() {
  scanf("%d",&n); m=(n*(n-1))/2;
  for (i=0; i<m; i++) scanf("%d%d%d%d%d",&a[i].s,&a[i].f,&a[i].l,&a[i].h,&a[i].a);
  sort(a,a+m,cmp); r1=r2=-1;
  for (x=0; x<=25; x++) {
    b[1]=x; rec(0,0);
    if (r1!=-1) break;
  }
  printf("%d %d\n",r1,r2);
  return 0;
}