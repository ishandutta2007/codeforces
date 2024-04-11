#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 200100;
vector<int> e[maxn], component[maxn];
bool vis[maxn];
int cnt = 0, target, place, num;
void dfs(int x)
{
  component[cnt].push_back(x);
  vis[x] = 1;
  if(x == target) place = cnt;
  for(auto k:e[x])
  {
    if(!vis[k])dfs(k);
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    for(int i = 0; i <= n; i++)
    {
      e[i].clear();
      component[i].clear();
    }
    cnt = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < m; i++)
    {
      int u,v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    vis[a] = 1;
    target = b;
    for(auto k:e[a])
    {
      if(!vis[k])dfs(k);
      cnt++;
    }
    long long ans1 = n - 1 - component[place].size();
    cnt = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 0; i <= n; i++) component[i].clear();
    swap(a,b);
    vis[a] = 1;
    target = b;
    for(auto k:e[a])
    {
      if(!vis[k])dfs(k);
      cnt++;
    }
    long long ans2 = n - 1 - component[place].size();
    cout << ans1 * ans2 << '\n';
  }
  return 0;
}