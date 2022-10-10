#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,num,mx,M,i,j,x,y,t,a[100100],c[100100],e[5005],s[5005];
double z,r,p[5005],f[5005][10010];
vector<pair<int,double> > b[100100];
vector<int> g[5005];
void dfs(int i) {
  for (int j=e[i]; j<=M; j++) f[i][j]=1.0;
  for (int k=0; k<g[i].size(); k++) {
    int x=g[i][k];
    dfs(x);
    for (int j=e[i]; j<=M; j++) f[i][j]*=f[x][j];
  }
  for (int j=M; j>=e[i]; j--) {
    f[i][j]*=(1.0-p[i]);
    if (j>0) f[i][j]+=p[i]*f[i][j-1];
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    mx=max(mx,a[i]);
  }
  M=2*m;
  if (mx>m) for (i=1; i<=n; i++) a[i]=max(0,a[i]-mx+m);
  for (i=0; i<m; i++) {
    scanf("%d%d%lf",&x,&y,&z);
    b[x].push_back(make_pair(y,z));
  }
  for (i=1; i<=n; i++) {
    sort(b[i].rbegin(),b[i].rend());
    for (j=0; j<b[i].size(); j++) {
      s[++t]=++num;
      g[s[t-1]].push_back(s[t]);
      p[num]=b[i][j].second;
      c[b[i][j].first]++;
    }
    e[s[t]]=max(e[s[t]],a[i]);
    t-=c[i];
  }
  dfs(0);
  for (j=M; j>0; j--) r+=(f[0][j]-f[0][j-1])*j;
  if (mx>m) r+=mx-m;
  printf("%.9lf\n",r);
  return 0;
}