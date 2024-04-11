#include <bits/stdc++.h>
using namespace std;
int t,n,i,a[100100],ptr[2],cnt[2];
long long r,cur;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<2; i++) cnt[i]=0;
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      a[i]&=1;
      ++cnt[a[i]];
    }
    if (cnt[0]==cnt[1]) {
      ptr[0]=0;
      ptr[1]=1;
      for (r=i=0; i<n; i++) {
        if (ptr[a[i]&1]<i) r+=i-ptr[a[i]&1];
        ptr[a[i]&1]+=2;
      }
      ptr[0]=1;
      ptr[1]=0;
      for (cur=i=0; i<n; i++) {
        if (ptr[a[i]&1]<i) cur+=i-ptr[a[i]&1];
        ptr[a[i]&1]+=2;
      }
      printf("%lld\n",min(r,cur));
    } else if (cnt[0]+1==cnt[1]) {
      ptr[0]=1;
      ptr[1]=0;
      for (cur=i=0; i<n; i++) {
        if (ptr[a[i]&1]<i) cur+=i-ptr[a[i]&1];
        ptr[a[i]&1]+=2;
      }
      printf("%lld\n",cur);
    } else if (cnt[1]+1==cnt[0]) {
      ptr[0]=0;
      ptr[1]=1;
      for (cur=i=0; i<n; i++) {
        if (ptr[a[i]&1]<i) cur+=i-ptr[a[i]&1];
        ptr[a[i]&1]+=2;
      }
      printf("%lld\n",cur);
    } else puts("-1");
  }
  return 0;
}