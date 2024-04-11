#include <bits/stdc++.h>
using namespace std;
const int MX=200100,md=998244353;
int t,n,i,j,x,y,vp,vq,r,tot,a[MX],p[MX],mx[MX];
vector<pair<int,pair<int,int>>> g[MX];
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void dfs(int i, int prv, int x, int y) {
  for (int cur=x; cur>1; cur/=a[cur]) --p[a[cur]];
  for (int cur=y; cur>1; cur/=a[cur]) {
    ++p[a[cur]];
    mx[a[cur]]=max(mx[a[cur]],p[a[cur]]);
  }
  //for (int ii=2; ii<10; ii++) if (p[ii]!=0) printf("%d^(%d) * ",ii,p[ii]);
  //printf(" <-- %d\n",i);
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j].first;
    if (k==prv) continue;
    pair<int,int> P=g[i][j].second;
    dfs(k,i,P.first,P.second);
  }
  for (int cur=x; cur>1; cur/=a[cur]) ++p[a[cur]];
  for (int cur=y; cur>1; cur/=a[cur]) --p[a[cur]];
}
void resolve(int i, int prv, int x, int y, long long cur) {
  cur=(cur*x)%md;
  cur=(cur*pw(y,md-2))%md;
  tot=(tot+cur)%md;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j].first;
    if (k==prv) continue;
    pair<int,int> P=g[i][j].second;
    resolve(k,i,P.first,P.second,cur);
  }
}
int main() {
  for (i=2; i<MX; i++) if (!a[i]) for (j=i; j<MX; j+=i) a[j]=i;
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<=n; i++) {
      p[i]=mx[i]=0;
      g[i].clear();
    }
    for (i=1; i<n; i++) {
      scanf("%d%d%d%d",&x,&y,&vp,&vq);
      g[x].emplace_back(y,make_pair(vq,vp));
      g[y].emplace_back(x,make_pair(vp,vq));
    }
    dfs(1,0,1,1);
    tot=0; r=1;
    for (i=2; i<=n; i++) if (mx[i]>0) r=(r*pw(i,mx[i]))%md;
    resolve(1,0,1,1,r);
    printf("%d\n",tot);
  }
  return 0;
}