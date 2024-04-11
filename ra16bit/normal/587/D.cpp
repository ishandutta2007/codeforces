#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int n,m,M,z,num,cc,i,ii,it,l,r,mid,x[50050],y[50050],c[50050],t[50050],k[50050],a[300300],b[300300],p[300300],ans[300300];
vector<int> g[50050],h[300300],o[300300],s[300300];
bool u[300300];
set<int> e,col[50050];
map<int,int> w;
int nt(int i) {
  if (i<M) return i+M;
  return i-M;
}
bool upd(int i, int v) {
  if (ans[i]<it) {
    ans[i]=it+v;
    if (v) for (int j=0; j<s[i].size(); j++) if (!upd(s[i][j],v)) return false;
  }
  return ans[i]==it+v;
}
bool solve(int cur) {
  it+=2;
  for (int i=0; i<m; i++) if (t[i]>cur) {
    if (!upd(b[i],0)) return false;
    if (!upd(b[nt(i)],1)) return false;
  }
  for (int i=cc; i>0; i--) if (ans[i]<it) {
    ans[i]=it+1;
    for (int j=0; j<s[i].size(); j++) if (ans[s[i][j]]==it) { ans[i]--; break; }
    //printf("%d = %d\n",i,ans[i]-it);
    if (!upd(b[nt(p[i])],(ans[i]-it)^1)) return false;
  } else if (ans[i]==it+1) {
    for (int j=0; j<s[i].size(); j++) if (ans[s[i][j]]==it) return false;
  }
  for (int i=0; i<M; i++) if (ans[b[i]]!=(ans[b[nt(i)]]^1)) return false;
  return true;
}
void dfs(int i) {
  u[i]=true;
  for (int j=0; j<h[i].size(); j++) if (!u[h[i][j]]) dfs(h[i][j]);
  a[++num]=i;
}
void ofs(int i) {
  b[i]=cc;
  for (int j=0; j<o[i].size(); j++) {
    int k=o[i][j];
    if (b[k]) s[b[k]].push_back(cc); else ofs(k);
  }
}
void edge(int i, int j) {
  int k=nt(i);
  h[k].push_back(j);
  o[j].push_back(k);
  k=nt(j); 
  h[k].push_back(i);
  o[i].push_back(k);
}
bool cmp(int i, int j) {
  return t[i]>t[j];
}
int main() {
  scanf("%d%d",&n,&m); M=3*m;
  for (i=0; i<m; i++) {
    scanf("%d%d%d%d",&x[i],&y[i],&c[i],&t[i]);
    g[x[i]].push_back(i);
    g[y[i]].push_back(i);
    k[i]=i;
  }
  for (z=m, i=1; i<=n; i++) {
    for (int j=0; j<g[i].size(); j++, z++) {
      int k=g[i][j];
      if (e.count(c[k])) {
        puts("No");
        return 0;
      }
      if (w.count(c[k])) {
        edge(w[c[k]],k);
        e.insert(c[k]);
      } else w[c[k]]=k;
      edge(nt(k),z);
      if (j>0) {
        edge(nt(z-1),z);
        edge(nt(z-1),nt(k));
      }
    }
    w.clear();
    e.clear();
  }
  for (i=0; i<2*M; i++) if (!u[i]) dfs(i);
  for (i=num; i>0; i--) if (!b[a[i]]) {
    p[++cc]=a[i];
    ofs(a[i]);
  }
  sort(k,k+m,cmp);
  for (ii=0; ii<m; ii++) {
    i=k[ii];
    if (col[x[i]].count(c[i])) break;
    if (col[y[i]].count(c[i])) break;
    col[x[i]].insert(c[i]);
    col[y[i]].insert(c[i]);
  }
  if (ii==m) { puts("Yes\n0 0"); return 0; }
  l=t[i]; r=t[k[0]];
  while (l<r) {
    mid=(l+r)/2;
    if (solve(mid)) r=mid; else l=mid+1;
  }
  if (solve(r)) {
    puts("Yes");
    for (l=i=0; i<m; i++) if (ans[b[i]]==it+1) l++;
    printf("%d %d\n",r,l);
    for (l=i=0; i<m; i++) if (ans[b[i]]==it+1) printf("%d ",i+1);
  } else puts("No");
  return 0;
}