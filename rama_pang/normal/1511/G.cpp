#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  const int CHECK = 0;
  const int LOG = 18;

  int N, M;
  cin >> N >> M;
  vector<int> cnt(M);
  while (N--) {
    int x;
    cin >> x;
    cnt[--x]++;
  }

  vector<int> A;
  for (int i = 0; i < M; i++) {
    if (cnt[i] & 1) {
      A.emplace_back(i);
    }
  }

  // Solution:
  // check if xorsum([A[i] <= R] * (A[i] - L)) == 0
  // For value X, check if X - L has bit B on
  // Then:
  // (X - L) mod (2^{B + 1}) must be in interval [2^B, 2^{B + 1} - 1]
  // X mod (2^{B + 1}) must be in interval [2^B + L, 2^{B + 1} - 1 + L) mod 2^{B + 1}
  // For every bit B, keep prefix sum of values [L, R] in range

  int Q;
  cin >> Q;
  vector<int> Xor(Q);
  vector<int> XorKey(Q);

  vector<vector<vector<array<int, 3>>>> query(LOG, vector<vector<array<int, 3>>>(M + 1));
  const auto AddInterval = [&](int q, int B, int L, int R, int interL, int interR) {
    query[B][R + 1].push_back({q, interL, interR});
    query[B][L].push_back({q, interL, interR});
  };

  for (int q = 0; q < Q; q++) {
    int L, R;
    cin >> L >> R;
    L--, R--;

    if (CHECK) {
      for (auto a : A) if (L <= a && a <= R) {
        XorKey[q] ^= a - L;
      }
    }

    for (int B = 0; B < LOG; B++) {
      int interL = ((1 << B) + L) % (1 << (B + 1));
      int interR = ((1 << (B + 1)) + L - 1) % (1 << (B + 1));
      if (interL <= interR) {
        AddInterval(q, B, L, R, interL, interR);
      } else {
        AddInterval(q, B, L, R, interL, (1 << (B + 1)) - 1);
        AddInterval(q, B, L, R, 0, interR);
      }
    }
  }

  for (int B = 0; B < LOG; B++) {
    int sz = 1 << (B + 1);
    vector<int> tree(sz);
    const auto Update = [&](int p, int x) {
      for (int i = p; i < sz; i |= i + 1) {
        tree[i] ^= x;
      }
    };
    const auto Query = [&](int p) {
      int res = 0;
      for (int i = p; i > 0; i &= i - 1) {
        res ^= tree[i - 1];
      }
      return res;
    };
    for (int i = M; i >= 0; i--) {
      if (i < M && (cnt[i] & 1)) {
        Update(i % sz, 1);
      }
      for (auto [q, ql, qr] : query[B][i]) {
        if (Query(qr + 1) ^ Query(ql)) {
          Xor[q] ^= 1 << B;
        }
      }
    }
  }

  for (int i = 0; i < Q; i++) {
    if (CHECK) assert(Xor[i] == XorKey[i]);
    if (Xor[i]) cout << 'A';
    else cout << 'B';
  }
  cout << '\n';
  return 0;
}