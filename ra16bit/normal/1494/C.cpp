#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,n,m,i,x,c[MX];
vector<int> a[2],b[2];
int solve(int x) {
  //for (int e: a[x]) printf("%d ",e); puts("a");
  //for (int e: b[x]) printf("%d ",e); puts("b");
  if (a[x].empty() || b[x].empty()) return 0;
  int r=0;
  c[int(a[x].size())]=0;
  for (int i=int(a[x].size())-1; i>=0; i--) {
    c[i]=c[i+1];
    int pos=lower_bound(b[x].begin(),b[x].end(),a[x][i])-b[x].begin();
    if (pos<b[x].size() && b[x][pos]==a[x][i]) ++c[i];
  }
  //for (int i=0; i<=a[x].size(); i++) printf("%d ",c[i]); puts("c");
  for (int i=0, j=0; i<b[x].size(); i++) if (b[x][i]>=a[x][0]) {
    for (; j<a[x].size() && a[x][j]<=b[x][i]+j; j++);
    int pos=lower_bound(b[x].begin(),b[x].end(),b[x][i]+j)-b[x].begin();
    r=max(r,c[j]+pos-i);
  }
  return r;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<2; i++) {
      a[i].clear();
      b[i].clear();
    }
    for (i=0; i<n; i++) {
      scanf("%d",&x);
      if (x>0) a[1].push_back(x); else a[0].push_back(-x);
    }
    for (i=0; i<m; i++) {
      scanf("%d",&x);
      if (x>0) b[1].push_back(x); else b[0].push_back(-x);
    }
    if (a[0].size()) reverse(a[0].begin(),a[0].end());
    if (b[0].size()) reverse(b[0].begin(),b[0].end());
    printf("%d\n",solve(0)+solve(1));
  }
  return 0;
}