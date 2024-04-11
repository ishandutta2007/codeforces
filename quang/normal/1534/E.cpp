#include <bits/stdc++.h>

using namespace std;

const int N = 550;

int n, k;
int used[N][N];
int pre[N][N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  used[n][0] = 1;
  queue<pair<int, int>> q;
  q.push({n, 0});
  while (!q.empty()) {
    auto [u, v] = q.front();
    q.pop();
    for (int i = 0; i <= min(k, u); i++) {
      int need = k - i;
      if (need <= v) {
        int uu = u - i + need;
        int vv = v - need + i;
        if (!used[uu][vv]) {
          used[uu][vv] = 1;
          q.push({uu, vv});
          pre[uu][vv] = i;
        }
      }
    }
  }
  if (!used[0][n]) {
    cout << -1 << endl;
    return 0;
  }
  int u = 0, v = n;
  set<int> x, y;
  for (int i = 1; i <= n; i++) {
    y.insert(i);
  }
  int res = 0;
  while (u != n || v != 0) {
    int id = pre[u][v];
    int need = k - id;
    int uu = u + id - need;
    int vv = v - id + need;
    cout << "?";
    vector<int> foo, bar;
    for (int i = 0; i < id; i++) {
      foo.push_back(*y.begin());
      y.erase(y.begin());
      cout << ' ' << foo.back();
    }
    for (int i = 0; i < need; i++) {
      bar.push_back(*x.begin());
      x.erase(x.begin());
      cout << ' ' << bar.back();
    }
    cout << endl;
    int z;
    cin >> z;
    res ^= z;
    for (auto u : foo) x.insert(u);
    for (auto u : bar) y.insert(u);
      u = uu;
    v = vv;
  }
  cout << "! " << res << endl;
  return 0;
}