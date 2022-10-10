#include <cstdio>
#include <vector>
using namespace std;
int n,i,x,y;
vector<int> g[100100];
int dfs(int i, int p) {
  int c[7];
  for (int j=0; j<7; j++) c[j]=0;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    int x=dfs(k,i);
    c[x]++;
  }
  if (c[0]>0 || c[3]>2 || c[4]>1 || c[5]>1 || c[6]>0) return 0;
  if (c[5]>0) {
    if (c[1]>1 || c[2]>0 || c[3]>0 || c[4]>0) return 0;
    return 5+c[1];
  }
  if (c[4]>0) {
    if (c[3]>0 || c[1]>2 || c[2]>0) return 0;
    return 5+int(c[1]==2);
  }
  if (c[3]==2) return 4;
  if (c[3]>0 || c[1]>2 || c[2]>0) return 3;
  return 1+int(c[1]==2);
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  puts(dfs(1,0)?"Yes":"No");
  return 0;
}