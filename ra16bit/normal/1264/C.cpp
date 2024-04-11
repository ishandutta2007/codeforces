#include <bits/stdc++.h>
using namespace std;
struct Fraq { long long p,q; } fraq,f[550550];
const int md=998244353;
int n,q,i,x,le,ri,r,a[200200],pw100[200200];
set<int> s;
set<int>::iterator it,jt;
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (a*pw(a,b-1))%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void init(int i, int L, int R) {
  if (L==R) {
    f[i].p=100;
    f[i].q=a[L];
    //printf("%d..%d = %d/%d\n",L,R,int(f[i].p),int(f[i].q));
    return;
  }
  int h=(L+R)/2;
  init(i*2,L,h);
  init(i*2+1,h+1,R);
  Fraq ff=f[i*2],g=f[i*2+1];
  f[i].p=(pw100[R-h]*ff.p+ff.q*g.p)%md;
  f[i].q=(ff.q*g.q)%md;
  //printf("%d..%d = %d/%d\n",L,R,int(f[i].p),int(f[i].q));
}
Fraq calc(int i, int L, int R, int le, int ri) {
  if (le>ri) return {1,1};
  if (L==le && R==ri) return f[i];
  int h=(L+R)/2;
  if (ri<=h) return calc(i*2,L,h,le,ri);
  if (le>h) return calc(i*2+1,h+1,R,le,ri);
  Fraq f=calc(i*2,L,h,le,min(h,ri));
  Fraq g=calc(i*2+1,h+1,R,max(h+1,le),ri);
  f.p=(pw100[ri-h]*f.p+f.q*g.p)%md;
  f.q=(f.q*g.q)%md;
  return f;
}
int main() {
  scanf("%d%d",&n,&q);
  for (pw100[0]=i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    pw100[i]=(pw100[i-1]*100LL)%md;
  }
  init(1,1,n);
  r=(f[1].p*pw(f[1].q,md-2))%md;
  s.insert({1,r});
  s.insert({n+1,0});
  while (q--) {
    scanf("%d",&x);
    it=s.lower_bound(x);
    if (*it==x) {
      jt=it; --it; le=*it;
      fraq=calc(1,1,n,le,x-1);
      r=(r+md-(fraq.p*pw(fraq.q,md-2)%md))%md;
      it=jt; ++it; ri=*it;
      fraq=calc(1,1,n,x,ri-1);
      r=(r+md-(fraq.p*pw(fraq.q,md-2)%md))%md;
      s.erase(jt);
      fraq=calc(1,1,n,le,ri-1);
      r=(r+fraq.p*pw(fraq.q,md-2))%md;
    } else {
      ri=*it; --it; le=*it;
      fraq=calc(1,1,n,le,ri-1);
      r=(r+md-(fraq.p*pw(fraq.q,md-2)%md))%md;
      fraq=calc(1,1,n,le,x-1);
      r=(r+fraq.p*pw(fraq.q,md-2))%md;
      fraq=calc(1,1,n,x,ri-1);
      r=(r+fraq.p*pw(fraq.q,md-2))%md;
      s.insert(x);
    }
    printf("%d\n",r);
  }
  return 0;
}