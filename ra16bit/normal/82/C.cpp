#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,i,x,y,z,a[5050],b[5050],c[5050],d[5050],e[5050],k[5050],p[5050];
vector <int> g[5050],f[5050];
bool q;
bool cmp(int i, int j) { return a[i]<a[j]; }
void dfs(int i, int pr, int fr) {
  p[i]=pr; c[i]=fr;
  for (int j=0; j<g[i].size(); j++) if (g[i][j]!=pr) dfs(g[i][j],i,f[i][j]);
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&a[i]); b[i]=i; k[i]=i; }
  sort(k,k+n,cmp);
  for (i=1; i<n; i++) {
    scanf("%d%d%d",&x,&y,&z);
    x--; y--;
    g[x].push_back(y); f[x].push_back(z);
    g[y].push_back(x); f[y].push_back(z);
  }
  dfs(0,0,0); q=true;
  while (q) {
    for (q=i=0; i<n; i++) d[i]=0;
    for (i=0; i<n; i++) if (b[k[i]]) e[k[i]]++;
    for (i=0; i<n; i++) if (d[b[k[i]]]<c[b[k[i]]]) {
      q=true; d[b[k[i]]]++; b[k[i]]=p[b[k[i]]];
    }
  }
  for (i=0; i<n; i++) {
    if (i) putchar(' ');
    printf("%d",e[i]);
  }
  return 0;
}