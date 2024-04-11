#include <cstdio>
#include <vector>
using namespace std;
int i,j,n,t,st,r,x,cnt,a[202];
vector <int> g[202];
bool q,u[202];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) { scanf("%d",&a[i]); a[i]--; }
  for (i=1; i<=n; i++) {
    scanf("%d",&x);
	g[i].resize(x);
	for (j=0; j<x; j++) scanf("%d",&g[i][j]);
  }
  for (st=0; st<3; st++) {
    cnt=n;
	for (i=1; i<=n; i++) u[i]=true;
    for (t=st; ; t++) {
	  q=true;
	  while (q) {
	    q=false;
	    for (i=1; i<=n; i++) if (u[i] && a[i]==t%3) {
	      for (j=0; j<g[i].size(); j++) if (u[g[i][j]]) break;
		  if (j==g[i].size()) {
		    q=true; cnt--;
		    u[i]=false;
		  }
	    }
	  }
	  if (cnt==0) break;
	}
    if (st==0 || t-st<r) r=t-st;
  }
  printf("%d\n",r+n);
  return 0;
}