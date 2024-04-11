#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,i,j,k,e,t,le,ri,cur,cnt,dop,a[100100],b[100100],f[200200],start[100100];
pair<int,int> all[100100];
vector<int> g[200200];
bool u[200200];
bool cmp(int i, int j) { return f[i]>f[j]; }
void dfs(int i) {
  u[i]=true;
  for (int j=0; j<g[i].size(); j++) if (!u[g[i][j]]) dfs(g[i][j]);
  f[i]=++t;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
  start[i]=cnt;
  for (j=0; j<m; j++) {
    cur=i*m+j;
    scanf("%d",&a[cur]);
	if (a[cur]>=0) all[cnt++]=make_pair(a[cur],j);
  }
  sort(all+start[i],all+cnt);
  }
  start[n]=cnt; dop=m;
  for (i=0; i<n; i++) {
    le=start[i];
	ri=start[i+1];
    for (j=le; j<ri; j=k) {
	  for (k=j; k<ri; k++) if (all[k].first!=all[j].first) break;
	  for (e=j; e<k; e++) {
	    if (j>le) g[dop-1].push_back(all[e].second);
		if (k<ri) g[all[e].second].push_back(dop);
	  }
	  if (k<ri) dop++;
	}
  }
  for (i=0; i<dop; i++) if (!u[i]) dfs(i);
  for (i=0; i<dop; i++) for (j=0; j<g[i].size(); j++) if (f[i]<f[g[i][j]]) { puts("-1"); return 0; }
  for (i=0; i<m; i++) b[i]=i;
  sort(b,b+m,cmp);
  for (j=0; j<m; j++) printf("%d%c",b[j]+1,(j+1==m)?'\n':' ');
  return 0;
}