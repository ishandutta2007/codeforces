#include <bits/stdc++.h>
using namespace std;
const int md=1000000007;
int n,i,x,y,r;
long long a[100100];
vector<int> g[100100];
long long gcd(long long a, long long b) {
  return b?gcd(b,a%b):a;
}
void dfs(int i, int p, const map<long long,int>& pd) {
  map<long long,int> d;
  d[a[i]]++;
  r=(r+a[i])%md;
  for (const auto& it : pd) {
    long long cur=gcd(it.first,a[i]);
    d[cur]+=it.second;
    r=(r+cur*(it.second))%md;
  }
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    dfs(k,i,d);
  }
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%I64d",&a[i]);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  map<long long,int> empt;
  dfs(1,0,empt);
  printf("%d\n",r);
  return 0;
}