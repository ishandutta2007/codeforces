#include <cstdio>
#include <vector>
using namespace std;
int n,m,h,t,x,y,i,j,it,u[100100],f[100100];
vector <int> g[100100],first,second;
bool solve(int x, int y) {
  if (g[x].size()<=h) return false;
  if (g[y].size()<=t) return false;
  ++it;
  int T=t,tot=0;
  first.clear();
  for (int i=0; i<g[x].size(); i++) {
    int k=g[x][i];
    if (k==y) continue;
    if (u[k]==y) {
      tot++;
      f[k]=it;
      continue;
    }
    first.push_back(k);
    if (first.size()==h) break;
  }
  if (int(first.size())+int(g[y].size())-1>=h+t) {
    for (int i=0; i<g[y].size(); i++) {
      int k=g[y][i];
      if (k==x || f[k]==it) continue;
      second.push_back(k);
      if (second.size()==t) break;
    }
    for (int i=1; i<=n; i++) if (f[i]==it) {
      if (first.size()<h) first.push_back(i); else 
        if (second.size()<t) second.push_back(i);
    }
    if (first.size()!=h || second.size()!=t) return false;
    puts("YES");
    printf("%d %d\n",x,y);
    for (int i=0; i<first.size(); i++) printf("%d%c",first[i],(i+1==first.size())?'\n':' ');
    for (int i=0; i<second.size(); i++) printf("%d%c",second[i],(i+1==second.size())?'\n':' ');
    return true;
  }
  return false;
}
int main() {
  scanf("%d%d%d%d",&n,&m,&h,&t);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=1; i<=n; i++) {
    for (j=0; j<g[i].size(); j++) u[g[i][j]]=i;
    for (j=0; j<g[i].size(); j++) if (solve(g[i][j],i)) return 0;
  }
  puts("NO");
  return 0;
}