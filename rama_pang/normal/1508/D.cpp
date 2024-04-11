#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int par[MAXN];
int sz[MAXN];
 
int Find(int x) {
  return par[x] == x ? x : Find(par[x]);
}
 
int Unite(int x, int y) {
  x = Find(x), y = Find(y);
  if (x == y) return 0;
  if (sz[x] > sz[y]) swap(x, y);
  par[x] = y;
  sz[y] += sz[x];
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  iota(par, par + MAXN, 0);
  fill(sz, sz + MAXN, 1);

  int N;
  cin >> N;
  vector<int> X(N), Y(N), A(N);
  vector<int> bad;
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i] >> A[i];
    A[i]--;
    if (A[i] != i) {
      Unite(i, A[i]);
      bad.emplace_back(i);
    }
  }

  vector<pair<int, int>> ans;
  const auto Swap = [&](int x, int y) {
    swap(A[x], A[y]);
    ans.emplace_back(x, y);
  };

  if (!bad.empty()) {
    sort(begin(bad), end(bad), [&](int i, int j) { // get leftmost bottommost
      return pair(X[i], Y[i]) < pair(X[j], Y[j]);
    });
    sort(begin(bad) + 1, end(bad), [&](int i, int j) { // sort by angle
      long long xi = X[i] - X[bad[0]];
      long long yi = Y[i] - Y[bad[0]];
      long long xj = X[j] - X[bad[0]];
      long long yj = Y[j] - Y[bad[0]];
      return xi * yj - yi * xj > 0;
    });
    for (int i = 1; i + 1 < int(bad.size()); i++) { // will not intersect, since sorted by angle
      if (Unite(bad[i], bad[i + 1])) {
        Swap(bad[i], bad[i + 1]);
      }
    }
    for (int i = 1; i < int(bad.size()); i++) { // star-like graph of swaps
      Swap(bad[0], A[bad[0]]);
    }
  }

  for (int i = 0; i < N; i++) {
    assert(A[i] == i);
  }

  cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }
  return 0;
}