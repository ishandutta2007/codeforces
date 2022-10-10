#include <cstdio>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, pair<int,int> > piii;
typedef pair<long long, pair<int,int> > pllii;
int n,m,i,j,k,x,y,z,zz,e,ans[10100];
long long p[2][10100];
vector<piii> g[10100];
vector<int> ed[10100];
bool u[2][10100];
priority_queue<pllii, vector<pllii>, greater<pllii> > q;
int main() {
  scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&e);
  memset(p,255,sizeof(p));
  p[0][x]=p[0][y]=0;
  q.push(make_pair(0,make_pair(0,x)));
  q.push(make_pair(0,make_pair(1,y)));
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x,&y,&z);
    g[x].push_back(make_pair(y,make_pair(z,z)));
    ed[x].push_back(k);
  }
  for (i=0; i<k; i++) {
    scanf("%d%d%d%d",&x,&y,&z,&zz);
    g[x].push_back(make_pair(y,make_pair(z,zz)));
    ed[x].push_back(i);
    ans[i]=z;
  }
  while (!q.empty()) {
    long long z=q.top().first;
    x=q.top().second.first;
    y=q.top().second.second;
    q.pop();
    if (u[x][y]) continue;
    u[x][y]=true;
    for (j=0; j<g[y].size(); j++) {
      i=g[y][j].first;
      if (u[1-x][y]) {
        if (x) zz=g[y][j].second.first; else zz=g[y][j].second.second;
      } else {
        if (x) zz=g[y][j].second.second; else zz=g[y][j].second.first;
        ans[ed[y][j]]=zz;
      }
      if (p[x][i]==-1 || z+zz<p[x][i]) {
        p[x][i]=z+zz;
        q.push(make_pair(z+zz,make_pair(x,i)));
      }
    }
  }
  for (i=0; i<2; i++) for (j=0; j<=n; j++) if (p[i][j]==-1) p[i][j]=1000000000000000000LL;
  if (p[0][e]<=p[1][e]) {
    puts(p[0][e]<p[1][e]?"WIN":"DRAW");
    for (i=0; i<k; i++) printf("%d%c",ans[i],(i==k-1)?'\n':' ');
  } else puts("LOSE");
  return 0;
}