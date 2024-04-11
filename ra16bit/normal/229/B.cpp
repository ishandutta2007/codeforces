#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef pair <int, int> pii;
const int MX=100100;
int n,m,i,j,x,y,z,zz,p[MX],inf;
vector <int> g[MX],f[MX],t[MX];
priority_queue <pii, vector <pii>, greater <pii> > q;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x,&y,&z);
	g[x].push_back(y); f[x].push_back(z);
	g[y].push_back(x); f[y].push_back(z);
  }
  for (i=1; i<=n; i++) {
    scanf("%d",&x);
	while (x--) {
	  scanf("%d",&y);
	  t[i].push_back(y);
	}
	sort(t[i].begin(),t[i].end());
  }
  memset(p,120,sizeof(p));
  inf=p[1]; p[1]=0;
  q.push(make_pair(p[1],1));
  while (!q.empty()) {
    x=q.top().second;
	z=q.top().first;
	q.pop();
	if (p[x]<z) continue;
	if (t[x].size()>0) {
	  for (j=t[x].size()-1; j>=0; j--) if (t[x][j]<=z) break;
	  if (j>=0) for (; j<t[x].size(); j++, z++) if (t[x][j]!=z) break;
	}
	zz=z;
	for (j=0; j<g[x].size(); j++) {
	  y=g[x][j]; z=zz+f[x][j];
	  if (z<p[y]) { p[y]=z; q.push(make_pair(z,y)); }
	}
  }
  if (p[n]>=inf) puts("-1"); else printf("%d\n",p[n]);
  return 0;
}