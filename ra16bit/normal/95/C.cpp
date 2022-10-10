#include <cstdio>
#include <vector>
#include <set>
#include <utility>
using namespace std;
int aa,bb,cc,i,j,n,m,x,y,T,c[1010];
long long p[1010],inf=2000000000000000000LL;
set <pair <long long, int> > s;
vector <int> g[1010],f[1010],r[1010];
void dijkstra(int st) {
  int i,j,k;
  long long z;
  for (i=0; i<n; i++) p[i]=inf;
  p[st]=0; s.insert(make_pair(0LL,st));
  while (!s.empty()) {
    i=s.begin()->second;
	z=s.begin()->first;
	s.erase(s.begin());
    for (j=0; j<g[i].size(); j++) {
	  k=g[i][j];
	  if (z+f[i][j]<p[k]) {
	    if (p[k]!=inf) s.erase(s.find(make_pair(p[k],k)));
		p[k]=z+f[i][j];
		s.insert(make_pair(p[k],k));
	  }
	}
  }
}
int main() {
  scanf("%d%d",&n,&m);
  scanf("%d%d",&x,&y); x--; y--;
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&aa,&bb,&cc); aa--; bb--;
	g[aa].push_back(bb); f[aa].push_back(cc);
	g[bb].push_back(aa); f[bb].push_back(cc);
  }
  for (i=0; i<n; i++) {
    scanf("%d%d",&T,&c[i]);
    dijkstra(i);
	for (j=0; j<n; j++) if (j!=i && p[j]<=T) r[i].push_back(j);
  }
  for (i=0; i<n; i++) {
    g[i].clear(); f[i].clear();
	for (j=0; j<r[i].size(); j++) {
	  g[i].push_back(r[i][j]);
	  f[i].push_back(c[i]);
	}
  }
  dijkstra(x);
  if (p[y]>=inf) p[y]=-1;
  printf("%I64d\n",p[y]);
  return 0;
}