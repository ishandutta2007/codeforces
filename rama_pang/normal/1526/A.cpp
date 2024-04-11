#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> A(2 * N);
    for (int i = 0; i < 2 * N; i++) {
      cin >> A[i];
    }
    sort(begin(A), end(A));
    vector<int> ans(2 * N);
    for (int i = 0; i < N; i++) {
      ans[i * 2 + 0] = A[i];
      ans[i * 2 + 1] = A[i + N];
    }
    for (int i = 0; i < 2 * N; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}