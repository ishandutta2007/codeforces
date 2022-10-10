#include <cstdio>
#include <vector>
using namespace std;
const int md=1000000007;
int n,m,i,x,y,z,t,cur,r,a[100100],l[100100],up[100100][18];
long long e,c[100100],d[100100],s[100100],s2[100100],o[100100],o2[100100];
vector<pair<int,int> > g[100100];
void dfs(int i, int p, int lev, long long dep) {
  c[i]=1; a[lev]=i; d[i]=dep; l[i]=lev;
  for (int j=0; j<18; j++) up[i][j]=a[max(0,lev-(1<<j))];
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j].first;
    if (k==p) continue;
    long long cur=g[i][j].second;
    dfs(k,i,lev+1,dep+cur);
    c[i]+=c[k];
    s[i]=(s[i]+s[k]+c[k]*cur)%md;
    s2[i]=(s2[i]+s2[k]+2LL*s[k]*cur+c[k]*((cur*cur)%md))%md;
  }
}
void ofs(int i, int p, long long os, long long os2) {
  o[i]=os; 
  o2[i]=os2;
  os=(os+s[i])%md;
  os2=(os2+s2[i])%md;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j].first;
    if (k==p) continue;
    long long cur=g[i][j].second;
    long long cs=(s[k]+c[k]*cur)%md,nos=(os-cs+md)%md;
    long long cs2=(s2[k]+2LL*s[k]*cur+c[k]*((cur*cur)%md))%md;
    long long cz2=(2LL*nos*cur+(n-c[k])*((cur*cur)%md))%md;
    ofs(k,i,(nos+(n-c[k])*cur)%md,((os2-cs2+md)%md+cz2)%md);
  }
}
int go(int i, int k) {
  for (int j=17; j>=0; j--) if ((k>>j)&1) i=up[i][j];
  return i;
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d%d",&x,&y,&z);
    g[x].push_back(make_pair(y,z));
    g[y].push_back(make_pair(x,z));
  }
  dfs(1,0,0,0);
  ofs(1,0,0,0);
  scanf("%d",&m);
  while (m--) {
    scanf("%d%d",&x,&y);
    r=(s2[x]+o2[x])%md;
    if (l[x]>=l[y]) {
      z=go(x,l[x]-l[y]);
      if (z==y) {
        e=(d[x]-d[y])%md;
        cur=((o2[y]+2LL*o[y]*e+(n-c[y])*((e*e)%md))*2)%md;
        printf("%d\n",(r+md-cur)%md);
        continue;
      }
      t=y;
    } else {
      z=x;
      t=go(y,l[y]-l[x]);
    }
    if (z!=t) {
      for (i=17; i>=0; i--) if (up[z][i]!=up[t][i]) {
        z=up[z][i];
        t=up[t][i];
      }
      z=up[z][0];
    }
    e=(d[x]+d[y]-2*d[z])%md;
    cur=((s2[y]+2LL*s[y]*e+c[y]*((e*e)%md))*2)%md;
    printf("%d\n",(cur+md-r)%md);
  }
  return 0;
}