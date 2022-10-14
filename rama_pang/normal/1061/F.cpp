#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // random u and v
  // probability root is on path from u to b is >= 1/2
  // since it's a perfect k-nary tree (worst case binary tree)

  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

  const auto Query = [&](int a, int b, int c) {
    cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
    string s;
    cin >> s;
    return s == "Yes";
  };

  int N, K;
  cin >> N >> K;

  vector<int> size_has_depth(N + 1, -1);
  for (int sz = N, d = 0; sz > 0; sz /= K) {
    assert(sz % K == 1);
    size_has_depth[sz] = d++;
  }

  while (true) { // can be repeated 15 < x < 20 times, probability of failure 2^-x
    int u = rnd() % N;
    int v = rnd() % N;
    if (u == v) {
      continue;
    }
    vector<int> onPath;
    vector<int> subtreeU;
    vector<int> subtreeV;
    for (int i = 0; i < N; i++) {
      if (Query(u, i, v)) {
        onPath.emplace_back(i);
      }
      if (Query(u, v, i)) {
        subtreeV.emplace_back(i);
      }
      if (Query(i, u, v)) {
        subtreeU.emplace_back(i);
      }
    }

    if (size_has_depth[subtreeU.size()] == -1 || size_has_depth[subtreeV.size()] == -1) { 
      // u, v are an ancestor-descendant pair
      continue;
    }

    assert(size_has_depth[subtreeU.size()] != -1);
    assert(size_has_depth[subtreeV.size()] != -1);

    if (onPath.size() == size_has_depth[subtreeU.size()] + size_has_depth[subtreeV.size()] + 1) {
      // path contains root
      // probability >= 1/2

      stable_sort(begin(onPath), end(onPath), [&](int i, int j) {
        return Query(u, i, j);
      });

      cout << "! " << onPath[size_has_depth[subtreeU.size()]] + 1 << endl;
      return 0;
    }
  }
  return 0;
}