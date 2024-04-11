#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=100100;
const long long INF=111000000000000LL;
int n,m,i,a[MX],s[MX];
long long cnt,k,l,r,h,rh,cur,b[MX],c[MX];
void add(int x) {
  for (; x<=m; x=(x<<1)-(x&(x-1))) s[x]++;
}
long long sum(int x) {
  long long r=0;
  for (; x>0; x&=x-1) r+=s[x];
  return r;
}
int main() {
  scanf("%d%I64d",&n,&k);
  for (i=0; i<n; i++) {
    b[i]=cur;
    scanf("%d",&a[i]);
    cur+=a[i];
  }
  b[n]=cur;
  for (i=0; i<=n; i++) c[i]=b[i];
  
  sort(b,b+n+1);
  m=unique(b,b+n+1)-b;
  //for (i=0; i<m; i++) printf("%I64d ",b[i]); puts("~");
  l=0; r=2*INF;
  while (l<r) {
    h=(l+r)/2+1;
    rh=h-INF;
    for (i=0; i<=m; i++) s[i]=0;
    //printf("%I64d\n",rh);
    for (cnt=i=0; i<n; i++) {
      add(lower_bound(b,b+m,c[i])-b+1);
      //printf("%d: %I64d (%d)\n",i,c[i]+a[i]-rh,upper_bound(b,b+m,c[i]+a[i]-rh)-b);
      cnt+=sum(upper_bound(b,b+m,c[i]+a[i]-rh)-b);
    }
    //printf("%I64d\n",cnt);
    if (cnt>=k) l=h; else r=h-1;
    //return 0;
  }
  printf("%I64d\n",r-INF);
  return 0;
}