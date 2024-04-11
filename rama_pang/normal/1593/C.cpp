#include <bits/stdc++.h>
using namespace std;

void Main() {
  int N, K;
  cin >> N >> K;
  vector<int> X(K);
  for (int i = 0; i < K; i++) {
    cin >> X[i];
    X[i] = N - X[i];
  }
  sort(begin(X), end(X));
  int ans = 0;
  int sum = 0;
  for (auto x : X) {
    if (sum + x < N) {
      sum += x;
      ans += 1;
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