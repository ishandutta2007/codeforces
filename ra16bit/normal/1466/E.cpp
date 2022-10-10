#include <bits/stdc++.h>
using namespace std;
const int md=1000000007;
int t,n,i,j,r;
long long x,y,pw2[62],cnt[62],a[500500];
int main() {
  for (pw2[0]=i=1; i<60; i++) pw2[i]=(pw2[i-1]*2)%md;
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    memset(cnt,0,sizeof(cnt));
    for (i=0; i<n; i++) {
      scanf("%lld",&a[i]);
      for (j=0; j<60; j++) if ((a[i]>>j)&1) ++cnt[j];
    }
    for (r=i=0; i<n; i++) {
      x=y=0;
      for (j=0; j<60; j++) if ((a[i]>>j)&1) {
        x=(x+cnt[j]*pw2[j])%md;
        y=(y+n*pw2[j])%md;
      } else y=(y+cnt[j]*pw2[j])%md;
      r=(r+x*y)%md;
    }
    printf("%d\n",r);
  }
  return 0;
}