#include <bits/stdc++.h>
using namespace std;
const int MX=200200,md=998244353;
int n,i,bw,wb,ww,bb,lw,rw,lb,rb,oth,res,pos,d;
long long f[MX],o[MX];
bool abw,awb;
char st[5];
string s;
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
int main() {
  for (f[0]=o[0]=i=1; i<MX; i++) {
    f[i]=(f[i-1]*i)%md;
    o[i]=pw(f[i],md-2);
  }
  scanf("%d",&n);
  awb=abw=true;
  for (i=0; i<n; i++) {
    scanf("%s",st);
    s=st;
    if (s=="BW") {
      ++bw;
      awb=false;
    } else if (s=="WB") {
      ++wb;
      abw=false;
    } else if (s=="WW") {
      ++ww;
      awb=abw=false;
    } else if (s=="BB") {
      ++bb;
      awb=abw=false;
    } else if (s=="?W") {
      ++rw;
      awb=false;
    } else if (s=="?B") {
      ++rb;
      abw=false;
    } else if (s=="W?") {
      ++lw;
      abw=false;
    } else if (s=="B?") {
      ++lb;
      awb=false;
    } else ++oth;
  }
  pos=rw+rb+lw+lb+oth*2;
  d=(ww-bb)*2+lw+rw-lb-rb;
  if (d<0) d=-d;
  if (pos>=d && (pos-d)%2==0) {
    if (abw) ++res;
    if (awb) ++res;
    d=(pos-d)/2;
    res=(res+((f[pos]*o[d])%md)*o[pos-d])%md;
    if (ww==0 && bb==0) res=(res+md-pw(2,oth))%md;
  }
  printf("%d\n",res);
  return 0;
}