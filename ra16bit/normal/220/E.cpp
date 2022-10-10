#include <cstdio>
#include <algorithm>
using namespace std;
int i,r,n,x,a[100100],s[100100],t[100100];
pair <int, int> y[100100];
long long m,ans,cur,fl[100100],fr[100100];
void modify(int *s, int i, int v) {
  for (; i<=n; i=(i<<1)-(i&(i-1))) s[i]+=v;
}
int cnt(int *s, int i) {
  int r=0;
  for (; i>0; i&=i-1) r+=s[i];
  return r;
}
void remove(int n) {
  modify(t,a[r],-1);
  cur-=n-cnt(s,a[r]);
  r++;
}
int main() {
  scanf("%d%I64d",&n,&m);
  for (i=1; i<=n; i++) { scanf("%d",&x); y[i-1]=make_pair(x,i); }
  sort(y,y+n);
  for (i=0; i<n; i++) a[y[i].second]=i+1;
  for (i=1; i<=n; i++) {
    fl[i]=fl[i-1]+i-1-cnt(s,a[i]);
    modify(s,a[i],1);
  }
  for (i=1; i<=n; i++) s[i]=0;
  for (i=n; i>=1; i--) {
    fr[i]=fr[i+1]+cnt(s,a[i]);
    modify(s,a[i],1);
  }
  for (i=1; i<=n; i++) s[i]=0;
  for (i=n; i>=2; i--) modify(t,a[i],1);
  for (i=1, r=2; i<n; i++) {
    if (r==i) remove(i-1);
    modify(s,a[i],1);
    cur+=cnt(t,a[i]);
    while (r<=n) {
      if (fl[i]+fr[r]+cur<=m) break;
      remove(i);
    }
    ans+=n-r+1;
  }
  printf("%I64d\n",ans);
  return 0;
}