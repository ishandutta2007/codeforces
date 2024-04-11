#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    long long sum = 0;
    vector<long long> A(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> A[i];
      sum += A[i];
    }
    if (sum % N != 0) {
      cout << -1 << '\n';
      continue;
    }
    vector<array<long long, 3>> ans;
    for (int i = 2; i <= N; i++) {
      if (A[i] % i != 0) {
        int need = i - (A[i] % i);
        assert(A[1] >= need);
        ans.push_back({1, i, need});
        A[i] += need;
        A[1] -= need;
      }
      assert(A[i] % i == 0);
      ans.push_back({i, 1, A[i] / i});
      A[1] += A[i];
      A[i] = 0;
    }
    assert(A[1] == sum);
    for (int i = 2; i <= N; i++) {
      ans.push_back({1, i, sum / N});
    }
    cout << ans.size() << '\n';
    for (auto [i, j, k] : ans) {
      cout << i << ' ' << j << ' ' << k << '\n';
    }
  }
  return 0;
}