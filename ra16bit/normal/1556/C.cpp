#include <bits/stdc++.h>
using namespace std;
const int MX=1010;
int t,n,i,j,a[MX];
long long cur,res,ri,lft[MX],rgh[MX];
long long inters(long long la, long long ra, long long lb, long long rb) {
  long long le=max(la,lb);
  long long ri=min(ra,rb);
  return max(0LL,ri-le+1);
}
int main() {
    scanf("%d",&n);
    for (res=cur=i=0; i<n; i++) {
      scanf("%d",&a[i]);
      lft[i]=cur;
      if (i&1) {
        --lft[i];
        rgh[i]=(cur-=a[i]);
      } else {
        rgh[i]=cur+a[i]-1;
        cur=rgh[i]+1;
      }
      if (lft[i]>rgh[i]) swap(lft[i],rgh[i]);
      if (i&1) {
        ri=rgh[i];
        for (j=i-1; j>=0; j--) if (j&1) {
          ri=min(ri,lft[j]);
        } else {
          if (lft[i]<=ri) res+=inters(lft[j],rgh[j],lft[i],ri);
        }
      }
    }
    printf("%lld\n",res);
    return 0;
}