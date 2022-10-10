#include <bits/stdc++.h>
using namespace std;
typedef complex<double> base;
const double pi=acos(-1.);
const int MX=500500;
int t,n,i,j,z[MX];
char s[MX];
vector<base> a,b;
vector<int> r,ans;
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
//vector<int>
void mul(vector<base>& a, vector<base>& b) {
  int n;
  for (n=1; n<a.size() || n<b.size(); n*=2);
  n*=2;
  a.resize(n);
  b.resize(n);
  r.resize(n);
  fft(a,false);
  fft(b,false);
  for (int i=0; i<n; i++) a[i]*=b[i];
  fft(a,true);
  for (int i=0; i<n; i++) r[i]=int(a[i].real()+0.5);
//  return r;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%s",s);
    a.resize(n);
    b.resize(n);
    for (i=0; i<n; i++) a[i]=int(s[i]=='V');
    for (i=0; i<n; i++) b[i]=int(s[n-i-1]=='K');
    mul(a,b);
    for (i=1; i<n; i++) z[i]=r[n-1-i]+r[n-1+i];
    ans.clear();
    for (i=1; i<n; i++) if (z[i]==0) {
      for (j=i+i; j<n; j+=i) if (z[j]>0) break;
      if (j>=n) ans.push_back(i);
    }
    printf("%d\n",int(ans.size())+1);
    for (i=0; i<ans.size(); i++) printf("%d ",ans[i]);
    printf("%d\n",n);
  }
  return 0;
}