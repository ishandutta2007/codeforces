#include <cstdio>
#include <queue>
using namespace std;
typedef pair<long long, pair<int, int> > node;
int n,m,k,x,y,z,r,i,j;
vector<int> g[100100],f[100100];
long long p[100100][2],len,cur,inf=1000000000;
priority_queue<node, vector<node>, greater<node> > q;
int main() {
  inf*=inf;
  scanf("%d%d%d",&n,&m,&k);
  while (m--) {
    scanf("%d%d%d",&x,&y,&z);
    g[x].push_back(y); f[x].push_back(z);
    g[y].push_back(x); f[y].push_back(z);
  }
  for (i=1; i<=n; i++) for (j=0; j<2; j++) p[i][j]=inf;
  p[1][0]=0;
  q.push(make_pair(0,make_pair(1,0)));
  while (k--) {
    scanf("%d%d",&x,&y);
    if (p[x][1]!=inf) r++;
    p[x][1]=min(p[x][1],1LL*y);
  }
  for (i=1; i<=n; i++) if (p[i][1]!=inf)
    q.push(make_pair(p[i][1],make_pair(i,1)));
  while (!q.empty()) {
    len=q.top().first;
    i=q.top().second.first;
    j=q.top().second.second;
    q.pop();
    if (p[i][j]!=len) continue;
    for (int e=0; e<g[i].size(); e++) {
      x=g[i][e];
      cur=len+f[i][e];
      if (cur<p[x][0]) {
        p[x][0]=cur;
        q.push(make_pair(cur,make_pair(x,0)));
      }
    }
  }
  for (i=1; i<=n; i++) if (p[i][1]!=inf && p[i][1]>=p[i][0]) r++;
  printf("%d\n",r);
  return 0;
}