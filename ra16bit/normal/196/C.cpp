#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int i,j,b,n,m,x[1515],y[1515],r[1515],cnt[1515],k[1515*1500];
vector <int> g[1515];
bool u[1515];
long long cx,cy;
bool cmp(int i, int j) {
//printf("%d %d cmp (%I64d %I64d) (%I64d %I64d) = %I64d\n",i,j,x[i]-cx,y[i]-cy,x[j]-cx,y[j]-cy,(x[i]-cx)*(y[j]-cy)-(y[i]-cy)*(x[j]-cx));
  return (x[i]-cx)*(y[j]-cy)-(y[i]-cy)*(x[j]-cx)>0;
}
void cntfs(int i, int p) {
  cnt[i]=1;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    cntfs(k,i);
    cnt[i]+=cnt[k];
  }
}
void dfs(int v, int p, int i, int px, int py, int lo, int hi) {
  r[i]=v+1;
  u[i]=true;
  cx=x[i];
  cy=y[i];
  sort(k+lo,k+hi,cmp);
  //for (int i=lo; i<hi; i++) for (int j=i+1; j<hi; j++) if (!cmp(k[i],k[j])) { printf("%d\n",1/0); puts("!"); return; }
  //printf("dfs %d %d (%d %d %d) [%d %d]\n",v,p,i,px,py,lo,hi);
  //for (int i=lo; i<hi; i++) printf("%d ",k[i]); puts("");
  int pnt=lo;
  for (int j=0; j<g[v].size(); j++) {
    int next=g[v][j],nextpnt,oldm=m;
    if (next==p) continue;
    for (int cc=0; cc!=cnt[next]; pnt++) if (!u[k[pnt]]) {
      if (++cc==1) nextpnt=k[pnt]; else k[m++]=k[pnt];
    }
    dfs(next,v,nextpnt,x[i],y[i],oldm,m);
  }
}
int main() {
  scanf("%d",&n); m=n;
  for (i=1; i<n; i++) {
    int x,y;
    scanf("%d%d",&x,&y);
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (b=i=0; i<n; i++) {
    scanf("%d%d",&x[i],&y[i]);
    if (i>0 && (y[i]<y[b] || (y[i]==y[b] && x[i]<x[b]))) b=i;
  }
  for (i=0; i<n; i++) k[i]=i;
  k[b]=k[n-1];
  cntfs(0,-1);
  dfs(0,-1,b,x[b]-1,y[b],0,n-1);
  for (i=0; i<n; i++) printf("%d%c",r[i],(i<n-1)?' ':'\n');
  return 0;
}