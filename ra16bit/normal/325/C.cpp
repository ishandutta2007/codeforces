#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
typedef pair<int,int> pii;
const int mx=314000000;
int m,n,i,j,inf,cur,k,x,e,a[100100],p[100100],z[100100],pm[100100],zz[100100],qq[100100],cnt[100100],fi,fr;
bool was[100100];
vector<int> g[100100],v[100100],vv[100100];
priority_queue<pii, vector<pii>, greater<pii> > q;
int main() {
  memset(p,120,sizeof(p));
  inf=p[0];
  scanf("%d%d",&m,&n);
  for (i=0; i<m; i++) {
    scanf("%d",&a[i]);
    scanf("%d",&k);
    for (j=0; j<k; j++) {
      scanf("%d",&x);
      g[i].push_back(x);
      if (x>0) { v[x].push_back(i); z[i]++; }
    }
    if (z[i]==0 && k<p[a[i]]) {
      p[a[i]]=k;
      q.push(make_pair(k,a[i]));
    }
  }
  while (!q.empty()) {
    i=q.top().second;
    q.pop();
    if (was[i]) continue;
    was[i]=true;
    for (j=0; j<v[i].size(); j++) if (--z[v[i][j]]==0) {
       x=v[i][j];
       for (cur=e=0; e<g[x].size(); e++) {
         if (g[x][e]>0) cur+=p[g[x][e]]; else cur++;
         if (cur>=mx) cur=mx;
       }
       if (cur<p[a[x]]) {
         p[a[x]]=cur;
         q.push(make_pair(cur,a[x]));
       }
    }
  }
  for (i=0; i<m; i++) if (p[a[i]]<inf) {
    k=g[i].size();
    for (j=0; j<k; j++) if (g[i][j]>0 && p[g[i][j]]==inf) break;
    if (j<k) continue;
    cnt[a[i]]++;
    for (j=0; j<k; j++) if (g[i][j]>0) { vv[g[i][j]].push_back(i); zz[i]++; }
    if (zz[i]==0) {
      pm[a[i]]=max(pm[a[i]],k);
      --cnt[a[i]];
    }
  }
  for (fi=fr=0, i=1; i<=n; i++) if (cnt[i]==0) qq[fr++]=i;
  while (fi<fr) {
    i=qq[fi++];
    for (j=0; j<vv[i].size(); j++) if (--zz[vv[i][j]]==0) {
      x=vv[i][j];
      for (cur=e=0; e<g[x].size(); e++) {
        if (g[x][e]>0) cur+=pm[g[x][e]]; else cur++;
        if (cur>=mx) cur=mx;
      }
      pm[a[x]]=max(pm[a[x]],cur);
      if (--cnt[a[x]]==0) qq[fr++]=a[x];
    }
  }
  for (i=1; i<=n; i++) if (p[i]<inf) printf("%d %d\n",p[i],cnt[i]==0?pm[i]:-2); else puts("-1 -1");
  return 0;
}