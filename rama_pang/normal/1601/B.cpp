#include <bits/stdc++.h>
using namespace std;

void Main() {
  int N;
  cin >> N;
  vector<int> A(N + 1), B(N + 1);
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= N; i++) cin >> B[i];
  vector<int> que;
  set<int> unvis;
  vector<int> vis(2 * N + 2, -1);
  for (int i = 0; i <= N; i++) {
    unvis.emplace(i);
  }
  const auto Relax = [&](int x, int prv) {
    if (unvis.count(x)) {
      unvis.erase(x);
    }
    if (vis[x] == -1) {
      vis[x] = prv;
      que.emplace_back(x);
    }
  };
  Relax(N, -2);
  for (int q = 0; q < int(que.size()); q++) {
    int u = que[q];
    if (u == 0) break;
    if (u > N) {
      u -= N;
      while (true) {
        auto it = unvis.lower_bound(u - A[u]);
        if (it == end(unvis) || *it > u) {
          break;
        }
        Relax(*it, u + N);
      }
    } else {
      Relax(u + N + B[u], u);
    }
  }
  if (vis[0] == -1) {
    cout << -1 << '\n';
    return;
  }
  vector<int> ans;
  int x = 0;
  while (x != -2) {
    if (x < N) {
      ans.emplace_back(x);
    }
    x = vis[x];
  }
  cout << ans.size() << '\n';
  reverse(begin(ans), end(ans));
  for (auto x : ans) cout << x << ' '; cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}