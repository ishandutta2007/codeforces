#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 10;
int g[N][N], used[N], vis[N];
int n;
vector<int> ord, li;

void dfs(int v) {
  used[v] = 1;
  rep(i, n)
    if (g[v][i] && !used[i])
      dfs(i);
  ord.push_back(v);
}

void dfs2(int v) {
  vis[v] = 1;
  rep(i, n)
    if (g[v][i] && g[i][v] && !vis[i])
      dfs2(i);
  li.push_back(v);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  rep(i, n)
    rep(j, n)
      cin >> g[i][j];
  rep(i, n)
    rep(j, n)
      rep(k, n)
        if (g[j][i] && g[i][k])
          g[j][k] = 1;
  rep(i, n)
    if (!used[i])
      dfs(i);
  vector<vector<string>> ans(n * 2, vector<string>(n * 2 - 1, string(n + 2, '#')));
  for (auto &pp : ans)
    rep(i, n)
      pp[i * 2][2] = '.';
  int layer = 2 * n - 2;
  for (int i : ord) {
    if (vis[i])
      continue;
    li.clear();
    dfs2(i);
    for (int j : li) {
      ans[layer][j * 2][1] = '.';
      ans[layer][j * 2][2] = '1' + j;
      ans[layer + 1][j * 2][2] = '#';
    }
    for (auto &s : ans[layer])
      s[0] = '.';
    rep(j, n)
      if (g[i][j])
        ans[layer][j * 2][1] = '.';
    layer -= 2;
  }
  cout << ans[0][0].size() << ' ' << ans[0].size() << ' ' << ans.size() << '\n';
  for (auto &pp : ans) {
    for (auto &s : pp)
      cout << s << '\n';
    cout << '\n';
  }

}