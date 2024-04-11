#include <cstdio>
#include <vector>
using namespace std;
int n,m,k,w,i,j,x,y,cur,p[1010],rk[1010],r;
char s[1010][12][12];
bool u[1010];
vector<pair<int,int> > v[1010],all;
vector<int> g[1010];
int fs(int i) {
  if (p[i]!=i) p[i]=fs(p[i]);
  return p[i];
}
bool un(int i, int j) {
  if (i==j) return false;
  if (rk[i]<rk[j]) {
    p[i]=j;
  } else {
    if (rk[i]==rk[j]) rk[i]++;
    p[j]=i;
  }
  return true;
}
void dfs(int i) {
  u[i]=true;
  for (int j=0; j<g[i].size(); j++) if (!u[g[i][j]]) {
    printf("%d %d\n",g[i][j]+1,i+1);
    dfs(g[i][j]);
  }
}
int main() {
  scanf("%d%d%d%d",&n,&m,&k,&w);
  for (i=0; i<k; i++) {
    for (x=0; x<n; x++) scanf("%s",s[i][x]);
    for (j=0; j<i; j++) {
      for (cur=x=0; x<n; x++) for (y=0; y<m; y++) if (s[i][x][y]!=s[j][x][y]) cur++;
      if (cur*w<n*m) v[cur*w].push_back(make_pair(i,j));
    }
    p[i]=i;
    r+=n*m;
  }
  for (i=0; i<n*m; i++) for (j=0; j<v[i].size(); j++) if (un(fs(v[i][j].first),fs(v[i][j].second))) {
    r+=i-n*m;
    g[v[i][j].first].push_back(v[i][j].second);
    g[v[i][j].second].push_back(v[i][j].first);
  }
  printf("%d\n",r);
  for (i=0; i<k; i++) if (!u[i]) {
    printf("%d 0\n",i+1,k);
    dfs(i);
  }
  return 0;
}