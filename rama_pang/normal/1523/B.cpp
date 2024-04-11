#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  // A[i] = A[i] + A[j]
  // A[j] = A[j] - (A[i] + A[j]) = -A[i]
  // A[i] = A[i] + A[j] - A[i] = A[j]
  // x, y
  // x + y, y
  // x + y, -x
  // y, -x
  // y, -x - y
  // -x, -x - y
  // -x, -y
  vector<array<int, 3>> ans;
  for (int i = 0; i < N; i += 2) {
    for (int j = 0; j < 3; j++) {
      ans.push_back({1, i, i + 1});
      ans.push_back({2, i, i + 1});
    }
  }

  cout << ans.size() << '\n';
  for (auto [t, i, j] : ans) {
    cout << t << ' ' << i + 1 << ' ' << j + 1 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}