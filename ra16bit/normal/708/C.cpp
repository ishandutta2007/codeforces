#include <bits/stdc++.h>
using namespace std;
int n,x,y,mx,my,i,a[400400];
vector<int> g[400400],all;
bool r[400400];
void sfs(int i, int p) {
  a[i]=1;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    sfs(k,i);
    a[i]+=a[k];
  }
}
void dfs(int i, int p, int d) {
  bool w=(d*2<=n);
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    dfs(k,i,d+a[i]-a[k]);
    w&=(a[k]*2<=n);
  }
  if (w) all.push_back(i);
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  sfs(1,0);
  dfs(1,0,0);
  if (all.size()>1) {
    for (i=0; i<n; i++) printf("1 ");
    return 0;
  }
  if (all.size()==0) {
    for (i=0; i<n; i++) printf("0 ");
    return 0;
  }
  r[x=all[0]]=true;
  all.clear();
  sfs(x,0);
  for (i=0; i<g[x].size(); i++) {
    y=g[x][i];
    if (a[y]>mx) {
      my=mx; mx=a[y];
    } else if (a[y]>my) my=a[y];
  }
  for (i=0; i<g[x].size(); i++) {
    y=g[x][i];
    dfs(y,x,a[x]-a[y]-((a[y]==mx)?my:mx));
  }
  dfs(x,0,0);
  for (i=0; i<all.size(); i++) r[all[i]]=true;
  for (i=1; i<=n; i++) printf("%d ",int(r[i]));
  return 0;
}