#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> e[maxn];
int dpt[maxn],sz[maxn];
void dfs(int x,int src)
{
  sz[x] = 1;
  for(auto k:e[x])
  {
    if(k == src) continue;
    dpt[k] = dpt[x] + 1;
    dfs(k,x);
    sz[x] += sz[k];
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  for(int i = 1; i < n; i++)
  {
    int u,v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1,-1);
  priority_queue<int> pq;
  for(int i = 1; i <= n; i++)
  {
    pq.push(sz[i] - dpt[i] - 1);
  }
  long long ans = 0;
  for(int i = 0; i < n-k; i++)
  {
    ans += pq.top();
    pq.pop();
  }
  cout << ans << endl;
  return 0;
}