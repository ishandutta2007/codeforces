#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, Q;
  cin >> N >> Q;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
  }

  vector<int> ans(Q, -1);
  vector<array<int, 3>> query;
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    query.push_back({l, r, i});
  }

  const int BLOCK = 555;

  sort(begin(query), end(query), [&](array<int, 3> a, array<int, 3> b) {
    if (a[0] / BLOCK == b[0] / BLOCK) return a[1] < b[1];
    return a[0] < b[0];
  });

  vector<int> freq(N);
  vector<int> cnt_freq(N + 5);
  int max_freq = 0;
  cnt_freq[0] = N;

  const auto Modify = [&](int v, int sgn) {
    v = A[v];
    cnt_freq[freq[v]]--;
    freq[v] += sgn;
    cnt_freq[freq[v]]++;
    if (sgn == 1) {
      while (cnt_freq[max_freq + 1] != 0) {
        max_freq += 1;
      }
    } else {
      while (cnt_freq[max_freq] == 0) {
        max_freq -= 1;
      }
    }
  };

  int L = 0, R = -1;
  for (auto q : query) {
    while (R < q[1]) Modify(++R, +1);
    while (L > q[0]) Modify(--L, +1);
    while (R > q[1]) Modify(R--, -1);
    while (L < q[0]) Modify(L++, -1);
    int len = q[1] - q[0] + 1;
    if (max_freq <= (len + 1) / 2) {
      ans[q[2]] = 1;
    } else {
      // f bad elements
      // len - f good elements
      int bad = max_freq;
      int good = len - bad;
      assert(bad > good);
      ans[q[2]] = (bad - good - 1) + 1;
    }
  }

  for (int i = 0; i < Q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}