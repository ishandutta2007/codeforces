#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const int BLOCK = 400;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M, K;
  cin >> N >> M >> K;
  vector<int> A(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    A[i] ^= A[i - 1];
  }
  vector<array<int, 3>> queries;
  vector<lint> ans(M);
  lint pairs = 0;
  vector<int> cnt(3e6 + 5);
  for (int i = 0; i < M; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    // Find pairs (i, j), i < j, where A[i] ^ A[j] = K in [l, r]
    if (r - l + 1 <= BLOCK) {
      for (int j = l; j <= r; j++) {
        pairs += cnt[A[j] ^ K];
        cnt[A[j]]++;
      }
      ans[i] = pairs;
      pairs = 0;
      for (int j = l; j <= r; j++) {
        cnt[A[j]]--;
      }
    } else {
      queries.push_back({l, r, i});
    }
  }
  sort(begin(queries), end(queries), [&](array<int, 3> &a, array<int, 3> &b) {
    return make_pair(a[0] / BLOCK, a[1]) < make_pair(b[0] / BLOCK, b[1]);
  });
  int lastblock = -1;
  int ptr = 0;
  for (const auto &q : queries) {
    int block = q[0] / BLOCK;
    int upper = (block + 1) * BLOCK;
    if (lastblock != block) {
      lastblock = block;
      for (int i = 1; i <= N; i++) {
        cnt[A[i]] = 0;
      }
      pairs = 0;
      ptr = upper;
    }
    while (ptr <= q[1]) {
      pairs += cnt[A[ptr] ^ K];
      cnt[A[ptr]]++;
      ptr++;
    }
    lint save = pairs;
    for (int i = q[0]; i < upper; i++) {
      pairs += cnt[A[i] ^ K];
      cnt[A[i]]++;
    }
    ans[q[2]] = pairs;
    pairs = save;
    for (int i = q[0]; i < upper; i++) {
      cnt[A[i]]--;
    }
  }

  for (int i = 0; i < M; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}