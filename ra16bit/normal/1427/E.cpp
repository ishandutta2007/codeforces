#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MX=100100;
int st,i,w,m,fr,ofr,zfr,ozfr;
long long mn,x,z,a[MX],b[MX],q[MX],qz[MX];
char r[MX];
long long gcd(long long a, long long b) { return b?gcd(b,a%b):a; }
void solve(long long z) {
  for (long long e=0; ; e++) if ((z-x*e)%st==0) {
    long long cur=(z+1-x*e)/st;
    //printf("cur=%d\n",int(cur));
    q[0]=st;
    for (i=1; (1LL<<i)<=cur; i++) {
      q[i]=q[i-1]*2;
      a[m]=b[m]=q[i-1];
      r[m++]='+';
    }
    fr=i;
    for (i=0; i<fr; i++) if ((cur>>i)&1) {
      w=i;
      break;
    }
    ofr=fr;
    for (++i; i<ofr; i++) if ((cur>>i)&1) {
      q[fr]=q[w]+q[i];
      a[m]=q[w];
      b[m]=q[i];
      r[m++]='+';
      w=fr++;
    }
    int wh=w;
    //printf("e=%d\n",int(e));
    qz[0]=x;
    for (i=1; (1LL<<i)<=e; i++) {
      qz[i]=qz[i-1]*2;
      a[m]=b[m]=qz[i-1];
      r[m++]='+';
    }
    //for (i=0; i<zfr; i++) printf("%d ",qz[i]); puts("qz");
    zfr=i;
    for (i=0; i<zfr; i++) if ((e>>i)&1) {
      w=i;
      break;
    }
    ozfr=zfr;
    for (++i; i<ozfr; i++) if ((e>>i)&1) {
      qz[zfr]=qz[w]+qz[i];
      a[m]=qz[w];
      b[m]=qz[i];
      r[m++]='+';
      w=zfr++;
    }
    //for (i=0; i<zfr; i++) printf("%d ",qz[i]); puts("qz~");
    if (q[wh]>0 && qz[w]>0) {
      a[m]=q[wh];
      b[m]=qz[w];
      r[m++]='+';
    }
    break;
  }
}
int main() {
  scanf("%d",&st);
  for (mn=2; ; mn++) {
    x=(st*mn)^st;
    if (gcd(x,st)==1) break;
  }
  z=x*st;
  q[0]=st;
  for (i=1; (1LL<<i)<=mn; i++) {
    q[i]=q[i-1]*2;
    a[m]=b[m]=q[i-1];
    r[m++]='+';
  }
  fr=i;
  for (i=0; i<fr; i++) if ((mn>>i)&1) {
    w=i;
    break;
  }
  ofr=fr;
  for (++i; i<ofr; i++) if ((mn>>i)&1) {
    q[fr]=q[w]+q[i];
    a[m]=q[w];
    b[m]=q[i];
    r[m++]='+';
    w=fr++;
  }
  a[m]=q[fr-1];
  b[m]=st;
  r[m++]='^';
  if (z%2) z++;
  solve(z);
  solve(z+1);
  a[m]=z;
  b[m]=z+1;
  r[m++]='^';
  printf("%d\n",m);
  for (i=0; i<m; i++) printf("%I64d %c %I64d\n",a[i],r[i],b[i]);  
  return 0;
}