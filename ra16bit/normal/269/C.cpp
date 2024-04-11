#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
int n,m,x[200200],y,z,i,j,k,s[200200],v[200200],ans[200200];
vector<int> g[200200],f[200200],e[200200];
bool was[200200];
priority_queue<pii, vector<pii>, greater<pii> > q;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x[i],&y,&z);
	g[x[i]].push_back(y); f[x[i]].push_back(z); e[x[i]].push_back(i); v[x[i]]+=z;
	g[y].push_back(x[i]); f[y].push_back(z); e[y].push_back(i); v[y]+=z;
  }
  q.push(make_pair(0,1));
  while (!q.empty()) {
    i=q.top().second;
	q.pop();
	if (was[i]) continue;
	was[i]=true;
	for (j=0; j<g[i].size(); j++) {
	  k=g[i][j];
	  if (was[k]) continue;
	  s[k]+=f[i][j];
	  if (k!=n) q.push(make_pair(v[k]/2-s[k],k));
	  ans[e[i][j]]=int(x[e[i][j]]==k);
	}
  }
  for (i=0; i<m; i++) printf("%d\n",ans[i]);
  return 0;
}