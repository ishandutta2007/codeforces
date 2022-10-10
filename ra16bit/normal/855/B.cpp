#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,p,q,r,i,j,k,a[MX];
long long b[MX][2],c[2],res;
int main() {
  scanf("%d%d%d%d",&n,&p,&q,&r);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    if (i==0) {
      b[i][0]=a[i];
      b[i][1]=a[i];
    } else {
      b[i][0]=max(b[i-1][0],1LL*a[i]);
      b[i][1]=min(b[i-1][1],1LL*a[i]);
    }
  }
  res=1LL*p*a[0]+1LL*q*a[0]+1LL*r*a[0];
  c[0]=c[1]=a[n-1];
  for (i=n-1; i>=0; i--) {
    c[0]=max(c[0],1LL*a[i]);
    c[1]=min(c[1],1LL*a[i]);
    for (j=0; j<2; j++) for (k=0; k<2; k++) res=max(res,b[i][j]*p+1LL*q*a[i]+c[k]*r);
  }
  cout<<res<<'\n';
  return 0;
}