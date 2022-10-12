#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

mt19937 rng;

int _ask(int u, int v, int w) {
  int n = 7;
  int labels[n] = {3, 6, 1, 5, 0, 4, 2};
  int ilabels[n];
  for (int i = 0; i < n; ++i) ilabels[labels[i]] = i;

  u = ilabels[u], v = ilabels[v], w = ilabels[w];

  function<int(int, int)> dist = [](int u, int v) {
    int ret = 0;
    ++u, ++v;
    while (u != v) {
      if (u > v) u >>= 1;
      else v >>= 1;
      ++ret;
    }
    return ret;
  };

  function<int(int)> sum = [&](int x) {
    return dist(x, u) + dist(x, v) + dist(x, w);
  };

  int ret = 0;
  for (int i = 1; i < n; ++i) if (sum(i) < sum(ret)) ret = i;
  // cerr << labels[u] + 1 << " " << labels[v] + 1 << " " << labels[w] + 1 << " " << labels[ret] + 1 << endl;
  return labels[ret];
}

int ask(int u, int v, int w) {
  printf("? %d %d %d\n", u+1, v+1, w+1);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret - 1;
}

int main() {
  int h;
  scanf("%d", &h);

  int n = (1 << h) - 1;
  vector<pair<int, int>> cnt(n);
  for (int i = 0; i < n; ++i) cnt[i].second = i;

  for (int i = 0; i < 420; ++i) {
    int x, y, z;
    do {
      x = rng() % n, y = rng() % n, z = rng() % n;
    } while (x == y || y == z || x == z);

    ++cnt[ask(x, y, z)].first;
  }

  nth_element(cnt.begin(), cnt.begin() + 2, cnt.end(), greater<pair<int, int>>());

  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    if (i == cnt[0].second || i == cnt[1].second) continue;
    ++c[ask(i, cnt[0].second, cnt[1].second)];
  }

  for (int i = 0; i < n; ++i) {
    if (c[i] == 1) printf("! %d\n", i + 1);
  }

  return 0;
}