#include <bits/stdc++.h>
using namespace std;
const long long inf=1000000000000000000LL;
int n,i,j,a[1000100];
long long s,f[1000100][2],res=inf;
void solve(long long x) {
  long long cur=0;
  for (int i=1; i<=n; i++) {
    int e=a[i]%x;
    long long curd=cur?(x-cur):0;
    long long nxt=(cur+e)%x;
    long long nxtd=nxt?(x-nxt):0;
    f[i][0]=f[i-1][0]+nxt;
    if (a[i]-curd>=nxt) f[i][0]=min(f[i][0],f[i-1][1]+nxt);
    f[i][1]=f[i-1][0]+nxtd;
    if (a[i]+nxtd>=curd) f[i][1]=min(f[i][1],f[i-1][1]+nxtd);
    cur=nxt;
  }
  res=min(res,min(f[n][0],f[n][1]));
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    s+=a[i];
  }
  if (s==1) { puts("-1"); return 0; }
  for (j=2; j*j<=s; j++) if (s%j==0) {
    while (s%j==0) s/=j;
    solve(j);
  }
  if (s>1) solve(s);
  printf("%I64d\n",res);
  return 0;
}