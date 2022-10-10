#include <bits/stdc++.h>
using namespace std;
const int MX=111;
int t,n,i,j,k,r,st,it,u[MX],f[MX],a[MX],s[MX][MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      ++it;
      for (j=i; j>=0; --j) {
        if (a[j]<MX) u[a[j]]=it;
        for (k=0; u[k]==it; ++k);
        s[j][i]=k;
      }
    }
    for (r=st=0; st<n; st++) for (i=st; i<n; i++) {
      f[i]=s[st][i]+1;
      for (j=st; j<i; j++) f[i]=max(f[i],f[j]+s[j+1][i]+1);
      r+=f[i];
    }
    printf("%d\n",r);
  }
  return 0;
}