#include <bits/stdc++.h>
#define int long long
using namespace std;

struct UnionFind {
  vector<int> id;

  UnionFind() {}
  UnionFind(int N) { id.assign(N, -1); }

  int find(int u) {
    if (id[u] < 0)
      return u;
    return id[u] = find(id[u]);
  }

  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return false;
    if (id[u] > id[v])
      swap(u, v);
    id[u] += id[v];
    id[v] = u;
    return true;
  }
};

int f(int x) { return x % 3; }

int g(int x, int y) {
  return ((f(x) + f(y)) * (f(x) + f(y)) + f(x) * f(y)) % 3;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    arr[i] %= 3;
  }

  array<int, 3> cnt;
  cnt[0] = cnt[1] = cnt[2] = 0;
  for (int x : arr)
    cnt[x]++;

  // Test Z = 0 ?
  if (cnt[0] <= N / 2) {
    int nec = N / 2 - cnt[0];
    cout << 0 << endl;
    for (int i = 0; i < N; ++i) {
      if (!arr[i])
        cout << 1;
      else if (nec > 0) {
        cout << 1;
        --nec;
      } else
        cout << 0;
    }
    cout << endl;
    return 0;
  }

  // Test Z = 1
  if (!cnt[0] or cnt[0] == N) {
    cout << 1 << endl;
    cout << string(N / 2, '0') + string(N / 2, '1') << endl;
    return 0;
  }

  // Test Z = 2
  if (cnt[1] + cnt[2] <= N / 2) {
    int nec0 = N / 2 - cnt[1] - cnt[2];
    cout << 2 << endl;
    for (int i = 0; i < N; ++i) {
      if (arr[i])
        cout << 1;
      else if (nec0 > 0) {
        cout << 1;
        --nec0;
      } else
        cout << 0;
    }
    cout << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;

  for (int Z = 0; Z < 3; ++Z) {
    cout << "INTERDIT POUR Z = " << Z << endl;
    for (int x = 0; x < 3; ++x)
      for (int y = x; y < 3; ++y)
        if (g(x, y) == Z)
          cout << x << ' ' << y << endl;
  }
}