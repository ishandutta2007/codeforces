#include <bits/stdc++.h>
using namespace std;
const int md=1000000007,MX=1000100;
int t,n,m,r,i,j,d,prv,lst,len,a[MX],z[MX];
long long p[22],cur,now;
bool found;
long long getpw(int v) {
  long long r=1;
  for (int d=v; d>0; ) {
    r=(r*p[z[d]])%md;
    d-=(1<<z[d]);
  }
  return r;
}
void go() {
  r=(now*getpw(prv))%md;
  for (int e=i; e>=0; e=j) {
    for (j=e; j>=0 && a[j]==a[e]; j--);
    len=e-j;
    r=(r+md-(len*getpw(a[e]))%md)%md;
  }
  found=true;
}
int main() {
  for (i=2; i<MX; i++) {
    z[i]=z[i-1];
    if ((1<<(z[i]+1))<=i) ++z[i];
  }
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    p[0]=m;
    for (lst=20, i=1; i<20; i++) {
      p[i]=p[i-1]*p[i-1];
      if (lst==20 && p[i]>=2000000) lst=i;
      //printf("%d = %I64d | %d\n",i,p[i],lst);
      p[i]%=md;
    }
    sort(a,a+n);
    for (cur=found=0, i=n-1; i>=0; i=j) {
      for (j=i; j>=0 && a[j]==a[i]; j--);
      len=i-j;
      //printf("%dx%d vs %dx%d\n",len,a[i],int(cur),prv);
      if (i<n-1 && cur>0) {
        d=prv-a[i];
        now=cur;
        if (lst<=z[d]) { go(); break; }
        while (d>0) {
          cur*=p[z[d]];
          if (cur>=2000000) { go(); break; }
          d-=(1<<z[d]);
        }
        if (found) break;
      }
      if (cur<len) cur=(len-cur)%2; else cur-=len;
      prv=a[i];
    }
    now=cur;
    if (!found) go();
    printf("%d\n",r);
  }
  return 0;
}