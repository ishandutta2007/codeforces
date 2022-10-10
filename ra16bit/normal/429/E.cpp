#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,i,x,y,o,c[100100];
pair<int,int> a[200200];
vector<int> g[100100],f[100100];
bool q=true;
void dfs(int i, int cc) {
  if (c[i]!=0) {
    if (c[i]!=cc) q=false;
    return;
  }
  c[i]=cc;
  for (int j=0; j<g[i].size(); j++) dfs(g[i][j],3-cc);
  for (int j=0; j<f[i].size(); j++) dfs(f[i][j],cc);
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x,&y);
    x=x*2; y=y*2+1;
    a[2*i].first=x;   a[2*i].second=i;
    a[2*i+1].first=y; a[2*i+1].second=i;
  }
  sort(a,a+2*n);
  for (o=-1, i=0; i<2*n; i++) if (a[i].first&1) {
    if (o>=0) {
      if (o!=a[i].second) {
        x=g[a[i].second][0];
        g[x].push_back(o);
        g[o].push_back(x);
      }
      o=-1;
    } else o=g[a[i].second][0];
  } else if (o>=0) {
    g[a[i].second].push_back(o);
    g[o].push_back(a[i].second);
    o=-1;
  } else o=a[i].second;
  for (i=0; i<n; i++) if (c[i]==0 && q) dfs(i,1);
  if (q) for (i=0; i<n; i++) printf("%d%c",c[i]-1,(i==n-1)?'\n':' '); else puts("-1");
  return 0;
}