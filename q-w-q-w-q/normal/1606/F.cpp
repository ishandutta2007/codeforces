#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 200005;
int n, q, fa[N], l[N], r[N], cnt;
int up[N], ans[N], s0[N], s1[N];
vector<int> to[N], add[N];
vector<pair<int, int>> qy[N];

namespace bits {
int s[N][2];

void add(int x, int v0, int v1) {
  while (x <= n)
    s[x][0] += v0, s[x][1] += v1, x += x & (-x);
}

pair<int, int> query(int x) {
  int s0 = 0, s1 = 0;

  for (int i = r[x]; i; i &= i - 1)
    s0 += s[i][0], s1 += s[i][1];

  for (int i = l[x]; i; i &= i - 1)
    s0 -= s[i][0], s1 -= s[i][1];

  return make_pair(s0, s1);
}
}

void dfs(int i) {
  l[i] = ++cnt, up[i] = i;
  for (int j : to[i]) {
    to[j].erase(find(to[j].begin(), to[j].end(), i));
    fa[j] = i, dfs(j);
  }
  r[i] = cnt;

  if (i != 1 && to[i].size() > 1)
    add[to[i].size() - 2].push_back(i);
}

int find(int x) {
  while (x != up[x])
    x = up[x] = up[up[x]];
  return x;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    to[x].push_back(y), to[y].push_back(x);
  }

  cin >> q;
  for (int i = 1; i <= q; i++) {
    int x, k;
    cin >> x >> k;
    qy[min(n - 1, k)].push_back(make_pair(x, i));
  }

  dfs(1);

  for (int i = n - 1; ~i; i--) {
    while (!add[i].empty()) {
      int x = add[i].back();
      add[i].pop_back();
      if (find(x) != x)
        continue;

      int t0 = s0[x], t1 = s1[x];
      int y = find(fa[x]);
      up[x] = y;
      s0[y] += s0[x] + 1, s1[y] += t1 + to[x].size();
      bits::add(l[x], t0 + 1, t1 + to[x].size());
      bits::add(l[y], -t0 - 1, -t1 - to[x].size());

      if (y != 1) {
        int tp = to[y].size() + s1[y];
        tp = (tp - 1) / (s0[y] + 1) - 1;
        if (tp >= 0)
          add[min(tp, i)].push_back(y);
      }
    }

    for (auto tp : qy[i]) {
      int x = tp.first;
      auto [t0, t1] = bits::query(x);
      ans[tp.second] = to[x].size() + t1 - t0 * (i + 1);
    }
  }

  for (int i = 1; i <= q; i++)
    cout << ans[i] << '\n';
}