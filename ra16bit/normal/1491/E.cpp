#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int n,i,x,y,f[44],w[MX],c[MX];
vector<int> g[MX];
multiset<int> s[MX];
bool ok=true;
void dfs(int i, int p) {
  c[i]=-1;
  for (int j: g[i]) if (j!=p) {
    dfs(j,i);
    if (c[i]==-1 || s[c[j]].size()>s[c[i]].size()) c[i]=c[j];
  }
  int cur=1;
  if (c[i]==-1) {
    c[i]=i;
    s[i].insert(cur);
    return;
  }
  for (int j: g[i]) if (j!=p && c[j]!=c[i]) for (multiset<int>::iterator it=s[c[j]].begin(); it!=s[c[j]].end(); it++) {
    s[c[i]].insert(*it);
  }
  while (!s[c[i]].empty()) {
    auto it=s[c[i]].begin();
    if (w[cur+(*it)]) {
      cur+=(*it);
      s[c[i]].erase(it);
    } else break;
  }
  if (!s[c[i]].empty()) {
    auto it=s[c[i]].begin();
    if ((*it)<cur) ok=false;
  }
  s[c[i]].insert(cur);
}
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  scanf("%d",&n);
  f[0]=f[1]=1; w[1]=1;
  for (i=2; ; i++) {
    f[i]=f[i-1]+f[i-2];
    if (f[i]>n) break;
    w[f[i]]=i;
  }
  if (w[n]==0) { puts("NO"); return 0; }
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  x=rng()%n+1;
  x=1;
  dfs(x,0);
  if (ok && s[c[x]].size()==1) puts("YES"); else puts("NO");
  return 0;
}