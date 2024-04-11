#include <bits/stdc++.h>
using namespace std;

using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  lint N, K, X;
  cin >> N >> K >> X;
  vector<lint> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(begin(A), end(A));
  vector<lint> need;
  for (int i = 0; i + 1 < N; i++) {
    lint gap = A[i + 1] - A[i];
    need.emplace_back(max(0ll, gap - 1) / X);
  }
  sort(begin(need), end(need));
  int ans = N;
  for (auto i : need) {
    if (K >= i) {
      K -= i;
      ans -= 1;
    }
  }
  cout << ans << '\n';
  return 0;
}