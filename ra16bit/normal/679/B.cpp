#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,rx,ry,a[100100],b[100100],c[100100];
void solve(ll up, ll& cc, ll& bb) {
  ll bc=0,cnt=0;
  for (int j=k-1; j>0; j--) {
    ll cur=(up-bc)/a[j];
    ll nc=cnt+cur-1+c[j];
    ll nb=bc+(cur-1)*a[j]+b[j];
    if (cur>0 && (nc>cc || (nc==cc && nb>bb))) {
      cc=nc; bb=nb;
    }
    bc+=cur*a[j];
    cnt+=cur;
    j=upper_bound(a,a+k,up-bc)-a;
  }
}
int main() {
  cin>>n;
  a[1]=1; b[1]=1; c[1]=1;
  for (k=2; k*k*k<=n; k++) {
    a[k]=k*k*k;
    solve(a[k]-1,c[k],b[k]);
  }
  solve(n,rx,ry);
  cout<<rx<<' '<<ry<<'\n';
  return 0;
}