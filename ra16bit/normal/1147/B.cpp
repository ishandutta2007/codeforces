#include <bits/stdc++.h>
using namespace std;
const int MX=1500500;
int num,cnt,n,m,i,k,x,y,a[MX],p[MX];
vector<int> g[MX];
bool w[MX],z[MX];
void add(int i) {
  a[++num]=g[i].size();
  z[num]=true;
  for (int j=0; j<g[i].size(); j++) a[++num]=g[i][j];
  w[num]=true;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    if (x>y) swap(x,y);
    g[x].push_back(y-x);
    g[y].push_back(n+x-y);
  }
  for (i=1; i<=n; i++) {
    sort(g[i].begin(), g[i].end());
    add(i);
  }
  cnt=num;
  for (i=1; i<n; i++) add(i);
  for (k=0, i=2; i<=num; i++) {
    while (k>0 && (a[k+1]!=a[i] || w[k+1]!=w[i] || z[k+1]!=z[i])) k=p[k];
    if (a[k+1]==a[i] && w[k+1]==w[i] && z[k+1]==z[i]) k++;
    p[i]=k;
    if (p[i]>=cnt && w[i] && z[i-cnt+1]) { puts("Yes"); return 0; }
  }
  puts("No");
  return 0;
}