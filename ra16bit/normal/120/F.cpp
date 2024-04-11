#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;
int t,n,i,j,k,x,y,p[111],q[111],fi,fr,r;
vector <int> g[111];
void bfs(int s) {
  memset(p,255,sizeof(p));
  p[s]=0; q[0]=s; fi=0; fr=1;
  while (fi<fr) {
    i=q[fi++];
    for (j=0; j<g[i].size(); j++) {
      k=g[i][j];
      if (p[k]==-1) {
        p[k]=p[i]+1;
        q[fr++]=k;
      }
    }
  }
}
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=1; i<=n; i++) g[i].clear();
    for (i=1; i<n; i++) {
      scanf("%d%d",&x,&y);
      g[x].push_back(y);
      g[y].push_back(x);
    }
    bfs(1);
    bfs(q[fr-1]);
    r+=p[q[fr-1]];
  }
  printf("%d\n",r);
  return 0;
}