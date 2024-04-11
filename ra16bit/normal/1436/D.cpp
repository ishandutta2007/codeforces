#include <bits/stdc++.h>
using namespace std;
const long long inf=100000000000000000LL;
const int MX=200200;
int n,m,i,x,a[MX],k[MX];
long long c[MX],o[MX],f[MX];
vector<int> g[MX];
bool cmp(int i, int j) { return f[i]<f[j]; }
void dfs(int i) {
  for (int j: g[i]) dfs(j);
  m=0;
  for (int j: g[i]) { k[m]=j; m++; }
  if (m==0) { f[i]=a[i]; c[i]=1; return; }
  sort(k,k+m,cmp);
  for (int jj=0; jj<m; jj++) {
    int j=k[jj];
    long long cur=min(1LL*a[i],o[j]);
    a[i]-=cur;
    o[j]-=cur;
  }
  long long lst=f[k[m-1]];
  for (int jj=0; jj<m-1 && a[i]>0; jj++) {
    int j=k[jj];
    long long cnt=a[i]/c[j];
    long long cur=min(cnt,lst-f[j]);
    a[i]-=c[j]*cur;
    f[j]+=cur;
    if (a[i]>0 && f[j]<lst) {
      ++f[j];
      o[j]=c[j]-a[i];
      a[i]=0;
    }
  }
  f[i]=lst;
  for (int jj=c[i]=o[i]=0; jj<m; jj++) {
    int j=k[jj];
    c[i]+=c[j];
    o[i]=min(inf,o[i]+o[j]);
    if (f[j]<lst) o[i]=min(inf,o[i]+c[j]*(lst-f[j]));
  }
  if (a[i]>0) {
    long long cur=a[i]/c[i];
    f[i]+=cur;
    a[i]-=cur*c[i];
    if (a[i]>0) {
      ++f[i];
      o[i]=c[i]-a[i];
    }
  }
}
int main() {
  scanf("%d",&n);
  for (i=2; i<=n; i++) {
    scanf("%d",&x);
    g[x].push_back(i);
  }
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  dfs(1);
  printf("%I64d\n",f[1]);
  return 0;
}