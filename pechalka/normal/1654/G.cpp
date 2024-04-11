#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <string>
#include <vector>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int MAXN = 200'200;
vector<int> G[MAXN];
int h[MAXN];

vector<pair<int, int>> dp[MAXN];
vector<int> comp;
vector<int> cur_G[MAXN];

void dfs(int v, int p) {
  comp.emplace_back(v);
  for (int u : G[v]) {
    if (u == p)
      continue;
    if (h[u] == h[v]) {
      cur_G[v].emplace_back(u);
      cur_G[u].emplace_back(v);
      dfs(u, v);
    }
  }
}

int dist[MAXN];
int chng[MAXN];
int ttimer = 0;

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;
  fill(h, h + n, n);
  deque<int> Q;
  vector<int> l(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i];
    if (l[i]) {
      h[i] = 0;
      Q.emplace_back(i);
    }
  }
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    G[a - 1].emplace_back(b - 1);
    G[b - 1].emplace_back(a - 1);
  }
  while (!Q.empty()) {
    int v = Q.front();
    Q.pop_front();
    for (int u : G[v]) {
      if (h[u] == n) {
        h[u] = h[v] + 1;
        Q.emplace_back(u);
      }
    }
  }
  vector<int> order(n);
  for (int i = 0; i < n; ++i)
    order[i] = i;
  sort(order.begin(), order.end(), [](int a, int b) {
    return h[a] < h[b];
  });
  vector<bool> used(n, false);
  for (int v : order) {
    if (used[v])
      continue;
    dfs(v, -1);
    vector<pair<int, pair<int, int>>> interesting;
    for (int u : comp) {
      used[u] = true;
      for (int w : G[u]) {
        if (h[w] == h[u] - 1) {
          for (auto t : dp[w])
            interesting.emplace_back(t.second, make_pair(u, t.first));
        }
      }
    }
    sort(interesting.rbegin(), interesting.rend());
    int pr = -1;
    for (int i = 0; i < interesting.size(); ++i) {
      if (i + 1 < interesting.size() && interesting[i + 1].first == interesting[i].first)
        continue;
      ++ttimer;
      set<pair<int, int>> Q;
      for (int j = pr + 1; j <= i; ++j) {
        if (chng[interesting[j].second.first] == ttimer) {
          if (dist[interesting[j].second.first] > interesting[j].second.second - 1) {
            Q.erase(make_pair(dist[interesting[j].second.first], interesting[j].second.first));
            dist[interesting[j].second.first] = max(interesting[j].second.second - 1, 0);
            Q.emplace(dist[interesting[j].second.first], interesting[j].second.first);
          }
        } else {
          chng[interesting[j].second.first] = ttimer;
          dist[interesting[j].second.first] = max(interesting[j].second.second - 1, 0);
          Q.emplace(dist[interesting[j].second.first], interesting[j].second.first);
        }
      }
      pr = i;
      while (!Q.empty()) {
        int u = Q.begin()->second;
        Q.erase(Q.begin());
        for (int w : cur_G[u]) {
          if (chng[w] != ttimer || dist[w] > dist[u] + 1) {
            Q.erase(make_pair(dist[w], w));
            dist[w] = dist[u] + 1;
            chng[w] = ttimer;
            Q.emplace(dist[w], w);
          }
        }
      }
      int k = interesting[i].first;
      for (int u : comp) {
        if (dp[u].empty() || dp[u].back().first > dist[u])
          dp[u].emplace_back(dist[u], k + 2);
      }
    }
    for (int u : comp)
      cur_G[u].clear();
    if (comp.size() > 1) {
      for (int u : comp) {
        if (dp[u].empty() || dp[u].back().first > 0)
          dp[u].emplace_back(0, h[u]);
      }
    }
    comp.clear();
  }
  for (int i = 0; i < n; ++i)
    cout << (dp[i].empty() ? h[i] : dp[i].back().second) << ' ';
  cout << '\n';
  return 0;
}