#include <bits/stdc++.h>
using namespace std;
int n,m,i,x,y,cv,r;
vector<int> g[100100];//,f[100100];
bool u[100100];//,w[100100];
void dfs(int i) {
  u[i]=true; cv++;
  for (int j=0; j<g[i].size(); j++) {
    //int k=f[i][j];
    //if (!w[k]) { w[k]=true; ce++; }
    int k=g[i][j];
    if (!u[k]) dfs(k);
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);// f[x].push_back(i);
    g[y].push_back(x);// f[y].push_back(i);
  }
  for (i=1; i<=n; i++) if (!u[i]) {
    cv=0;
    dfs(i);
    r+=cv-1;
  }
  printf("%d\n",m-r);
  return 0;
}