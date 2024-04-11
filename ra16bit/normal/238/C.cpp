#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int i,n,it,X,Y,r=1000000000,c[3003],x[3003],y[3003];
vector <int> g[3003];
void cfs(int i, int p) {
  c[i]=0;
  for (int j=0; j<g[i].size(); j++) {
    int e=g[i][j],k=x[e]+y[e]-i;
	if (k==p) continue;
	cfs(k,i);
	if (e!=it) c[i]+=c[k]+int(y[e]==i);
  }
}
void dfs(int i, int p, int v, bool isX) {
  if (isX) X=min(X,v+c[i]); else Y=min(Y,v+c[i]);
  for (int j=0; j<g[i].size(); j++) {
    int e=g[i][j],k=x[e]+y[e]-i;
	if (k==p) continue;
	if (e==it) {
	  dfs(k,i,0,!isX);
	  continue;
	}
	dfs(k,i,v+c[i]-c[k]-int(y[e]==i)+int(y[e]==k),isX);
  }
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x[i],&y[i]);
	g[x[i]].push_back(i);
	g[y[i]].push_back(i);
  }
  for (it=0; it<n; it++) {
    cfs(1,0);
    X=r;
    if (it==0) Y=0; else Y=r;
    dfs(1,0,0,true);
	r=min(r,X+Y);
  }
  printf("%d\n",r);
  return 0;
}