#include <bits/stdc++.h>
using namespace std;
const int MX=300300;
int t,n,m,i,k[MX],c[MX];
long long r;
int main() {
  scanf("%d",&t);
  while (t--){
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) scanf("%d",&k[i]);
    for (i=1; i<=m; i++) scanf("%d",&c[i]);
    sort(k,k+n);
    reverse(k,k+n);
    for (r=i=0; i<n; i++) r+=c[min(k[i],i+1)];
    printf("%I64d\n",r);
  }
  return 0;
}