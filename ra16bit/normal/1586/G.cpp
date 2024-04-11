#include <bits/stdc++.h>
using namespace std;
const int MX=400400,md=1000000007;
int N,n,m,i,res,lft,rgh,ii,a[MX],b[MX],c[MX],k[MX],f[MX],s[MX];
void upd(int x, int v) {
  for (; x<=N; x=(x<<1)-(x&(x-1))) s[x]=(s[x]+v)%md;
}
int sum(int x) {
  int r=0;
  for (; x>0; x&=x-1) r=(r+s[x])%md;
  return r;
}
bool cmp(int i, int j) {
  return b[i]>b[j];
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d%d",&a[i],&b[i]);
    c[a[i]]=-i;
    c[b[i]]=i;
  }
  scanf("%d",&m);
  for (i=0; i<m; i++) scanf("%d",&k[i]);
  sort(k,k+m,cmp);
  N=2*n;
  for (i=1; i<=N; i++) if (c[i]>0) {
    f[c[i]]=(1+sum(i)+md-sum(a[c[i]]))%md;
    upd(a[c[i]],f[c[i]]);
  }
  rgh=N;
  for (lft=ii=0; ii<m; ii++) {
    i=k[ii];
    if (a[i]<=lft) continue;
    for (; rgh>=b[i]; rgh--) if (c[rgh]>0) upd(a[c[rgh]],(md-f[c[rgh]])%md);
    res=(res+1)%md;
    if (lft<rgh) {
      res=(res+sum(rgh))%md;
      res=(res+md-sum(lft))%md;
    }
    lft=a[i];
  }
  printf("%d\n",res);
  return 0;
}