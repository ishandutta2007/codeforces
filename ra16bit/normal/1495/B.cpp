#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,i,res,a[MX],lftup[MX],lftdn[MX],rghup[MX],rghdn[MX],lmxlftup[MX],rmxlftup[MX],lmxrghup[MX],rmxrghup[MX];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    if (i>1) {
      if (a[i-1]>a[i]) {
        lftup[i]=lftup[i-1]+1;
        lftdn[i]=1;
      }else {
        lftup[i]=1;
        lftdn[i]=lftdn[i-1]+1;
      }
    } else {
      lftup[i]=1;
      lftdn[i]=1;
    }
    lmxlftup[i]=max(lmxlftup[i-1],lftup[i]);
  }
  for (i=n; i>=1; i--) {
    if (i<n) {
      if (a[i+1]>a[i]) {
        rghup[i]=rghup[i+1]+1;
        rghdn[i]=1;
      }else {
        rghup[i]=1;
        rghdn[i]=rghdn[i+1]+1;
      }
    } else {
      rghup[i]=1;
      rghdn[i]=1;
    }
    rmxlftup[i]=max(rmxlftup[i+1],lftup[i]);
    rmxrghup[i]=max(rmxrghup[i+1],rghup[i]);
  }
  for (i=1; i<=n; i++) {
    lmxrghup[i]=max(lmxrghup[i-1],rghup[i]);
    int lpos=i-lftdn[i]+1;
    int rpos=i+rghdn[i]-1;
    int cur=max(lftdn[i],rghdn[i]);
    if (cur<=1) continue;
    int pos=min(lpos,i-1);
    if (pos>=1 && lmxlftup[pos]>=cur) continue;
    if (lpos>1 && lmxrghup[lpos-1]>=cur) continue;
    pos=max(rpos,i+1);
    if (pos<=n && rmxrghup[pos]>=cur) continue;
    if (rpos<n && rmxlftup[rpos+1]>=cur) continue;
    int mn=min(lftdn[i],rghdn[i]);
    if (cur%2==1) --cur;
    if (cur<mn) ++res;
  }
  printf("%d\n",res);
  return 0;
}