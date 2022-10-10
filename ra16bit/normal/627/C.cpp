#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int d,n,m,i,j,ii,jj,e,nx[200200],ka[200200],kb[200200];
long long f[200200];
pii a[200200];
set<pii> s,c;
bool cmpa(int i, int j) {
  return a[i]>a[j];
}
bool cmpb(int i, int j) {
  if (a[i].second!=a[j].second) return a[i].second<a[j].second;
  return a[i].first>a[j].first;
}
int main() {
  scanf("%d%d%d",&d,&n,&m);
  for (i=1; i<=m; i++) {
    scanf("%d%d",&a[i].first,&a[i].second);
    ka[i]=kb[i]=i;
  }
  a[++m]=make_pair(d,0);
  ka[m]=kb[m]=m;
  m++;
  sort(ka,ka+m,cmpa);
  sort(kb,kb+m,cmpb);
  for (ii=0; ii<m; ii++) {
    i=kb[ii];
    if (ii>0) nx[i]=s.lower_bound(make_pair(a[i].first,-1))->second;
    s.insert(make_pair(a[i].first,i));
  }
  for (jj=ii=0; ii<m; ii++) {
    i=ka[ii];
    for (; jj<ii; jj++) {
      j=ka[jj];
      if (a[j].first-a[i].first<=n) break;
      c.erase(make_pair(a[j].second,j));
    }
    if (ii>0) {
      if (c.empty()) { puts("-1"); return 0; }
      if (a[nx[i]].first<=a[i].first+n) {
        f[i]=f[nx[i]]+1LL*(a[nx[i]].first-a[i].first)*a[i].second;
      } else {
        e=c.begin()->second;
        f[i]=f[e]+1LL*n*a[i].second+1LL*(a[i].first+n-a[e].first)*(-a[e].second);
      }
    }
    c.insert(make_pair(a[i].second,i));
  }
  printf("%I64d\n",f[0]);
  return 0;
}