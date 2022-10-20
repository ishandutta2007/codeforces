#include <bits/stdc++.h>
using namespace std;
const int maxn =  1e5 + 5;
int d[maxn],dpt[maxn];
bool vis[maxn];
vector<int> e[maxn];
void dfs(int x, int src)
{
  for(auto k:e[x])
  {
    if(k == src) continue;
    dpt[k] = dpt[x]+1;
    dfs(k,x);
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 1; i < n; i++)
  {
    int u,v;
    cin >> u >> v;
    d[u]++;
    d[v]++;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for(int i = 1; i <= n; i++)
  {
    if(d[i] != 1)
    {
      dfs(i,-1);
      break;
    }
  }
  int odd = -1, check = 0;
  for(int i = 1; i <= n; i++)
  {
    if(d[i] != 1) continue;
    if(odd == -1) odd = dpt[i] & 1;
    else
    {
      if(odd != (dpt[i] & 1))
      {
        check = 1;
        break;
      }
    }
  }
  if(check) cout << 3 << " ";
  else cout << 1 << " ";
  int ans = n-1;
  for(int i = 1; i <= n; i++)
  {
    int cnt = 0;
    for(auto k:e[i])
    {
      if(d[k] == 1) cnt++;
    }
    if(cnt >= 2) ans -= cnt-1;
  }
  cout << ans << endl;
  return 0;
}