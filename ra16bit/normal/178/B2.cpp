#include <cstdio>
#include <vector>
using namespace std;
int n,m,i,j,k,x,y,cc=1,gt,tot,c[100100],t[100100],l[100100],d[100100],where[100100],all[200200],q[200200],a[19][200200];
vector <int> g[100100],h[100100];
void dfs(int i, int p) {
  t[i]=l[i]=++gt;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    if (t[k]==0) {
      dfs(k,i);
      l[i]=min(l[i],l[k]);
    } else l[i]=min(l[i],t[k]);
  }
}
void cfs(int i, int cur) {
  c[i]=cur;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (c[k]>0) continue;
    if (l[k]>t[i]) {
      h[cur].push_back(++cc);
      h[cc].push_back(cur);
      cfs(k,cc);
    } else cfs(k,cur);
  }
}
void hfs(int i, int l) {
  all[++tot]=i;
  where[i]=tot;
  d[i]=l;
  for (int j=0; j<h[i].size(); j++) {
    int k=h[i][j];
    if (where[k]==0) {
      hfs(k,l+1);
      all[++tot]=i;
    }
  }
}
int rmq(int l, int r) {
  if (l>r) swap(l,r);
  int Q=q[r-l+1];
  x=min(a[Q][l],a[Q][r-(1<<Q)+1]);
  return x;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1,0);
  cfs(1,cc);
  hfs(1,0);
  for (x=0, i=1; i<=tot; i++) {
    if (i==(1<<(x+1))) x++;
    q[i]=x;
    a[0][i]=d[all[i]];
  }
  for (j=1; j<=18; j++) for (i=1; i<=tot; i++) {
    a[j][i]=a[j-1][i];
    if (i+(1<<(j-1))<=tot) a[j][i]=min(a[j][i],a[j-1][i+(1<<(j-1))]);
  }
  scanf("%d",&k);
  for (i=0; i<k; i++) {
    scanf("%d%d",&x,&y);
    printf("%d\n",d[c[x]]+d[c[y]]-2*rmq(where[c[x]],where[c[y]]));
  }
  return 0;
}