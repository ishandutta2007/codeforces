#include <bits/stdc++.h>
using namespace std;

namespace std {

template<typename ...Args>
void read(Args &...args) {
  ((cin >> args), ...);
}

template<typename ...Args>
void write(Args &&...args) {
  ((cout << args), ...);
}

template<typename ...Args>
void debug(Args &&...args) {
  return;
  ((cerr << args), ...);
}

template<typename Fun>
class y_combinator_result {
 private:
  Fun fun_;

 public:
  template<typename T>
  explicit y_combinator_result(T &&fun) : fun_(fun) {}

  template<typename ...Args>
  decltype (auto) operator()(Args &&...args) {
    return fun_(ref(*this), forward<Args>(args)...);
  }
};

template<typename Fun>
decltype (auto) y_combinator(Fun &&fun) {
  return y_combinator_result<decay_t<Fun>>(forward<Fun>(fun));
}

} // namespace std

using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // We have array weight[mask] = min(popcount(mask), N - popcouont(mask))
  // Let cnt[mask] = number of columns with "mask" config
  // Choose X s.t. sum_mask cnt[mask] * weight[X ^ mask] is minimized
  // Looks like xor-convolution
  // cnt[m1] * weight[m2] = res[m1 ^ m2]
  // If we can get res[], we can solve just choose the minimum among res[]

  int N, M;
  read(N, M);

  vector<lint> A(1 << N); // weight
  vector<lint> B(1 << N); // cnt column

  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    read(S[i]);
  }

  for (int i = 0; i < (1 << N); i++) {
    int popcnt = __builtin_popcount(i);
    A[i] = min(popcnt, N - popcnt);
  }

  for (int j = 0; j < M; j++) {
    int mask = 0;
    for (int i = 0; i < N; i++) {
      if (S[i][j] == '1') {
        mask |= 1 << i;
      }
    }
    B[mask]++;
  }

  // Xor-Covoltion on A[] and B[]. I think it's name is FWHT?
  // I think it's k-D FFT on 2 * 2 * 2 * ...
  // We evaluate at +1 and -1 to simulate xor (+ when bit 0, - when bit 1)
  //
  // For 1 bits: if we have (a + bx) -> (a + b, a - b)
  // For inverting:
  // a = u + v, b = u - v -> u = (a + b) / 2, v = (a - b) / 2
  // So we divide by N

  auto FWHT = [&](vector<lint> A, bool inv) {
    for (int len = 0; len < N; len++) {
      for (int mask = 0; mask < (1 << N); mask++) {
        if (!((mask >> len) & 1)) {
          lint u = A[mask];
          lint v = A[mask ^ (1 << len)];
          // u has bit 0
          // v has bit 1
          A[mask] = u + v;
          A[mask ^ (1 << len)] = u - v;
        }
      }
    }
    if (inv) {
      for (int mask = 0; mask < (1 << N); mask++) {
        assert(A[mask] % (1 << N) == 0);
        A[mask] /= (1 << N);
      }
    }
    return A;
  };

  A = FWHT(A, 0);
  B = FWHT(B, 0);

  vector<lint> C(1 << N);
  for (int i = 0; i < (1 << N); i++) {
    C[i] = 1ll * A[i] * B[i];
  }

  C = FWHT(C, 1);
  write(*min_element(begin(C), end(C)), '\n');
  return 0;
}