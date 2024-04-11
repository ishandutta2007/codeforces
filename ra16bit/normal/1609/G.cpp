#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;
const int MX=144144;
struct Node {
  long long s,z,f,a;
} v[2*MX];
int n,m,q,i,tp,cnt,tot,pos,prv,d;
long long a[111],b[MX],res;
long long sm(long long x, long long cnt) {
  return ((cnt*(cnt+1LL))/2)*x;
}
void recalc(int i, int cntr) {
  v[i].f=v[i*2+1].f;
  v[i].s=v[i*2].s+v[i*2+1].s;
  v[i].z=v[i*2].s*cntr+v[i*2].z+v[i*2+1].z;
}
void init(int i, int L, int R) {
  if (L==R) {
    v[i].f=b[R];
    v[i].s=b[R];
    v[i].z=b[R];
    return;
  }
  int mid=(L+R)/2;
  init(i*2,L,mid);
  init(i*2+1,mid+1,R);
  recalc(i,R-mid);
}
void upd(int i, long long d, int len) {
  v[i].a+=d;
  v[i].f+=d;
  v[i].s+=d*len;
  v[i].z+=sm(d,len);
}
void push(int i, int L, int R, int mid) {
  upd(i*2,v[i].a,mid-L+1);
  upd(i*2+1,v[i].a,R-mid);
  v[i].a=0;
}
void mdf(int i, int L, int R, int lim, int d) {
  if (L>lim) {
    upd(i,d,R-L+1);
    return;
  }
  int mid=(L+R)/2;
  if (v[i].a) push(i,L,R,mid);
  if (mid>lim) mdf(i*2,L,mid,lim,d);
  mdf(i*2+1,mid+1,R,lim,d);
  recalc(i,R-mid);
}
int fnd(int i, int L, int R, long long val) {
  if (L==R) return R;
  int mid=(L+R)/2;
  if (v[i].a) push(i,L,R,mid);
  if (v[i*2].f>val) return fnd(i*2,L,mid,val);
  return fnd(i*2+1,mid+1,R,val);
}
pll fndsums(int i, int L, int R, int lft, int rgh) {
  if (L==lft && R==rgh) return make_pair(v[i].s,v[i].z);
  int mid=(L+R)/2;
  if (v[i].a) push(i,L,R,mid);
  if (lft<=mid) {
    if (rgh<=mid) return fndsums(i*2,L,mid,lft,rgh);
    pll p=fndsums(i*2,L,mid,lft,mid);
    pll q=fndsums(i*2+1,mid+1,R,mid+1,rgh);
    p.second+=p.first*(rgh-mid);
    p.second+=q.second;
    p.first+=q.first;
    return p;
  }
  return fndsums(i*2+1,mid+1,R,lft,rgh);
}
int main() {
  scanf("%d%d%d",&n,&m,&q);
  for (i=1; i<=n; i++) scanf("%lld",&a[i]);
  for (i=n; i>=1; i--) a[i]-=a[i-1];
  for (i=1; i<=m; i++) scanf("%lld",&b[i]);
  for (i=m; i>=1; i--) b[i]-=b[i-1];
  init(1,1,m);
  while (q--) {
    scanf("%d%d%d",&tp,&cnt,&d);
    if (tp==1) {
      for (i=0; i<cnt; i++) a[n-i]+=d;
    } else {
      mdf(1,1,m,m-cnt,d);
      if (cnt==m) b[1]+=d;
    }
    res=(a[1]+b[1])*(n+m-1LL);
    prv=1;
    tot=n+m-2;
    for (i=2; i<=n; i++) {
      if (prv<m) {
        if (v[1].f<=a[i]) pos=m; else pos=fnd(1,1,m,a[i])-1;
        if (pos>prv) {
          pll p=fndsums(1,1,m,prv+1,pos);
          tot-=pos-prv;
          res+=p.second+p.first*tot;
          prv=pos;
        }
      }
      res+=a[i]*tot;
      --tot;
    }
    if (prv<m) {
      pll p=fndsums(1,1,m,prv+1,m);
      res+=p.second;
    }
    printf("%lld\n",res);
  }
  return 0;
}