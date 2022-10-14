#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    vector<lint> A, B;
    for (int i = 0; i < n; i++) {
      if (b[i] == 1) {
        A.emplace_back(a[i]);
      } else {
        B.emplace_back(a[i]);
      }
    }
    sort(begin(A), end(A));
    sort(begin(B), end(B));
    reverse(begin(B), end(B));
    reverse(begin(A), end(A));
    if (accumulate(begin(a), end(a), 0ll) < m) {
      cout << -1 << '\n';
      continue;
    }
    int ans = 1e9;
    lint sumA = 0;
    lint sumB = accumulate(begin(B), end(B), 0ll);
    for (int i = 0; i <= A.size(); i++) {
      while (!B.empty() && sumA + sumB - B.back() >= m) {
        sumB -= B.back();
        B.pop_back();
      }
      if (sumA + sumB >= m) {
        ans = min(ans, (int) i + (int) 2 * (int) B.size());
      }
      if (i < A.size()) sumA += A[i];
    }
    cout << ans << '\n';
  }
  return 0;
}