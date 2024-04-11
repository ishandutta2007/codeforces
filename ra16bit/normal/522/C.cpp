#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,m,i,j,z,x[100100],y[100100],last[100100],cnt[100100];
bool was,can[100100];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    cnt[0]=z=0; was=false;
    for (i=1; i<=m; i++) {
      scanf("%d",&cnt[i]);
      last[i]=0;
      can[i]=false;
    }
    for (i=1; i<n; i++) {
      scanf("%d%d",&x[i],&y[i]);
      last[x[i]]=i;
    }
    for (i=1; i<n; i++) {
      if (!was && y[i]==1) {
        was=true; z=1000000000;
        for (j=1; j<=m; j++) if (last[j]<i && cnt[j]<=-cnt[0]) {
          can[j]=true;
          z=min(z,cnt[j]);
        }
      }
      cnt[x[i]]--;
    }
    z=-cnt[0]-z;
    for (i=1; i<=m; i++) putchar((can[i] || cnt[i]<=z)?'Y':'N');
    putchar('\n');
  }
  return 0;
}