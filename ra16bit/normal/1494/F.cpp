#include <bits/stdc++.h>
using namespace std;
const int MX=3030;
int n,m,i,j,all,far,cur,cnt,lst,nv,x[MX],y[MX],d[MX],u[MX],was[MX],pos[MX],it,fnd;
vector<int> g[MX],r;
bool b[MX],c[MX];
void dfs(int i) {
  u[i]=it; ++nv;
  for (int j: g[i]) if (!b[j]) {
    int k=x[j]+y[j]-i;
    if (u[k]!=it) dfs(k);
  }
}
void euler(int i) {
  while (pos[i]<g[i].size()) {
    int e=g[i][pos[i]++];
    if (was[e]==it || b[e]) continue;
    was[e]=it;
    int v=x[e]+y[e]-i;
    euler(v);
    r.push_back(v);
  }
}
void eulerp(int i) {
  euler(i);
  r.push_back(i);
  reverse(r.begin(),r.end());
}
void printans() {
  printf("%d\n",int(r.size()));
  for (int i=0; i<r.size(); i++) printf("%d ",r[i]);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x[i],&y[i]);
    g[x[i]].push_back(i);
    g[y[i]].push_back(i);
  }
  for (i=1; i<=n; i++) if (g[i].size()&1) {
    c[i]=true;
    ++cnt;
    lst=i;
    all^=i;
  }
  ++it;
  if (cnt==0) {
    eulerp(1);
    printans();
    return 0;
  }
  if (cnt==2) {
    eulerp(lst);
    printans();
    return 0;
  }
  for (i=1; i<=n; i++) {
    r.clear();
    for (j=1; j<=n; j++) { d[j]=g[j].size(); pos[j]=0; }
    far=all;
    cur=int(c[i]);
    if (c[i]) far^=i;
    for (int j: g[i]) if (c[x[j]+y[j]-i]) {
      cur++;
      b[j]=true;
      far^=(x[j]+y[j]-i);
    }
    nv=0; ++it;
    dfs(i);
    if (cur==cnt) {
      fnd=-1;
      for (int j: g[i]) if (b[j] && u[x[j]+y[j]-i]!=it) {
        nv=0;
        dfs(x[j]+y[j]-i);
        if (nv>1) { fnd=j; break; }
      }
      if (fnd==-1) for (int j: g[i]) if (b[j]) { fnd=j; break; }
      b[fnd]=false;
      eulerp(x[fnd]+y[fnd]-i);
      for (j=0; j<m; j++) if (was[j]!=it && !b[j]) break;
      if (j<m || r.back()!=i) {
        for (int j: g[i]) b[j]=false;
        continue;
      }
      r.push_back(-1);
      for (int j: g[i]) if (b[j]) {
        r.push_back(x[j]+y[j]-i);
        r.push_back(i);
      }
      printans();
      return 0;
    }
    if (cur==cnt-1) {
      eulerp(far);
      for (j=0; j<m; j++) if (was[j]!=it && !b[j]) break;
      if (j<m || r.back()!=i) {
        for (int j: g[i]) b[j]=false;
        continue;
      }
      r.push_back(-1);
      for (int j: g[i]) if (b[j]) {
        r.push_back(x[j]+y[j]-i);
        r.push_back(i);
      }
      printans();
      return 0;
    }
    for (int j: g[i]) b[j]=false;
  }
  puts("0");
  return 0;
}