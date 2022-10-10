#include <cstdio>
#include <vector>
#include <map>
#include <memory.h>
using namespace std;
int n,q,i,j,a,b,inf,p[500500],s[500500],l[500500],r[500500],ans[500500];
vector<int> g[500500],f[500500];
map<int,int> m;
void add(int x, int v) {
  if (v>s[x]) return;
  s[x]=v;
  for (int i=x; i>0; i&=i-1) l[i]=min(l[i],v);
  for (; x<=n; x=(x<<1)-(x&(x-1))) r[x]=min(r[x],v);
}
int findmin(int le, int ri) {
  int res=s[le],p,i;
  for (i=le; ; i=p) {
    p=(i<<1)-(i&(i-1));
    if (p>ri) break;
    res=min(res,l[i]);
  }
  res=min(res,s[i]);
  for (i=ri; ; i=p) {
    p=(i&(i-1));
    if (p<le) break;
    res=min(res,r[i]);
  }
  return min(res,s[i]);
}
int main() {
  scanf("%d%d",&n,&q);
  for (i=1; i<=n; i++) {
    scanf("%d",&a);
    if (m.count(a)) p[i]=m[a];
    m[a]=i;
  }
  for (i=0; i<q; i++) {
    scanf("%d%d",&a,&b);
    g[b].push_back(a);
    f[b].push_back(i);
  }
  memset(s,120,sizeof(s));
  memset(l,120,sizeof(l));
  memset(r,120,sizeof(r));
  inf=s[0];
  for (i=1; i<=n; i++) {
    if (p[i]>0) add(p[i],i-p[i]);
    for (j=0; j<g[i].size(); j++) ans[f[i][j]]=findmin(g[i][j],i);
  }
  for (i=0; i<q; i++) printf("%d\n",ans[i]==inf?-1:ans[i]);
  return 0;
}