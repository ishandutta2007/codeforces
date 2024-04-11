#include <bits/stdc++.h>
using namespace std;
const int MX=100100,inf=1000000100;
int n,num,q,x,rt,i,le,ri,mid,p[MX],a[MX],lft[MX],rgh[MX],pos[MX],mn[MX],mx[MX];
double ans[MX];
vector<int> g[MX];
void dfs(int i, int le, int ri) {
  if (g[i].empty()) {
    mn[i]=mx[i]=a[i];
    lft[num]=le;
    rgh[num]=ri;
    pos[num++]=i;
    return;
  }
  if (a[g[i][0]]>a[g[i][1]]) swap(g[i][0],g[i][1]);
  dfs(g[i][0],le,a[i]); mn[i]=mn[g[i][0]];
  dfs(g[i][1],a[i],ri); mx[i]=mx[g[i][1]];
}
void solve(int i, int cnt, long long sum) {
  if (g[i].empty()) {
    ans[i]=double(sum)/cnt;
    return;
  }
  solve(g[i][0],cnt+1,sum+mn[g[i][1]]);
  solve(g[i][1],cnt+1,sum+mx[g[i][0]]);
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d%d",&p[i],&a[i]);
    if (p[i]==-1) rt=i; else g[p[i]].push_back(i);
  }
  dfs(rt,0,inf);
  solve(rt,0,0);
  scanf("%d",&q);
  while (q--) {
    scanf("%d",&x);
    le=0; ri=num-1;
    while (le<ri) {
      mid=(le+ri)/2;
      if (rgh[mid]<x) le=mid+1; else ri=mid;
    }
    printf("%.11lf\n",ans[pos[ri]]);
  }
  return 0;
}