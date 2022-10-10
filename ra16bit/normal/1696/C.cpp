#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int t,n,m,k,na,nb,i,a[MX],b[MX];
long long ca[MX],cb[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      ca[i]=1;
      while (a[i]%m==0) {
        a[i]/=m;
        ca[i]*=m;
      }
    }
    scanf("%d",&k);
    for (i=0; i<k; i++) {
      scanf("%d",&b[i]);
      cb[i]=1;
      while (b[i]%m==0) {
        b[i]/=m;
        cb[i]*=m;
      }
    }
    na=0;
    for (i=1; i<n; i++) if (a[i]!=a[na]) {
      a[++na]=a[i];
      ca[na]=ca[i];
    } else ca[na]+=ca[i];
    nb=0;
    for (i=1; i<k; i++) if (b[i]!=b[nb]) {
      b[++nb]=b[i];
      cb[nb]=cb[i];
    } else cb[nb]+=cb[i];
    if (na!=nb) { puts("No"); continue; }
    for (i=0; i<=na; i++) if (a[i]!=b[i] || ca[i]!=cb[i]) break;
    if (i<=na) puts("No"); else puts("Yes");
  }
  return 0;
}