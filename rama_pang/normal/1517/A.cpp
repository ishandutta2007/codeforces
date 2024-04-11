#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  lint N;
  cin >> N;
  // vector<lint> A(N);
  // for (int i = 0; i < N; i++) {
  //   cin >> A[i];
  // }

  if (N % 2050 != 0) {
    cout << -1 << '\n';
    return;
  }

  lint x = N / 2050;
  string s = to_string(x);
  int ans = 0;
  for (auto i : s) ans += i - '0';
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