#include <bits/stdc++.h>
using namespace std;
int n,i,j,x,y,p[3030][3030],s[3030][3030];
long long f[3030][3030],res;
vector<int> g[3030];
void dfs(int v, int pr) {
  p[i][v]=pr;
  s[i][v]=1;
  for (int j=0; j<g[v].size(); j++) {
    int k=g[v][j];
    if (k==pr) continue;
    dfs(k,v);
    s[i][v]+=s[i][k];
  }
}
long long F(int i, int j) {
  if (f[i][j]) return f[i][j];
  if (p[i][j]==i) return f[i][j]=f[j][i]=s[i][j]*s[j][i];
  return f[i][j]=f[j][i]=s[i][j]*s[j][i]+max(F(i,p[i][j]),F(j,p[j][i]));
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=1; i<=n; i++) dfs(i,0);
  for (i=1; i<=n; i++) for (j=i+1; j<=n; j++) res=max(res,F(i,j));
  printf("%I64d\n",res);
  return 0;
}