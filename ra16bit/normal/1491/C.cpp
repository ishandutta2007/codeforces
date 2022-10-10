#include <bits/stdc++.h>
using namespace std;
int t,n,i;
long long c[5050],a,cur,r;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (r=cur=i=0; i<n; i++) c[i]=0;
    for (i=0; i<n; i++) {
      cur+=c[i];
      scanf("%lld",&a);
      if (a>1) {
        if (i+2<n) ++c[i+2];
        if (i+a+1<n) --c[i+a+1];
      }
      a-=cur;
      if (a<1) {
        if (i+1<n) c[i+1]+=1-a;
        if (i+2<n) c[i+2]-=1-a;
      } else r+=a-1;
    }
    printf("%lld\n",r);
  }
  return 0;
}