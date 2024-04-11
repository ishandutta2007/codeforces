#include <bits/stdc++.h>
using namespace std;

using lint = long long;

// N = 3. AAA
// N = 4. ABCD, A ^ B ^ C = D.
// N = 5. AAABC -> AADDD -> DDDDD
// N = 6. AAABBB -> AA
// N = 7. AAAAABB -> AAAAAAA

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);
  int all = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    all ^= A[i];
  }
  if (N % 2 == 0 && all != 0) {
    cout << "NO\n";
    return;
  }

  if (N % 2 == 0) {
    A.pop_back();
    N--;
  }

  vector<array<int, 3>> ans;
  const auto Solve = [&](const auto &self, int n) {
    if (n == 3) {
      ans.push_back({0, 1, 2});
      return;
    }
    ans.push_back({n - 3, n - 2, n - 1});
    self(self, n - 2);
    ans.push_back({n - 3, n - 2, n - 1});
  };

  Solve(Solve, N);

  cout << "YES\n";
  cout << ans.size() << '\n';
  for (auto [i, j, k] : ans) {
    cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}