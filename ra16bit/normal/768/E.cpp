#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int n,num,i,j,pos,r,cnt[62],f[62][104104],s[104104];
long long a[104104],msk;
vector<int> g[104104];
void rec(int i, int j, long long mask) {
  a[num++]=mask;
  for (j++; i+j<=60; j++) rec(i+j,j,mask|(1LL<<j));
}
int F(int i, int j) {
  if (f[i][j]>0) return f[i][j]-1;
  bool u[62];
  memset(u,0,sizeof(u));
  for (int k=0; k<g[j].size(); k++) {
    int x=g[j][k],cur=s[x]-s[j];
    if (i-cur>=0) u[F(i-cur,x)]=true;
  }
  for (f[i][j]=1; u[f[i][j]-1]; f[i][j]++);
  return f[i][j]-1;
}
int main() {
  rec(0,0,0);
  sort(a,a+num);
  for (i=0; i<num; i++) for (j=1; j<=60; j++) if (a[i]&(1LL<<j)) {
    msk=a[i]^(1LL<<j);
    pos=lower_bound(a,a+num,msk)-a;
    g[pos].push_back(i);
    s[i]+=j;
  }
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&j); cnt[j]++; }
  for (i=1; i<=60; i++) if (cnt[i]&1) r^=F(i,0);
  puts(r?"NO":"YES");
  return 0;
}