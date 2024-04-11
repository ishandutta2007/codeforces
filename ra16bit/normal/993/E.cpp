#include <bits/stdc++.h>
using namespace std;
typedef complex<double> base;
const double pi=acos(-1.);
const int MX=200200;
int n,x,i,l,cnt,cn,cm,z[MX];
vector<base> a,b;
long long r[MX];
void fft(vector<base>& a, bool inv) {
  int n=a.size();
  if (n==1) return;
  for (int i=1, rv=0; i<n; i++) {
    int j=n/2;
    for (; rv>=j; j/=2) rv-=j;
    rv+=j;
    if (i<rv) swap(a[i],a[rv]);
  }
  for (int l=2; l<=n; l*=2) {
    double alpha=2*pi/l;
    if (inv) alpha=-alpha;
    for (int i=0; i<n; i+=l) {
      base w(1), wn(cos(alpha),sin(alpha));
      for (int j=0; j<l/2; j++) {
        base x=a[i+j];
        base y=w*a[i+j+l/2];
        a[i+j]=x+y;
        a[i+j+l/2]=x-y;
        w*=wn;
      }
    }
  }
  if (inv) for (int i=0; i<n; i++) a[i]/=n;
}
void mul(vector<base>& a, vector<base>& b) {
  int n;
  for (n=1; n<a.size() || n<b.size(); n*=2);
  n*=2;
  a.resize(n);
  b.resize(n);
  fft(a,false);
  fft(b,false);
  for (int i=0; i<n; i++) a[i]*=b[i];
  fft(a,true);
  for (int i=0; i<cnt; i++) {
    r[cnt-i]=(long long)(a[i].real()+0.5);
    r[0]-=r[cnt-i];
  }
}
int main() {
  scanf("%d%d",&n,&x);
  r[0]=(n*(n+1LL))/2LL;
  for (i=0; i<n; i++) {
    scanf("%d",&z[i]);
    if (z[i]<x) cnt++;
  }
  if (cnt==0) {
    for (i=0; i<=n; i++) printf("%I64d ",r[i]);
    return 0;
  }
  a.resize(cnt);
  b.resize(cnt);
  for (l=-1, i=0; i<n; i++) if (z[i]<x) {
    a[cn++]=i-l;
    l=i;
  }
  for (l=n, i=n-1; i>=0; i--) if (z[i]<x) {
    b[cm++]=l-i;
    l=i;
  }
  mul(a,b);
  for (i=0; i<=n; i++) printf("%I64d ",r[i]);
  return 0;
}