#include <bits/stdc++.h>
using namespace std;
const long long inf=2200200200200200200LL;
const int MX=100100;
int t,n,i,j,prv,len,a[MX];
long long m,pw[MX];
int main() {
  for (pw[0]=i=1; i<MX; i++) {
    pw[i]=pw[i-1]+pw[i-1];
    if (pw[i]>inf) pw[i]=inf;
  }
  scanf("%d",&t);
  while (t--) {
    scanf("%d%lld",&n,&m);
    if (m>pw[n-1]) { puts("-1"); continue; }
    len=0;
    for (i=1; i<n; i++) if (m<=pw[n-i-1]) a[len++]=i; else m-=pw[n-i-1];
    for (prv=i=0; i<len; i++) {
      for (j=a[i]; j>prv; j--) printf("%d ",j);
      prv=a[i];
    }
    for (j=n; j>prv; j--) printf("%d ",j);
    puts("");
  }
  return 0;
}