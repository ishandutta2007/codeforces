#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 998244353, N = 2e7 + 2, L = 20;

vector <vector <int>> g, rev, newG;
vector <bool> used;
vector <int> ts, col;

void dfs(int v){
  used[v] = true;
  for (auto &u: g[v]) {
    if (!used[u]) dfs(u);
  }
  ts.push_back(v);
}

void dfsColor(int v, int c){
  col[v] = c;
  for (auto &u: rev[v]){
    if (!col[u]) dfsColor(u, c);
  }
}

void dfs2(int v){
  used[v] = true;
  for (auto u: newG[v])
    if (!used[u]) dfs2(u);
  ts.push_back(v);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(6);
  int n; cin >> n;
  vector <string> a(n), b(n);
  for (int i = 0; i < n; ++i){
    string s, t; cin >> s >> t;
    a[i] = s.substr(0, 3), b[i] = s.substr(0, 2) + t.substr(0, 1);
  }
  g.resize(2 * n), rev.resize(2 * n);
  used.resize(2 * n + 1);
  col.resize(2 * n);
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j) {
      if (j == i) continue;
      if (a[i] == a[j]) {
        g[i].push_back(j + n), g[i + n].push_back(j + n);
        rev[j + n].push_back(i), rev[j + n].push_back(i + n);
      }
      if (b[i] == b[j]) {
        g[i + n].push_back(j);
        rev[j].push_back(i + n);
      }
      if (a[i] == b[j]){
        g[i].push_back(j);
        rev[j].push_back(i);
      }
      if (b[i] == a[j]){
        g[i + n].push_back(j + n);
        rev[j + n].push_back(i + n);
      }
    }
  }
  for (int i = 0; i < 2 * n; ++i){
    if (!used[i]) dfs(i);
  }
  reverse(ts.begin(), ts.end());
  int curColor = 1;
  for (auto &x: ts)
    if (!col[x]) dfsColor(x, curColor++);
  for (int i = 0; i < n; ++i){
    if (col[i] == col[i + n]){
      cout << "NO\n";
      return 0;
    }
  }
  newG.resize(curColor);
  for (int i = 0; i < 2 * n; ++i){
    for (auto &x: g[i]){
      if (col[x] != col[i])
        newG[col[i]].push_back(col[x]);
    }
  }
  ts = {};
  for (int i = 0; i < 2 * n; ++i)
    used[i] = false;
  for (int i = 1; i < curColor; ++i)
    if (!used[i]) dfs2(i);
  reverse(ts.begin(), ts.end());
  vector <int> pos(curColor);
  for (int i = 0; i < ts.size(); ++i)
    pos[ts[i]] = i;
  cout << "YES\n";
  for (int i = 0; i < n; ++i){
    cout << (pos[col[i]] > pos[col[i + n]] ? a[i] : b[i]) << '\n';
  }
  return 0;
}