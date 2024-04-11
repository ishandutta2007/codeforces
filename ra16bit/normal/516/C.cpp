#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const pli infp=make_pair(-1000000000000000000LL,0);
int n,m,i,d,l,r;
ll a[200200],b[200200];
pli la[200200],ra[200200],lb[200200],rb[200200];
pli mx(ll* v, pli* lv, pli* rv, int l, int r) {
  pli res=infp;
  int j,x;
  for (j=l; ; j=x) {
    x=(j<<1)-(j&(j-1));
    if (x>r) break;
    res=max(res,rv[j]);
  }
  res=max(res,make_pair(v[j],j));
  for (j=r; ; j=x) {
    x=(j&(j-1));
    if (x<l) break;
    res=max(res,lv[j]);
  }
  res=max(res,make_pair(v[j],j));
  return res;
}
ll solve(int l, int r) {
  pli mx1=mx(a,la,ra,l,r);
  pli mx2=mx(b,lb,rb,l,r);
  if (mx1.second!=mx2.second) return mx1.first+mx2.first;
  pli mx1a=(mx1.second==l)?infp:mx(a,la,ra,l,mx1.second-1);
  mx1a=max(mx1a,(mx1.second==r)?infp:mx(a,la,ra,mx1.second+1,r));
  pli mx2a=(mx2.second==l)?infp:mx(b,lb,rb,l,mx2.second-1);
  mx2a=max(mx2a,(mx2.second==r)?infp:mx(b,lb,rb,mx2.second+1,r));
  return max(mx1.first+mx2a.first,mx1a.first+mx2.first);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%d",&d);
    a[i+1]=d; a[i+n+1]=d;
  }
  for (i=1; i<=2*n; i++) {
    a[i]+=a[i-1];
    b[i]=-a[i];
  }
  for (i=1; i<=n; i++) {
    scanf("%d",&d);
    d*=2;
    a[i]+=d; a[i+n]+=d;
    b[i]+=d; b[i+n]+=d;
  }
  for (i=1; i<=2*n; i++) {
    la[i]=infp; ra[i]=infp;
    lb[i]=infp; rb[i]=infp;
  }
  for (i=1; i<=2*n; i++) {
    for (int j=i; j<=2*n; j=(j<<1)-(j&(j-1))) {
      la[j]=max(la[j],make_pair(a[i],i));
      lb[j]=max(lb[j],make_pair(b[i],i));
    }
    for (int j=i; j>0; j&=j-1) {
      ra[j]=max(ra[j],make_pair(a[i],i));
      rb[j]=max(rb[j],make_pair(b[i],i));
    }
  }
  while (m--) {
    scanf("%d%d",&l,&r);
    printf("%I64d\n",(r<l)?solve(r+1,l-1):solve(r+1,l+n-1));
  }
  return 0;
}