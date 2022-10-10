#include <bits/stdc++.h>
using namespace std;
int n,m,i,x,y,res;
vector<int> g[200200],o[200200];
bool u[3][200200],w[200200],ok=true;
char r[200200];
void dfs(int i, int z) {
  u[z][i]=true;
  w[i]=true;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (w[k]) ok=false;
    if (!u[z][k]) dfs(k,z);
  }
  w[i]=false;
}
void ofs(int i, int z) {
  u[z][i]=true;
  for (int j=0; j<o[i].size(); j++) {
    int k=o[i][j];
    if (!u[z][k]) ofs(k,z);
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    o[y].push_back(x);
  }
  for (i=1; ok && i<=n; i++) if (!u[0][i]) dfs(i,0);
  if (!ok) { puts("-1"); return 0; }
  memset(u,0,sizeof(u));
  for (i=1; i<=n; i++) if (!u[0][i] && !u[1][i] && !u[2][i]) {
    dfs(i,0);
    ofs(i,0);
    r[i-1]='A';
    res++;
  } else {
    r[i-1]='E';
    if (!u[1][i]) dfs(i,1);
    if (!u[2][i]) ofs(i,2);
  }
  printf("%d\n",res);
  puts(r);
  return 0;
}