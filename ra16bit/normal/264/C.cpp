#include <cstdio>
#include <algorithm>
using namespace std;
const long long inf=1000000000000000000LL;
int n,m,i,v[100100],c[100100],w1,w2;
long long a[100100],b1,b2,best,A,B,cur,oth,res;
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) scanf("%d",&v[i]);
  for (i=1; i<=n; i++) scanf("%d",&c[i]);
  while (m--) {
    scanf("%I64d%I64d",&A,&B);
    res=b1=b2=w1=w2=0;
    for (i=1; i<=n; i++) a[i]=-inf;
    for (i=1; i<=n; i++) {
      cur=a[c[i]]+v[i]*A;
      oth=(c[i]==w1?b2:b1)+v[i]*B;
      best=max(cur,oth);
      if (best>a[c[i]]) {
        a[c[i]]=best;
        res=max(res,best);
        if (c[i]==w1) b1=best;
        if (c[i]==w2) b2=best;
        if (b1<b2) {
          swap(b1,b2);
          swap(w1,w2);
        }
        if (best>b1) {
          b2=b1; w2=w1;
          b1=best; w1=c[i];
        } else if (best>b2 && c[i]!=w1) {
          b2=best; w2=c[i];
        }
      }
    }
    printf("%I64d\n",res);
  }
  return 0;
}