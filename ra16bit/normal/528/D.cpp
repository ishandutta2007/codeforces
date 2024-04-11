#include <bits/stdc++.h>
using namespace std;
typedef complex<double> base;
const double pi=acos(-1.);
const char c[4]={'A','C','G','T'};
const int MX=200200;
int n,m,x,i,j,ch,pn,cnt;
pair<int,int> pos[MX*2];
vector<int> r;
char s[MX],t[MX];
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
//    for (i=0; i<a.size(); i++) cout << a[i] << ' ' ; cout << " <-A\n";
  fft(a,false);
//    for (i=0; i<a.size(); i++) cout << a[i] << ' ' ; cout << " <-A\n";
//    for (i=0; i<b.size(); i++) cout << b[i] << ' ' ; cout << " <-B\n";
  fft(b,false);
//    for (i=0; i<b.size(); i++) cout << b[i] << ' ' ; cout << " <-B\n";
  for (int i=0; i<n; i++) a[i]*=b[i];
//  puts("solve inv");
  fft(a,true);
  for (int i=0; i<n; i++) r[i]+=int(a[i].real()+0.5);
//  return r;
}
int main() {
  scanf("%d%d%d",&n,&m,&x);
  scanf("%s",s);
  scanf("%s",t);
  for (ch=0; ch<4; ch++) {
//    printf("%c:\n",c[ch]);
    vector<base> a(n),b(m);
    for (pn=i=0; i<n; i++) if (s[i]==c[ch]) {
      pos[pn++]={i-x,1};
      pos[pn++]={i+x+1,-1};
    }
    sort(pos,pos+pn);
    for (cnt=i=j=0; i<n; i++) {
      for (; j<pn && pos[j].first<=i; j++) cnt+=pos[j].second;
      a[i]=int(cnt>0);
//      printf("%d ",int(cnt>0));
    }
//    puts(" <-a");
    for (i=0; i<m; i++) {
    b[i]=int(t[m-i-1]==c[ch]);
//    printf("%d ",int(t[m-i-1]==c[ch]));
    }
//    puts(" <-b");
    //vector<int> r=
    mul(a,b);
//    for (i=0; i<r.size(); i++) printf("%d ",r[i]);
//    puts("");
  }
  for (cnt=i=0; i<n; i++) if (r[i]==m) cnt++;
  printf("%d\n",cnt);
  return 0;
}