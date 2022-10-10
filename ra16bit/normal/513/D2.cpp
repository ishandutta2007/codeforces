#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,num,x,y,i,last,r[1000010];
vector<int> g[1000010][2];
char s[111];
bool q=true;
void dfs(int x) {
  int i=++last;
  if (g[i][0].size()) {
    sort(g[i][0].begin(),g[i][0].end());
    if (g[i][0][0]<=last) { q=false; return; }
    dfs(g[i][0].back());
    if (!q) return;
  }
  r[num++]=i;
  if (g[i][1].size()) {
    sort(g[i][1].begin(),g[i][1].end());
    if (g[i][1][0]<=last) { q=false; return; }
    dfs(max(x,g[i][1].back()));
  } else if (x>last) dfs(x);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    scanf("%s",s);
    g[x][int(s[0]=='R')].push_back(y);
  }
  dfs(n);
  if (q) {
    for (i=0; i<num; i++) printf("%d%c",r[i],(i==num-1)?'\n':' ');
  } else puts("IMPOSSIBLE");
  return 0;
}