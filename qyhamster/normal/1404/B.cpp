#ifdef LOCAL
#include <iostream>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
const int maxn= 1e5 + 5;
vector<int> e[maxn];
int dpt[maxn];
void dfs(int x,int src)
{
  for(auto k:e[x])
  {
    if(k == src) continue;
    dpt[k] = dpt[x] + 1;
    dfs(k,x);
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--)
  {
    int n,a,b,da,db;
    cin >> n >> a >> b >> da >> db;
    for(int i = 0; i <= n; i++)
    {
      e[i].clear();
      dpt[i] = 0;
    }
    for(int i = 1; i < n; i++)
    {
      int u,v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    if(db <= da*2)
    {
      cout << "Alice" << '\n';
      continue;
    }
    dfs(a,-1);
    if(dpt[b] <= da)
    {
      cout << "Alice" << '\n';
      continue;
    }
    int mx = 0, cand = 0;
    for(int i = 1; i <= n; i++)
    {
      if(dpt[i] > mx)
      {
        mx = dpt[i];
        cand = i;
      }
    }
    dpt[cand] = 0;
    mx = 0;
    dfs(cand,-1);
    for(int i = 1; i <= n; i++)
    {
      mx = max(mx,dpt[i]);
    }
    if(mx <= da*2) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
  }

  return 0;
}