
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int fa[maxn],a[maxn],sz[maxn],val[maxn];
vector<int> ans[maxn],e[maxn];
void dfs(int x)
{
  sz[x] = 1;
  for(auto k:e[x])
  {
    dfs(k);
    sz[x] += sz[k];
    for(int i = 0; i < sz[k]; i++)
      ans[x].push_back(ans[k][i]);
  }
  if(a[x] >= sz[x])
  {
     cout << "NO" << endl;
     exit(0);
  }
  ans[x].push_back(0);
  for(int i = sz[x]-2; i >= a[x]; i--)
  {
    ans[x][i+1] = ans[x][i];
  }
  ans[x][a[x]] = x;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, root = 1;
  cin >> n;
  for(int i = 1; i <= n; i++)
  {
    cin >> fa[i] >> a[i];
    e[fa[i]].push_back(i);
    if(fa[i] == 0) root = i;
  }
  dfs(root);
  cout << "YES" << '\n';
  for(int i = 0; i < n; i++)
  {
    val[ans[root][i]] = i+1;
  }
  for(int i = 1; i <= n; i++)
    cout << val[i] << " ";
  cout << '\n';
}