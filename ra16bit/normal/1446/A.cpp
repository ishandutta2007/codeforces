#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,n,i,ii,a[MX],k[MX],r[MX],cnt;
long long sum,m;
bool cmp(int i, int j) {
  return a[i]>a[j];
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%lld",&m);
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      k[i]=i;
    }
    sort(k,k+n,cmp);
    for (sum=cnt=ii=0; ii<n; ii++) {
      i=k[ii];
      if (a[i]+sum>m) continue;
      sum+=a[i];
      r[cnt++]=i+1;
    }
    if (sum*2>=m) {
      printf("%d\n",cnt);
      for (i=0; i<cnt; i++) printf("%d ",r[i]);
      puts("");
    } else puts("-1");
  }
  return 0;
}