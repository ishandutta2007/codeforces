#include <bits/stdc++.h>
using namespace std;
const int MN=100100,MX=1000100;
int n,m,c,i,j,x,mx,mn[MN],cnt[MX];
bool v[MN];
long long r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&m,&x);
    mn[i]=mx=x;
    for (j=1; j<m; j++) {
      scanf("%d",&x);
      if (x>mn[i]) v[i]=true;
      mn[i]=min(mn[i],x);
      mx=max(mx,x);
    }
    if (v[i]) c++; else cnt[mx]++;
  }
  for (i=MX-2; i>=0; i--) cnt[i]+=cnt[i+1];
  for (i=0; i<n; i++) if (v[i]) r+=n; else r+=c+cnt[mn[i]+1];
  printf("%I64d\n",r);
  return 0;
}