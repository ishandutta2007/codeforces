#include <cstdio>
#include <vector>
using namespace std;
int i,n,m,x,y,z,d[1222222],w[1222222],u[222222];
long long r1[222222],r2[222222],e[222222],s[1222222],LR,l,r;
vector <int> g[222222],f[222222];
bool c[222222],q;
void cycles(int i, int l, int p) {
  int j,k;
  if (u[i]==z) {
    for (j=l-1; d[j]!=i; j--) c[d[j]]=true;
    for (k=j; k<l; k++) d[k-j]=d[k];
    m=l-j; c[i]=q=true;
    return;
  }
  u[i]=z; d[l]=i;
  for (j=0; j<g[i].size(); j++) {
    k=g[i][j];
    if (k!=p) cycles(k,l+1,i);
    if (q) break;
  }
}
void dfs(int i, int p) {
  int j,k;
  r1[i]=0; e[i]=1;
  for (j=0; j<g[i].size(); j++) {
    k=g[i][j];
    if (k!=p && !c[k]) {
      dfs(k,i);
      e[i]+=e[k];
      r1[i]+=r1[k]+e[k]*f[i][j];
    }
  }
}
void count(int i, int p, long long s, long long t) {
  int j,k;
  r2[i]=s;
  for (j=0; j<g[i].size(); j++) {
    k=g[i][j];
    if (k!=p && !c[k]) count(k,i,s+r1[i]-r1[k]+(t+e[i]-2*e[k])*f[i][j],t+e[i]-e[k]);
  }
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%d",&x,&y,&z);
    g[x].push_back(y); f[x].push_back(z);
    g[y].push_back(x); f[y].push_back(z);
  }
  z=1; cycles(1,0,0);
  for (i=0; i<m; i++) {
    dfs(d[i],0);
    d[m+i]=d[i];
    d[m+m+i]=d[i];
    for (x=0; x<g[d[i]].size(); x++) if (g[d[i]][x]==d[i+1]) {
      w[i]=f[d[i]][x];
      w[m+i]=w[i];
      w[m+m+i]=w[i];
      break;
    }
    s[i+1]=s[i]+w[i];
  }
  for (i=m; i<3*m; i++) s[i+1]=s[i]+w[i];
  x=1; y=m; LR=l=r=0;
  for (i=1; i<m; i++) {
    LR+=(s[m]-s[i])*e[d[i]]+r1[d[i]];
    l+=e[d[i]];
  }
  for (i=m; i<m+m; i++) {
    while (x<i && (s[i]-s[x]>s[y+1]-s[i] || y<i)) {
      LR+=(s[y+1]-s[i]-s[i]+s[x])*e[d[x]];
      l-=e[d[x]]; r+=e[d[y+1]];
      x++; y++;
    }
    count(d[i],0,LR,l+r);
    l+=e[d[i]]; LR+=w[i]*(l-r)+r1[d[i]]-r1[d[i+1]]; r-=e[d[i+1]];
  }
  for (i=1; i<=n; i++) {
    printf("%I64d",r1[i]+r2[i]);
    putchar((i==n)?'\n':' ');
  }
  return 0;
}