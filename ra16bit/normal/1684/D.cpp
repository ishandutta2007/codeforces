#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> pii;
const long long inf=10000000000000000LL;
const int MX=270100;
struct Node {
  long long v;
  int w,add;
} b[MX*2];
int t,n,m,i,a[MX];
long long res;
void updv(int i) {
  b[i].v=min(b[i*2].v,b[i*2+1].v);
  if (b[i].v==b[i*2].v) b[i].w=b[i*2].w; else b[i].w=b[i*2+1].w;
  b[i].v+=b[i].add;
}
void init(int i, int L, int R) {
  b[i].add=0;
  if (L==R) {
    if (R<m) b[i].v=a[R]+m-R; else b[i].v=inf;
    b[i].w=R;
    return;
  }
  int mid=(L+R)/2;
  init(i*2,L,mid);
  init(i*2+1,mid+1,R);
  updv(i);
}
pii findmin(int i, int L, int R, int le, int ri) {
  if (L==le && R==ri) return {b[i].v,b[i].w};
  int mid=(L+R)/2;
  if (le<=mid) {
    if (ri<=mid) return findmin(i*2,L,mid,le,ri);
    pii best=min(findmin(i*2,L,mid,le,mid),findmin(i*2+1,mid+1,R,mid+1,ri));
    best.first+=b[i].add;
    return best;
  }
  return findmin(i*2+1,mid+1,R,le,ri);
}
void setv(int i, int L, int R, int pos, long long v) {
  if (L==R) {
    b[i].v=v;
    return;
  }
  int mid=(L+R)/2;
  v-=b[i].add;
  if (pos<=mid) setv(i*2,L,mid,pos,v); else setv(i*2+1,mid+1,R,pos,v);
  updv(i);
}
void addone(int i, int L, int R, int le, int ri) {
  if (L==le && R==ri) {
    ++b[i].v;
    ++b[i].add;
    return;
  }
  int mid=(L+R)/2;
  if (le<=mid) addone(i*2,L,mid,le,min(ri,mid));
  if (ri>mid) addone(i*2+1,mid+1,R,max(mid+1,le),ri);
  updv(i);
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    reverse(a,a+n);
    init(1,0,n-1);
    res=0;
    for (i=m; i<n; i++) {
      pii best=findmin(1,0,n-1,0,i-1);
      if (best.first<a[i]) {
        res+=best.first;
        setv(1,0,n-1,best.second,inf);
        setv(1,0,n-1,i,a[i]);
        addone(1,0,n-1,0,i);
      } else {
        res+=a[i];
        addone(1,0,n-1,0,i-1);
      }
    }
    printf("%lld\n",res);
  }
  return 0;
}