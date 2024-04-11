#include <bits/stdc++.h>
using namespace std;
const int MX=300300;
int t,n,m,ans,i,j,k,cnt,it,u[MX],a[MX],c[MX],o[MX],r[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) c[i]=0;
    for (i=1; i<=n; i++) {
      scanf("%d",&a[i]);
      if (a[i]<=i) ++c[i-a[i]]; else ++c[n-(a[i]-i)];
    }
    for (ans=k=0; k<n; k++) if (m*2>=n-c[k]) {
      for (i=1; i<=n-k; i++) o[i]=i+k;
      for (j=1; i<=n; i++, j++) o[i]=j;
      //for (i=1; i<=n; i++) printf("%d ",o[i]); puts("~");
      ++it;
      cnt=0;
      for (i=1; i<=n; i++) if (u[i]!=it) {
        u[i]=it;
        for (j=o[a[i]]; u[j]!=it; j=o[a[j]]) {
          u[j]=it;
          ++cnt;
        }
      }
      if (cnt<=m) r[ans++]=k;
    }
    printf("%d",ans);
    for (i=0; i<ans; i++) printf(" %d",r[i]);
    puts("");
  }
  return 0;
}