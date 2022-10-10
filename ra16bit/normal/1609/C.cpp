#include <bits/stdc++.h>
using namespace std;
const int MX=1000100;
int t,x,i,j,cur,rgh,n,m,lp[MX],ls[MX];
bool u[MX];
long long res;
int main() {
  for (i=2; i<MX; i++) if (!u[i]) for (j=i+i; j<MX; j+=i) u[j]=true;
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<m; i++) {
      ls[i]=-1;
      lp[i]=-1;
    }
    for (res=i=0; i<n; i++) {
      scanf("%d",&x);
      cur=i%m;
      if (!u[x]) {
        if (x!=1) {
          ls[cur]=max(ls[cur],lp[cur]);
          lp[cur]=i/m;
        }
        rgh=min(lp[cur],i/m-1);
        if (rgh>ls[cur]) res+=rgh-ls[cur];
      } else ls[cur]=i/m;
    }
    printf("%lld\n",res);
  }
  return 0;
}