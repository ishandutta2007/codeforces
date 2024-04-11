#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,d,x,y,i,r,mx[100100],mx2[100100];
bool b[100100];
vector<int> g[100100];
void dfs(int i, int p) {
  mx[i]=mx2[i]=int(b[i])-1;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
	if (k==p) continue;
	dfs(k,i);
	if (mx[k]>=0) {
	  if (mx[k]>=mx[i]) {
	    mx2[i]=mx[i];
		mx[i]=mx[k]+1;
	  } else if (mx[k]>=mx2[i]) mx2[i]=mx[k]+1;
	}
  }
}
void rfs(int i, int p, int mxup) {
  if (max(mxup,mx[i])<=d) r++;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j],cur;
	if (k==p) continue;
	if (mx[k]>=0 && mx[i]==mx[k]+1) cur=mx2[i]; else cur=mx[i];
	cur=max(cur,mxup);
	if (cur>=0) cur++;
	rfs(k,i,cur);
  }
}
int main() {
  scanf("%d%d%d",&n,&m,&d);
  for (i=0; i<m; i++) { scanf("%d",&x); b[x]=true; }
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
	g[x].push_back(y);
	g[y].push_back(x);
  }
  dfs(1,0);
  rfs(1,0,-1);
  printf("%d\n",r);
  return 0;
}