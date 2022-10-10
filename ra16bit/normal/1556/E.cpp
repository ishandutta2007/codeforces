#include <bits/stdc++.h>
using namespace std;
const int MX=140140;
struct Node {
  long long pb,nb,pe,ne;
} b[MX*2],r;
int n,q,i,x,y,a[MX];
void init(int i, int L, int R) {
  if (L==R) {
    if (a[R]>0) b[i].pb=b[i].pe=a[R];
    if (a[R]<0) b[i].nb=b[i].ne=-a[R];
    return;
  }
  int mid=(L+R)/2;
  init(i*2,L,mid);
  init(i*2+1,mid+1,R);
  b[i].pb=b[i*2].pb;
  b[i].pe=b[i*2].pe;
  b[i].nb=b[i*2].nb;
  b[i].ne=b[i*2].ne;
  long long nxt=b[i*2+1].pb;
  if (nxt>0) {
    long long cur=min(nxt,b[i].ne);
    b[i].ne-=cur;
    b[i].pb+=nxt-cur;
  }
  nxt=b[i*2+1].nb;
  if (nxt>0) {
    long long cur=min(nxt,b[i].pe);
    b[i].pe-=cur;
    b[i].nb+=nxt-cur;
  }
  b[i].pe+=b[i*2+1].pe;
  b[i].ne+=b[i*2+1].ne;
}
Node fnd(int i, int L, int R, int le, int ri) {
  if (L==le && R==ri) return b[i];
  int mid=(L+R)/2;
  if (le<=mid) {
    if (ri<=mid) return fnd(i*2,L,mid,le,ri);
    Node x=fnd(i*2,L,mid,le,mid);
    Node y=fnd(i*2+1,mid+1,R,mid+1,ri);
    long long nxt=y.pb;
    if (nxt>0) {
      long long cur=min(nxt,x.ne);
      x.ne-=cur;
      x.pb+=nxt-cur;
    }
    nxt=y.nb;
    if (nxt>0) {
      long long cur=min(nxt,x.pe);
      x.pe-=cur;
      x.nb+=nxt-cur;
    }
    x.pe+=y.pe;
    x.ne+=y.ne;
    return x;
  }
  return fnd(i*2+1,mid+1,R,le,ri);
}
int main() {
  scanf("%d%d",&n,&q);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=1; i<=n; i++) { scanf("%d",&x); a[i]-=x; }
  //for (i=1; i<=n; i++) printf("%d ",a[i]);
  init(1,1,n);
  while (q--) {
    scanf("%d%d",&x,&y);
    r=fnd(1,1,n,x,y);
    if (r.nb==r.pe && r.pb==0 && r.ne==0) printf("%lld\n",r.nb); else puts("-1");
  }
  return 0;
}