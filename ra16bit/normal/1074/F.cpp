#include <bits/stdc++.h>
using namespace std;
const int MX=200200,BS=450,BC=MX/BS+10,inf=1000000000;
int n,num=-1,q,bc,i,j,x,y,px,py,r,d[MX],fi[MX],lst[MX],p[MX][19],v[MX],best[BC],bcnt[BC],a[BC];
vector<int> g[200200];
set<pair<int,int>> s;
void dfs(int i, int pr, int dep) {
  fi[i]=++num;
  d[i]=dep;
  p[i][0]=pr;
  for (int j=1; j<19; j++) p[i][j]=p[p[i][j-1]][j-1];
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
	if (k==pr) continue;
	dfs(k,i,dep+1);
  }
  lst[i]=num;
}
void upd(int b) {
  int sl=b*BS,sr=min(n,sl+BS);
  best[b]=inf;
  for (int i=sl; i<sr; i++) {
    v[i]+=a[b];
	if (v[i]<best[b]) { best[b]=v[i]; bcnt[b]=1; }
	  else if (v[i]==best[b]) bcnt[b]++;
  }
  a[b]=0;
}
void add(int x, int val) {
  int le=fi[x],ri=lst[x];
//  printf("[%d %d] %d\n",le,ri,val);
  int lb=le/BS,rb=ri/BS;
  if (lb==rb) {
    for (int i=le; i<=ri; i++) v[i]+=val;
	upd(lb);
    return;
  }
  int bnd=min(n,(lb+1)*BS);
  for (int i=le; i<bnd; i++) v[i]+=val;
  upd(lb);
  bnd=rb*BS;
  for (int i=bnd; i<=ri; i++) v[i]+=val;
  upd(rb);
  for (int i=lb+1; i<rb; i++) a[i]+=val;
}
int main() {
  scanf("%d%d",&n,&q);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
	g[x].push_back(y);
	g[y].push_back(x);
  }
  dfs(1,0,1);
  bc=(n-1)/BS;
  for (i=0; i<=bc; i++) {
    x=i*BS;
	y=min(n,x+BS);
	bcnt[i]=y-x;
  }
  while (q--) {
    scanf("%d%d",&x,&y);
	if (x>y) swap(x,y);
	auto it=s.find({x,y});
	px=x; py=y;
	if (d[x]>d[y]) for (j=18; j>=0; j--) if (d[px]-(1<<j)>d[py]) px=p[px][j];
	if (d[x]<d[y]) for (j=18; j>=0; j--) if (d[py]-(1<<j)>d[px]) py=p[py][j];
	if (p[px][0]==py) {
	  add(px,(it==s.end())?1:-1);
	  add(x,(it==s.end())?-1:1);
	} else if (p[py][0]==px) {
	  add(py,(it==s.end())?1:-1);
	  add(y,(it==s.end())?-1:1);
	} else {
	  add(1,(it==s.end())?1:-1);
	  add(x,(it==s.end())?-1:1);
	  add(y,(it==s.end())?-1:1);
	}
	if (it==s.end()) s.insert({x,y}); else s.erase(it);
	for (r=i=0; i<=bc; i++) if (best[i]+a[i]==0) r+=bcnt[i];
	printf("%d\n",r);
  }
  return 0;
}