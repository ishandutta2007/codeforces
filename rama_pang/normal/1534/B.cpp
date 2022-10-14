#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int N;
  cin >> N;
  vector<lint> A(N + 2);
  lint ans = 0;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i <= N; i++) {
    ans += abs(A[i] - A[i + 1]);
  }
  for (int i = 1; i <= N; i++) {
    if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
      ans -= A[i] - max(A[i - 1], A[i + 1]);
    }
  }
  cout << ans << '\n';

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