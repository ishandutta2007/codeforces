#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,k,r,cnt,dp,dq,a[111];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    r=n-1;
    for (i=0; i<n; i++) for (j=i+1; j<n; j++) {
      dp=a[j]-a[i];
      dq=j-i;
      for (cnt=k=0; k<n; k++) if (a[i]*dq+dp*(k-i)!=a[k]*dq) ++cnt;
      r=min(r,cnt);
    }
    printf("%d\n",r);
  }
  return 0;
}