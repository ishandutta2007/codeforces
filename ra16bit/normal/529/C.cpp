#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
const int inf=2000000000;
int w,h,n,m,i,xx,xv,b[1100100],c[200200];
pii a[200200],x[200200],y[200200];
bool r[200200];
void setpos(int i, int L, int R) {
  if (L==R) b[i]=xv;
  if (L>=R) return;
  int h=(L+R)/2;
  if (xx<=h) setpos(i*2,L,h); else setpos(i*2+1,h+1,R);
  b[i]=min(b[i*2],b[i*2+1]);
}
void findmin(int i, int L, int R, int l, int r) {
  if (L>R) return;
  if (L==l && R==r) {
    xv=min(xv,b[i]);
    return;
  }
  int h=(L+R)/2;
  if (l<=h) findmin(i*2,L,h,l,min(r,h));
  if (r>h) findmin(i*2+1,h+1,R,max(l,h+1),r);
}
void solve() {
  int i=0,j=0;
  for (; i<m; i++) {
    int cur=c[i];
    for (; j<n && a[j].first<=x[cur].first; j++) {
      xx=a[j].second;
      xv=a[j].first;
      setpos(1,1,300000);
    }
    if (r[cur]==false) {
      xv=inf;
      findmin(1,1,300000,y[cur].second,y[cur].first);
      if (xv>=x[cur].second) r[cur]=true;
    }
  }
}
bool cmp(int i, int j) {
  return x[i]<x[j];
}
int main() {
  scanf("%d%d%d%d",&w,&h,&n,&m);
  for (i=0; i<n; i++) scanf("%d%d",&a[i].first,&a[i].second);
  sort(a,a+n);
  for (i=0; i<m; i++) {
    scanf("%d%d%d%d",&x[i].second,&y[i].second,&x[i].first,&y[i].first);
    c[i]=i;
  }
  sort(c,c+m,cmp);
  solve();
  memset(b,0,sizeof(b));
  for (i=0; i<n; i++) swap(a[i].first,a[i].second);
  sort(a,a+n);
  for (i=0; i<m; i++) swap(x[i],y[i]);
  sort(c,c+m,cmp);
  solve();
  for (i=0; i<m; i++) puts(r[i]?"YES":"NO");
  return 0;
}