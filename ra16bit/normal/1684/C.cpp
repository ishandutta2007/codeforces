#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,n,m,i,j,mn[MX],mx[MX],b[MX];
vector<int> a[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (j=0; j<m; j++) {
      mn[j]=0;
      mx[j]=m;
    }
    for (i=0; i<n; i++) {
      a[i].resize(m);
      for (j=0; j<m; j++) {
        scanf("%d",&a[i][j]);
        b[j]=a[i][j];
      }
      sort(b,b+m);
      for (j=0; j<m; j++) {
        mn[j]=max(mn[j],int(lower_bound(b,b+m,a[i][j])-b));
        mx[j]=min(mx[j],int(upper_bound(b,b+m,a[i][j])-b));
      }
    }
    vector<int> bad;
    for (i=0; i<m; i++) {
      if (mx[i]<mn[i]) break;
      if (i<mn[i] || i>=mx[i]) bad.push_back(i);
    }
    if (i<m || bad.size()>2) {
      puts("-1");
      continue;
    }
    if (bad.size()==0) {
      puts("1 1");
      continue;
    }
    if (bad.size()==1) {
      if (bad[0]<mn[bad[0]]) bad.push_back(mn[bad[0]]); else bad.push_back(mx[bad[0]]);
    }
    for (i=0; i<n; i++) {
      swap(a[i][bad[0]],a[i][bad[1]]);
      for (j=1; j<m; j++) if (a[i][j]<a[i][j-1]) break;
      if (j<m) break;
    }
    if (i>=n) printf("%d %d\n",bad[0]+1,bad[1]+1); else puts("-1");
  }
  return 0;
}