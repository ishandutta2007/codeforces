#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;
const int MX=1000100,MD=2*MX;
int n,m,i,j,k,x,y,z,fi,fr,v[MX],p[MX],q[2*MD];
vector<int> g[MX],o[MX];
bool u[MX];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
	g[x].push_back(y);
	o[y].push_back(x);
	v[x]++;
  }
  scanf("%d%d",&x,&y);
  memset(p,255,sizeof(p));
  p[y]=0; q[MD]=y; fi=MD; fr=fi+1;
  while (fi<fr) {
    i=q[fi++];
	if (i==x) break;
	if (u[i]) continue;
	u[i]=true;
	for (j=0; j<o[i].size(); j++) {
	  y=o[i][j];
	  if (--v[y]==0) {
		if (p[i]<p[y] || p[y]==-1) {
		  p[y]=p[i];
		  q[--fi]=y;
		}
	  } else if (p[y]==-1) {
	    p[y]=p[i]+1;
		q[fr++]=y;
	  }
	}
  }
  printf("%d\n",p[x]);
  return 0;
}