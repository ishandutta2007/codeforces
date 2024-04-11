#include <bits/stdc++.h>
using namespace std;
int n,m,i,l,r,h,x,y,res,a[200200],c[200200];
vector<int> g[200200];
int dfs(int i, int p) {
  c[i]=1;
  int cnt=1,mx1=0,mx2=0;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    int cur=dfs(k,i);
    if (cur!=c[k]) {
      if (cur>mx1) {
        mx2=mx1; mx1=cur;
      } else if (cur>mx2) mx2=cur;
    } else cnt+=cur;
    c[i]+=c[k];
  }
  if (a[i]<h) return 0;
  res=max(res,cnt+mx1+mx2);
  return cnt+mx1;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=1; i<=n; i++) if (a[i]<a[x]) x=i;
  l=a[x]; r=1000001;
  while (l<r) {
    h=(l+r)/2+1;
    res=0; dfs(x,0);
    if (res>=m) l=h; else r=h-1;
  }
  printf("%d\n",r);
  return 0;
}