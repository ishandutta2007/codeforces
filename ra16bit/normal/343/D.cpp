#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int n,m,num,x,y,i,t[500050],fi[500050],last[500050],r[500050],a[500050],le[500050],ri[500050];
vector<int> g[500050],v[500050],c[500050];
set<int> s;
void modify(int x, int v) {
  a[x]=max(a[x],v);
  for (int i=x; i<=num; i=(i<<1)-(i&(i-1))) le[i]=max(le[i],v);
  for (int i=x; i>0; i&=(i-1)) ri[i]=max(ri[i],v);
}
int findmax(int l, int r) {
  int res=a[l],i,j;
  for (i=l; ; i=j) {
    j=(i<<1)-(i&(i-1));
    if (j>r) break;
    res=max(res,ri[i]);
  }
  res=max(res,a[i]);
  for (i=r; ; i=j) {
    j=i&(i-1);
    if (j<l) break;
    res=max(res,le[i]);
  }
  res=max(res,a[i]);  
  return res;
}
void dfs(int i, int p) {
  fi[i]=++num;
  for (int j=0; j<g[i].size(); j++) if (g[i][j]!=p) dfs(g[i][j],i);
  last[i]=num;
}
void rfs(int i, int p) {
  for (int j=0; j<v[i].size(); j++) s.insert(-v[i][j]);
  for (int j=0; j<c[i].size(); j++) {
    y=c[i][j];
    x=*(s.lower_bound(-y));
    r[y]=int(-x>r[y]);
  }
  for (int j=0; j<g[i].size(); j++) if (g[i][j]!=p) rfs(g[i][j],i);
  for (int j=0; j<v[i].size(); j++) s.erase(-v[i][j]);
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1,0);
  scanf("%d",&m);
  for (i=1; i<=m; i++) {
    scanf("%d%d",&t[i],&x);
    if (t[i]==1) v[x].push_back(i);
    if (t[i]==2) modify(fi[x],i);
    if (t[i]==3) {
      c[x].push_back(i);
      r[i]=findmax(fi[x],last[x]);
    }
  }
  s.insert(0);
  rfs(1,0);
  for (i=1; i<=m; i++) if (t[i]==3) printf("%d\n",r[i]);
  return 0;
}