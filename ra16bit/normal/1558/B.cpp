#include <bits/stdc++.h>
using namespace std;
const int MX=4000100;
int n,m,md,i,j,cur,z,f[MX],s[MX],lst[MX],a[MX],b[44],c[44];
void rec(int l, int cur) {
  if (l==m) {
    if (cur>1) {
      z-=f[lst[cur]];
      if (z<0) z+=md;
      z+=f[++lst[cur]];
      if (z>=md) z-=md;
    }
    return;
  }
  for (int i=0; i<=c[l]; ++i) {
    rec(l+1,cur);
    cur*=b[l];
  }
}
int main() {
  scanf("%d%d",&n,&md);
  f[1]=s[1]=1;
  for (i=2; i<=n; i++) {
    if (!a[i]) for (j=i; j<=n; j+=i) a[j]=i;
    cur=i;
    for (m=0; cur>1; ++m) {
      b[m]=a[cur];
      for (c[m]=0; a[cur]==b[m]; ++c[m]) cur/=b[m];
    }
    rec(0,1);
    f[i]=s[i-1]+z;
    if (f[i]>=md) f[i]-=md;
    s[i]=s[i-1]+f[i];
    if (s[i]>=md) s[i]-=md;
  }
  printf("%d\n",f[n]);
  return 0;
}