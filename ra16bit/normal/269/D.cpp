#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
const int inf=1000000000;
struct pnt { int x,i; bool d; } a[200200];
int n,m,t,i,ii,j,x,L,R,h[100100],l[100100],r[100100],f[100100],k[100100];
set<pair<int,int> > s,e;
set<pair<int,int> >::iterator it;
vector<int> g[100100];
bool u[100100];
bool cmp(pnt x, pnt y) {
  if (x.x!=y.x) return x.x<y.x;
  if (x.d!=y.d) return x.d;
  return x.i<y.i;
}
bool cmh(int i, int j) { return h[i]<h[j]; }
void dfs(int i) {
  u[i]=true;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
	if (!u[k]) dfs(k);
	f[i]=max(f[i],min(f[k],min(r[i],r[k])-max(l[i],l[k])));
  }
}
int main() {
  scanf("%d%d,",&n,&t);
  //n=100000;
  //t=inf;
  l[0]=-inf; r[0]=inf; h[0]=0;
  l[n+1]=-inf; r[n+1]=inf; h[n+1]=t;
  for (i=1; i<=n; i++) {
    scanf("%d%d%d",&h[i],&l[i],&r[i]);
	//h[i]=i;
	//l[i]=-i;
	//r[i]=i;
	a[m].x=l[i]; a[m].i=i; a[m++].d=false;
	a[m].x=r[i]; a[m].i=i; a[m++].d=true;
	k[i]=i;
  }
  sort(a,a+m,cmp);
  s.insert(make_pair(0,0));
  s.insert(make_pair(t,n+1));
  for (i=0; i<m; i++) if (a[i].d) {
    it=s.find(make_pair(h[a[i].i],a[i].i));
    if (it!=s.end()) s.erase(it);
	//printf("del %d\n",a[i].i);
	//for (it=s.begin(); it!=s.end(); it++) printf("(%d %d), ",it->first,it->second); puts("");
  } else {
  //printf("go %d\n",a[i].i);
  //for (it=s.begin(); it!=s.end(); it++) printf("(%d %d), ",it->first,it->second); puts("");
    it=s.lower_bound(make_pair(h[a[i].i],0));
	R=it->second;
	--it;
	L=it->second;
	//printf("%d %d\n",L,R);
	it=e.find(make_pair(L,R));
	if (it!=e.end()) e.erase(it);
	e.insert(make_pair(L,a[i].i));
	e.insert(make_pair(a[i].i,R));
	s.insert(make_pair(h[a[i].i],a[i].i));
  }
  int res=0;
  for (it=e.begin(); it!=e.end(); it++, res++) g[it->first].push_back(it->second);
  //printf("%d\n",res);
  sort(k,k+n+2,cmh);
  f[0]=2000000000;
  for (ii=0; ii<=n+1; ii++) {
    i=k[ii];
	for (j=0; j<g[i].size(); j++) {
	  x=g[i][j];
	  f[x]=max(f[x],min(f[i],min(r[i],r[x])-max(l[i],l[x])));
	}
  }
  printf("%d\n",f[n+1]);
  return 0;
}