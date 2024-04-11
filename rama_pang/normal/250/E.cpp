#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e14;

struct DSU {
  vector<int> p;
  DSU(int n) {
    p.resize(n);
    iota(begin(p), end(p), 0);
  }
  int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
  }
};

int N, M;
string G[105];

pair<pair<int, int>, lint> solve(int pos, int dir, int row) {
  DSU left(M), right(M);
  string A = G[row];
  auto wall = [&](int x) {
    if (x < 0 || x >= M) return true;
    return A[x] == '#';
  };

  lint res = 0;
  int it = 0;

  while (true) {
    if (dir == 1) {
      res += abs(right.Find(pos) - pos);
      pos = right.Find(pos);
    } else {
      res += abs(left.Find(pos) - pos);
      pos = left.Find(pos);
    }

    it++;
    if (it > 200 * M) return {{0, 0}, INF};

    res++;
    if (G[row + 1][pos] == '.') {
      return {{pos, dir}, res};
    }
    if (wall(pos + dir)) {
      dir *= -1;
    } else {
      if (dir == 1) {
        right.p[pos] = pos + dir;
        left.p[pos + dir] = pos;
      } else {
        right.p[pos + dir] = pos;
        left.p[pos] = pos + dir;
      }
      pos += dir;
      if (A[pos] == '+') {
        pos -= dir;
        dir *= -1;
      }
    }
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> G[i];
  }

  int cur = 0;
  int dir = 1;
  lint ans = 0;
  for (int i = 0; i < N - 1; i++) {
    pair<pair<int, int>, lint> floor = solve(cur, dir, i);
    cur = floor.first.first;
    dir = floor.first.second;
    ans += floor.second;
    if (ans >= INF) break;
  }

  if (ans >= INF) {
    cout << "Never\n";
    return 0;
  }

  cout << ans << "\n";
  return 0;
}