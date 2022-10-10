#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> piii;
const int MX=77,inf=2100100100;
int n,m,num,i,j,x,y,z,fi,fr,a,b,msk,cur,cc,c[MX],q[MX],w[MX],dst[MX][(1<<17)+5];
priority_queue<piii, vector<piii>, greater<piii>> d;
vector<int> g[MX],e[MX],v[MX];
int main() {
  scanf("%d%d%d%d",&n,&m,&a,&b);
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x,&y,&z);
	g[x].push_back(y); e[x].push_back(z);
	g[y].push_back(x); e[y].push_back(z);
  }
  for (i=1; i<=n; i++) {
	if (c[i]==0) {
	  c[i]=++cc;
	  v[cc].push_back(i);
	} else continue;
	q[0]=i;
    for (fi=0, fr=1; fi<fr; fi++) {
	  x=q[fi];
	  for (j=0; j<g[x].size(); j++) {
	    y=g[x][j];
		if (c[y]==0 && e[x][j]==a) {
		  v[c[i]].push_back(y);
		  c[y]=c[i];
		  q[fr++]=y;
		}
	  }
	}
  }
  for (i=1; i<=cc; i++) if (v[i].size()>3) w[i]=++num;
  for (i=1; i<=n; i++) for (j=0; j<(1<<num); j++) dst[i][j]=inf;
  if (w[c[1]]>0) msk|=(1<<(w[c[1]]-1));
  d.push({0,{1,msk}});
  dst[1][msk]=0;
  while (!d.empty()) {
    x=d.top().second.first;
	y=d.top().second.second;
	z=d.top().first;
	d.pop();
	if (z!=dst[x][y]) continue;
	for (j=0; j<g[x].size(); j++) {
	  i=g[x][j];
	  msk=y;
	  if (w[c[i]]>0) {
	    if (e[x][j]==b && (msk&(1<<(w[c[i]]-1)))) continue;
		msk|=(1<<(w[c[i]]-1));
	  } else if (e[x][j]==b && c[i]==c[x]) continue;
	  cur=z+e[x][j];
	  if (cur<dst[i][msk]) {
	    dst[i][msk]=cur;
		d.push({cur,{i,msk}});
	  }
	}
  }
  for (i=1; i<=n; i++) {
    for (j=1; j<(1<<num); j++) dst[i][0]=min(dst[i][0],dst[i][j]);
    printf("%d ",dst[i][0]);
  }
  return 0;
}