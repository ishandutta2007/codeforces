#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,q,i,x,y,z,r,a[100100],s[100100];
long long now,c[100100],d[100100],e[100100];
vector<pair<int,int> > g[100100];
bool cmp(pair<int,int> a, pair<int,int> b) {
  return d[a.second]<d[b.second];
}
void dfs(int i, int p) {
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j].second;
    if (k==p) continue;
    dfs(k,i);
    long long cur=d[k]+g[i][j].first;
    if (cur>d[i]) {
      e[i]=d[i]; d[i]=cur;
    } else if (cur>e[i]) e[i]=cur;
  }
}
void dfs2(int i, int p, long long up) {
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j].second;
    if (k==p) continue;
    long long cur=d[k]+g[i][j].first;
    dfs2(k,i,max(up,(cur==d[i]?e[i]:d[i]))+g[i][j].first);
  }
  d[i]=max(d[i],up);
}
void sfs(int i, int p) {
  s[i]=1;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j].second;
    if (k==p) continue;
    sfs(k,i);
    s[i]+=s[k];
  }
}
int rfs(int i, int p, int l, int b, int sb, long long cur) {
  a[l]=s[i]; c[l]=d[i];
  for (; c[l]-c[b]>now; b++) a[b]-=sb;
  int nb=b,nsb=s[i]-1;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j].second;
    if (k==p) continue;
    nb=rfs(k,i,l+1,nb,nsb,cur+g[i][j].first);
    nsb-=s[k];
  }
  r=max(r,a[l]);
  return b;
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d%d",&x,&y,&z);
    g[x].push_back(make_pair(z,y));
    g[y].push_back(make_pair(z,x));
  }
  dfs(1,0);
  dfs2(1,0,0);
  for (i=x=1; i<=n; i++) {
    if (d[i]<d[x]) x=i;
    sort(g[i].begin(),g[i].end(),cmp);
  }
  sfs(x,0);
  scanf("%d",&q);
  while (q--) {
    scanf("%I64d",&now);
    r=0;
    rfs(x,0,0,0,0,0);
    printf("%d\n",r);
  }
  return 0;
}