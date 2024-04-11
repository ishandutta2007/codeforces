#include <cstdio>
#include <algorithm>
using namespace std;
int i,n,m,x,y,z,v[1010],g[1010],f[1010],r,r1[1010],r2[1010],r3[1010];
void dfs(int s, int i, int k) {
  if (g[i]==0) {
    if (k!=100000000) { r1[r]=s; r2[r]=i; r3[r++]=k; }
  } else dfs(s,g[i],min(k,f[i]));
}
int main() {
  scanf("%d%d",&n,&m);
  while (m--) {
    scanf("%d%d%d",&x,&y,&z);
    g[x]=y; f[x]=z; v[y]++;
  }
  for (i=1; i<=n; i++) if (v[i]==0) dfs(i,i,100000000);
  printf("%d\n",r);
  for (i=0; i<r; i++) printf("%d %d %d\n",r1[i],r2[i],r3[i]);
  return 0;
}