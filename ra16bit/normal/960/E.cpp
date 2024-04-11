#include <bits/stdc++.h>
using namespace std;
const int MX=200200,md=1000000007;
int n,i,x,y,res,a[MX],c[2][MX];
vector<int> g[MX];
void dfs(int i, int p) {
  c[0][i]=1;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    dfs(k,i);
    c[0][i]+=c[1][k];
    c[1][i]+=c[0][k];
  }
}
void solve(int i, int p, long long up0, long long up1) {
  long long cur=((up0+1LL)*(c[0][i]+c[1][i]))%md;
  res=((res+cur*a[i])%md+md)%md;
  cur=(up1*(c[0][i]+c[1][i]))%md;
  res=((res-cur*a[i])%md+md)%md;
  cur=(c[0][i]*(up0+up1))%md;
  res=((res+cur*a[i])%md+md)%md;
  cur=(c[1][i]*(up0+up1))%md;
  res=((res-cur*a[i])%md+md)%md;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    long long oth=c[0][i]+c[1][i]-c[0][k]-c[1][k];
    cur=(oth*c[1][k])%md;
    res=((res+cur*a[i])%md+md)%md;
    cur=(oth*c[0][k])%md;
    res=((res-cur*a[i])%md+md)%md;
    solve(k,i,up1+c[1][i]-c[0][k],up0+c[0][i]-c[1][k]);
  }
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1,0);
  solve(1,0,0,0);
  printf("%d\n",res);
  return 0;
}