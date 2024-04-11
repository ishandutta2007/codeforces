#include <bits/stdc++.h>
using namespace std;

const int BIT = 25;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  sort(begin(a), end(a));

  auto transition = [n, &a](int k) { // sorting mod 2^(k + 1) (in other words, sort based only on first k bits)
    int piv = n;
    for (int i = 0; i < n; i++) {
      if (a[i] & (1 << (k + 1))) {
        piv = i;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      a[i] &= (1 << (k + 1)) - 1;
    }
    inplace_merge(begin(a), begin(a) + piv, end(a));
  };

  auto solve = [n, &a](int k) { // k-th bit is on if sum is in interval [2^k, 2 * 2^k) or [3 * 2^k, 4 * 2^k)
    int plo = n; // start of 2^k
    int pmi = n; // satrt of 2 * 2^k
    int phi = n; // start of 3 * 2^k

    long long k_bits = 0;
    for (int i = 0; i < n; i++) {
      while (plo > 0 && a[i] + a[plo - 1] >= (1 << k)) {
        plo--;
      }
      while (pmi > 0 && a[i] + a[pmi - 1] >= 2 * (1 << k)) {
        pmi--;
      }
      while (phi > 0 && a[i] + a[phi - 1] >= 3 * (1 << k)) {
        phi--;
      }
      int first_interval = max(i + 1, pmi) - max(i + 1, plo);
      int second_interval = n - max(i + 1, phi); 
      k_bits += first_interval + second_interval;
    }

    return k_bits;
  };

  int ans = 0;

  for (int bit = BIT - 1; bit >= 0; bit--) {
    transition(bit);
    if (solve(bit) & 1) {
      ans |= (1 << bit);
    }
  }

  cout << ans << "\n";
  return 0;

}