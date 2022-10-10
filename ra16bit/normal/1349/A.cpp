#include <bits/stdc++.h>
using namespace std;
int n,i,j,cur,x,mx,mn,mm,a[200200],f[200200],cnt[200200];
long long r=1LL;
long long pw(int a, int b) {
  if (b==0) return 1LL;
  if (b&1) return pw(a,b-1)*a;
  long long x=pw(a,b/2);
  return x*x;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    cnt[x]++;
    mx=max(mx,x);
  }
  for (i=2; i<=mx; i++) if (!a[i]) {
    cur=0; mn=mm=100;
    for (j=i; j<=mx; j+=i) {
      if (a[j/i]!=i) f[j]=1; else f[j]=f[j/i]+1;
      if (cnt[j]>0) {
        cur+=cnt[j];
        if (f[j]<mn) { mm=mn; mn=f[j]; } else if (f[j]<mm) mm=f[j];
        if (cnt[j]>1) {
          if (f[j]<mn) { mm=mn; mn=f[j]; } else if (f[j]<mm) mm=f[j];
        }
      }
      a[j]=i;
    }
    if (cur==n) r*=pw(i,mm); else if (cur==n-1) r*=pw(i,mn);
  }
  printf("%I64d\n",r);
  return 0;
}