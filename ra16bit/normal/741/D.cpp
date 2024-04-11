#include <cstdio>
#include <vector>
using namespace std;
const int MX=500500;
int T,n,i,x,s[MX],w[MX],a[MX],dep[MX],fi[MX],la[MX],r[MX],best[1<<22];
vector<int> g[MX],f[MX];
char st[5];
void dfs(int i) {
  w[i]=0;
  s[i]=1;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    dfs(k);
    if (s[k]>s[g[i][w[i]]]) w[i]=j;
    s[i]+=s[k];
  }
}
void tryAdd(int i, int d, int e) {
  int cur=a[e];
  if (best[cur]>0) r[i]=max(r[i],dep[e]+best[cur]-2*d);
  for (int b=0; b<22; b++) {
    int v=cur^(1<<b);
    if (best[v]>0) r[i]=max(r[i],dep[e]+best[v]-2*d);
  }
}
void solve(int i, bool save, int d, int x) {
  a[++T]=x; dep[T]=d; fi[i]=T;
  for (int j=0; j<g[i].size(); j++)
    if (j!=w[i]) solve(g[i][j],false,d+1,x^(1<<f[i][j]));
  if (!g[i].empty()) solve(g[i][w[i]],true,d+1,x^(1<<f[i][w[i]]));
  la[i]=T;
  tryAdd(i,d,fi[i]);
  best[x]=max(best[x],d);
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    r[i]=max(r[i],r[k]);
    if (j==w[i]) continue;
    for (int e=fi[k]; e<=la[k]; e++) tryAdd(i,d,e);
    for (int e=fi[k]; e<=la[k]; e++) best[a[e]]=max(best[a[e]],dep[e]);
  }
  if (!save) for (int j=fi[i]; j<=la[i]; j++) best[a[j]]=0;
}
int main() {
  scanf("%d",&n);
  for (i=2; i<=n; i++) {
    scanf("%d",&x);
    scanf("%s",st);
    g[x].push_back(i);
    f[x].push_back(st[0]-'a');
  }
  dfs(1);
  solve(1,true,1,0);
  for (i=1; i<=n; i++) printf("%d%c",r[i],(i==n)?'\n':' ');
  return 0;
}