#include <bits/stdc++.h>
using namespace std;
const int MX=100100,BLN=1000000000;
int t,n,q,i,a[MX],b[MX];
map<int,bool> m;
long long s[MX];
void solve(int le, int ri) {
  long long cur=s[ri+1]-s[le];
  if (cur<=BLN) {
    auto it=m.find(cur);
    if (it!=m.end()) it->second=true;
  }
  if (a[le]==a[ri]) return;
  int mid=(a[le]+a[ri])/2,i=le;
  for (; i<=ri; i++) if (a[i]>mid) break;
  if (i>le && i<=ri) {
    solve(le,i-1);
    solve(i,ri);
  }
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&q);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for (i=0; i<n; i++) s[i+1]=s[i]+a[i];
    m.clear();
    for (i=0; i<q; i++) {
      scanf("%d",&b[i]);
      m[b[i]]=false;
    }
    solve(0,n-1);
    for (i=0; i<q; i++) puts(m[b[i]]?"Yes":"No");
  }
  return 0;
}