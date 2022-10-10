#include <cstdio>
#include <vector>
using namespace std;
int n,i,x,y,z,c[100100],s[100100];
vector <int> g[100100];
vector <bool> v[100100];
long long res;
void dfs(int i, int p) {
  s[i]=1;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    dfs(k,i);
    s[i]+=s[k];
    c[i]+=v[i][j]?s[k]:c[k];
  }
}
void solve(int i, int p,long long d) {
  if (d+c[i]>1) res+=(d+c[i])*(d+c[i]-1);
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    solve(k,i,v[i][j]?(n-s[k]):(c[i]-c[k]+d));
  }
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d%d",&x,&y,&z);
    for (; z>0; z/=10) if (z%10!=4 && z%10!=7) break;
    g[x].push_back(y); v[x].push_back(z==0);
    g[y].push_back(x); v[y].push_back(z==0);
  }
  dfs(1,0);
  solve(1,0,0);
  printf("%I64d\n",res);
  return 0;
}