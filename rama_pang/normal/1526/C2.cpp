#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> A(N);
  multiset<int> used;
  int ans = 0;
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (sum + A[i] >= 0) {
      ans += 1;
      sum += A[i];
      used.emplace(A[i]);
    } else if (!used.empty() && *begin(used) < A[i]) {
      sum -= *begin(used);
      sum += A[i];
      used.erase(used.find(*begin(used)));
      used.emplace(A[i]);
      assert(sum >= 0);
    }
  }

  cout << ans << '\n';
  return 0;
}