#include <bits/stdc++.h>
using namespace std;
const int MX=525525;
struct Node {
  int dep[2],add;
} seg[2][MX*2];  
int n,q,i,cur,w,mx,x,y,z[MX],dwn[2][MX],fi[2][MX],lst[2][MX],a[2][MX],d[2][MX],T[2];
vector<int> g[MX],e[MX];
void init(int cur, int i, int L, int R) {
  if (L==R) {
    for (int j=0; j<2; j++) seg[cur][i].dep[j]=-1;
    seg[cur][i].dep[a[cur][R]]=d[cur][R];
    return;
  }
  int h=(L+R)/2;
  init(cur,i*2,L,h);
  init(cur,i*2+1,h+1,R);
  for (int j=0; j<2; j++) seg[cur][i].dep[j]=max(seg[cur][i*2].dep[j],seg[cur][i*2+1].dep[j]);
}
void mdf(int cur, int i, int L, int R, int le, int ri) {
  if (L==le && R==ri) {
    seg[cur][i].add^=1;
    swap(seg[cur][i].dep[0],seg[cur][i].dep[1]);
    return;
  }
  int h=(L+R)/2;
  if (le<=h) mdf(cur,i*2,L,h,le,min(ri,h));
  if (ri>h) mdf(cur,i*2+1,h+1,R,max(le,h+1),ri);
  for (int j=0; j<2; j++) seg[cur][i].dep[j]=max(seg[cur][i*2].dep[j],seg[cur][i*2+1].dep[j]);
  if (seg[cur][i].add) swap(seg[cur][i].dep[0],seg[cur][i].dep[1]);
}
void dfs(int i, int p, int dep, int xx) {
  fi[cur][i]=++T[cur];
  a[cur][T[cur]]=xx;
  d[cur][T[cur]]=dep;
  if (dep>mx) { mx=dep; w=i; }
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    int ed=e[i][j];
    dwn[cur][ed]=k;
    dfs(k,i,dep+1,(xx^z[ed]));
  }
  lst[cur][i]=T[cur];
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d%d",&x,&y,&z[i]);
    g[x].push_back(y); e[x].push_back(i);
    g[y].push_back(x); e[y].push_back(i);
  }
  dfs(1,0,0,0);
  x=w; w=mx=0; T[0]=0;
  dfs(x,0,0,0);
  y=w; ++cur;
  dfs(y,0,0,0);
  for (i=0; i<2; i++) init(i,1,1,n);
  scanf("%d",&q);
  while (q--) {
    scanf("%d",&w);
    for (i=0; i<2; i++) mdf(i,1,1,n,fi[i][dwn[i][w]],lst[i][dwn[i][w]]);
    printf("%d\n",max(seg[0][1].dep[0],seg[1][1].dep[0]));
  }
  return 0;
}