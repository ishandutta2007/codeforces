#include <cstdio>
#include <vector>
using namespace std;
int n,m,x,y,i,cnt,c[100100],z[100100],a[100100],b[100100];
vector<int> g[100100],f[100100];
bool u[500500],w[100100];
vector<pair<int,int> > r;
void dfs(int i) {
  for (; c[i]<g[i].size(); c[i]++) {
    int k=g[i][c[i]];
    int e=f[i][c[i]];
    if (!u[e]) {
      bool need=!w[k];
      w[k]=true;
      u[e]=true;
      dfs(k);
      if (need && a[k]%2==1) {
      r.push_back(make_pair(i,k));
      a[k]++; b[i]++;
      } else {
      r.push_back(make_pair(k,i));
      a[i]++; b[k]++;
      }
    }
  }
  if (c[i]==g[i].size()) for (int j=0; j<z[i]; j++) {
  r.push_back(make_pair(i,i));
  a[i]++; b[i]++;
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    if (x!=y) {
      g[x].push_back(y); f[x].push_back(i);
      g[y].push_back(x); f[y].push_back(i);
    } else z[x]++;
  }
  for (x=0, i=1; i<=n; i++) if (g[i].size()%2) {
    if (x) {
      g[x].push_back(i); f[x].push_back(m);
      g[i].push_back(x); f[i].push_back(m);
      m++; x=0;
    } else x=i;
  } /*else if ((g[i].size()+z[i]*2)%4==2) {
    cnt++; y=i;
  }
  if (cnt%2) { z[y]++; m++; }*/
  dfs(y);
  if (a[y]%2) {
  r.push_back(make_pair(y,y));
  a[y]++;b[y]++;
  }
  printf("%d\n",int(r.size()));
  for (i=0; i<r.size(); i++) printf("%d %d\n",r[i].first,r[i].second);
  //for (i=1; i<=n; i++) if (a[i]%2!=0 || b[i]%2!=0) printf("%d\n",i/=0);
  return 0;
}