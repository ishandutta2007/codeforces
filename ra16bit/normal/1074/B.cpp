#include <bits/stdc++.h>
using namespace std;
int t,it,ans,n,i,j,x,y,k,z,fi,fr,q[1010],u[1010],w[1010],b[1010];
vector<int> g[1010];
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%d",&n);
	for (i=1; i<=n; i++) g[i].clear();
	for (i=1; i<n; i++) {
	  scanf("%d%d",&x,&y);
	  g[x].push_back(y);
	  g[y].push_back(x);
	}
	scanf("%d",&k);
	for (i=0; i<k; i++) {
	  scanf("%d",&x);
	  w[x]=it;
	}
	scanf("%d",&k);
	for (i=0; i<k; i++) scanf("%d",&b[i]);
	printf("B %d\n",b[0]);
	fflush(stdout);
	scanf("%d",&q[0]);
	if (w[q[0]]==it) {
	  printf("C %d\n",q[0]);
	  fflush(stdout);
	  continue;
	}
	u[q[0]]=it;
	bool stop=false;
	for (ans=-1, fi=0, fr=1; fi<fr && !stop; fi++) {
	  x=q[fi];
	  for (i=0; i<g[x].size(); i++) {
	    y=g[x][i];
		if (u[y]!=it) {
		  u[y]=it;
		  q[fr++]=y;
		  if (w[y]==it) {
		    printf("A %d\n",y);
			fflush(stdout);
			scanf("%d",&z);
			for (j=0; j<k; j++) if (b[j]==z) { ans=y; break; }
		    stop=true;
		    break;
		  }
		}
	  }
	}
	printf("C %d\n",ans);
	fflush(stdout);
  }
  return 0;
}