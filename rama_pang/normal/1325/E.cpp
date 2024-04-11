#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000005;

int ans = 1e9;
vector<pair<int, int>> adj[MAX];
int vis[MAX];
int dist[MAX];
int mark = 1;

vector<pair<int, int>> edges;
vector<int> used;

void bfs(int s) {
  used.clear();
  used.assign(edges.size(), 0);

  mark++;

  queue<int> q;
  q.emplace(s);
  dist[s] = 0;
  vis[s] = mark;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &v : adj[u]) {
      if (vis[v.first] != mark) {
        vis[v.first] = mark;
        dist[v.first] = dist[u] + 1;
        q.emplace(v.first);
        used[v.second] = 1;
      }
    }
  }

  int cnt = 0;
  for (auto &i : edges) {
    if (used[cnt++]) continue;
    if (vis[i.first] == mark && vis[i.second] == mark) {
      // cout << s << " " << dist[i.first] << " " << dist[i.second] << " " << i.first << " " << i.second << "\n";
      ans = min(ans, dist[i.first] + dist[i.second] + 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);

  for (auto &i : a) {
    cin >> i;

    vector<int> prime;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        int cnt = 0;
        while (i % j == 0) {
          i /= j;
          cnt++;
        }
        if (cnt & 1) {
          prime.emplace_back(j);
        }
      }
    }
    if (i > 0) {
      prime.emplace_back(i);
    }
    while (prime.size() < 2) {
      prime.emplace_back(1);
    }
    assert(prime.size() == 2);
    edges.emplace_back(prime[0], prime[1]);
  }

  vector<bool> is_composite(MAX, false);
  for (int i = 2; i < MAX; i++) {
    if (!is_composite[i]) {
      for (int j = 2 * i; j < MAX; j += i) {
        is_composite[j] = true;
      }
    }
  }

  int cnt = 0;
  for (auto &i : edges) {
    adj[i.first].emplace_back(i.second, cnt);
    adj[i.second].emplace_back(i.first, cnt);
    cnt++;
  }

  for (int i = 1; i * i < MAX; i++) {
    if (!is_composite[i]) {
      bfs(i);
    }
  }

  if (ans == 1e9) {
    ans = -1;
  }

  cout << ans << "\n";
  return 0;
}