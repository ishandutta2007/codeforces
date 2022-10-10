#include <bits/stdc++.h>
using namespace std;
const int MX=1100100;
int t,it,n,q,i,j,a,cur,tot,x,z,r,ans,b[MX],cnt[MX],lst[MX],all[MX];
long long w;
int main() {
  for (i=2; i<MX; i++) if (b[i]==0) for (j=i; j<MX; j+=i) b[j]=i;
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%d",&n);
    for (tot=i=0; i<n; i++) {
      scanf("%d",&a);
      z=1;
      while (a>1) {
        cur=b[a];
        for (x=0; b[a]==cur; x^=1) a/=cur;
        if (x) z*=cur;
      }
      if (lst[z]!=it) {
        lst[z]=it;
        cnt[z]=1;
        all[tot++]=z;
      } else ++cnt[z];
    }
    for (r=ans=i=0; i<tot; i++) {
      r=max(r,cnt[all[i]]);
      if (all[i]==1 || cnt[all[i]]%2==0) ans+=cnt[all[i]];
    }
    ans=max(r,ans);
    scanf("%d",&q);
    while (q--) {
      scanf("%I64d",&w);
      printf("%d\n",w?ans:r);
    }
  }
  return 0;
}