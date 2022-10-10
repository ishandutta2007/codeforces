#include <bits/stdc++.h>
using namespace std;
const int MX=405,md=998244353;
int n,m,x,y,i,j,k,it,cur,fi,fr,q[MX],w[MX],d[MX][MX],r[MX][MX];
vector<int> g[MX];
void bfs(int st) {
  q[fi=0]=st; 
  d[st][st]=0;
  for (fr=1; fi<fr; fi++) {
    int x=q[fi];
    for (int y: g[x]) if (d[st][y]==-1) {
      d[st][y]=d[st][x]+1;
      q[fr++]=y;
    }
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  memset(d,255,sizeof(d));
  for (i=1; i<=n; i++) bfs(i);
  for (i=1; i<=n; i++) for (j=1; j<=i; j++) {
    ++it;
    for (k=1; k<=n; k++) {
      /*if (d[i][k]+d[j][k]!=d[i][j] && d[i][k]+d[i][j]!=d[j][k] && d[i][j]+d[j][k]!=d[i][k]) {
      if (i==6 && j==5) printf("# %d (%d %d %d)\n",k,d[i][j],d[i][k],d[k][j]);
      break;
      }*/
      if (d[i][k]+d[j][k]==d[i][j]) {
        if (w[d[i][k]]==it) break;
        w[d[i][k]]=it;
      }
    }
    if (k<=n) continue;
    cur=1;
    for (k=1; k<=n; k++) if (d[i][k]+d[j][k]!=d[i][j]) {
      long long cnt=0;
      for (int prv: g[k]) if (d[i][prv]+1==d[i][k] && d[j][prv]+1==d[j][k]) ++cnt;
      cur=(cur*cnt)%md;
    }
    r[i][j]=cur;
    r[j][i]=cur;
  }
  for (i=1; i<=n; i++, puts("")) for (j=1; j<=n; j++) printf("%d ",r[i][j]);
  return 0;
}