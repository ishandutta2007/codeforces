#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,i,x,y,z;
struct thr { int f; long long s,t; } a[100100],b[100100];
vector <int> f[100100],g[100100];
bool cmp(thr i, thr j) {
  return i.s*j.f<j.s*i.f;
}
void dfs(int i, int p) {
  int j,k;
  for (j=0; j<g[i].size(); j++) {
    k=g[i][j];
    if (k!=p) dfs(k,i);
  }
  for (m=j=0; j<g[i].size(); j++) {
    k=g[i][j];
    if (k==p) continue;
    b[m].f=a[k].f;
    b[m].s=a[k].s+f[i][j]*2;
    b[m++].t=a[k].t+f[i][j]*a[k].f;
  }
  sort(b,b+m,cmp);
  a[i].f=1;
  for (j=0; j<m; j++) {
    a[i].f+=b[j].f;
    a[i].t+=a[i].s*b[j].f+b[j].t;
    a[i].s+=b[j].s;
  }
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d%d",&x,&y,&z);
    g[x].push_back(y); f[x].push_back(z);
    g[y].push_back(x); f[y].push_back(z);
  }
  dfs(1,0);
  printf("%.8lf\n",double(a[1].t)/(n-1.0));
  return 0;
}