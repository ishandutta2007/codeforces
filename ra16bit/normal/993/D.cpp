#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,i,j,k,can,nxcan,rq;
ll f[52][52][5200][2],rp;
pii a[52];
bool cmp(const pii& x, const pii& y) {
  if (x.first!=y.first) return x.first>y.first;
  return x.second<y.second;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i].first);
  for (i=0; i<n; i++) scanf("%d",&a[i].second);
  sort(a,a+n,cmp);
  f[0][0][0][0]=1;
  for (i=0; i<n; i++) {
    nxcan=int(i==n-1 || a[i+1].first!=a[i].first);
    for (j=0; j<=i; j++) for (k=0; k<=i*100; k++) for (can=0; can<2; can++) if (f[i][j][k][can]) {
      ll& c=f[i+1][j+1][k+a[i].second][nxcan];
      if (c==0) c=f[i][j][k][can]+a[i].first; else c=min(c,f[i][j][k][can]+a[i].first);
      if (j>0 && can==1) {
        ll& c=f[i+1][j-1][k][1];
        if (c==0) c=f[i][j][k][can]; else c=min(c,f[i][j][k][can]);
      }
    }
  }
  for (rp=-1, j=0; j<=n; j++) for (k=0; k<=n*100; k++) {
    ll cur=f[n][j][k][1];
    if (cur>0 && (rp==-1 || ((cur-1LL)*rq<rp*k))) {
      rp=cur-1; rq=k;
    }
  }
  printf("%lld\n",(rp*1000+rq-1)/rq);
  return 0;
}