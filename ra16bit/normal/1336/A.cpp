#include <bits/stdc++.h>
using namespace std;
int n,m,i,x,y,a[200200],c[200200],k[200200];
vector<int> g[200200];
long long r;
void dfs(int i, int p, int d) {
  a[i]=d; c[i]=1;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    dfs(k,i,d+1);
    c[i]+=c[k];
  }
}
bool cmp(int i, int j) {
  return a[i]-c[i]>a[j]-c[j];
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1,0,1);
  for (i=0; i<n; i++) k[i]=i+1;
  sort(k,k+n,cmp);
  for (i=0; i<m; i++) r+=a[k[i]]-c[k[i]];
  printf("%I64d\n",r);
  return 0;
}