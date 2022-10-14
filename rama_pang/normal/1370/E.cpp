#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  string A, B;
  cin >> A >> B;
  {
    string a = A, b = B;
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    if (a != b) {
      cout << -1 << "\n";
      return 0;
    }
  }

  vector<int> P(N);
  for (int i = 0; i < N; i++) {
    if (A[i] == '0' && B[i] == '1') {
      P[i] = -1;
    } else if (A[i] == '1' && B[i] == '0') {
      P[i] = +1;
    }
  }

  int ans = 0;
  for (int r = 0; r < 2; r++) {
    for (int i = 0, j = 0, mn = 0; i < N; i++) {
      j += P[i];
      mn = min(mn, j);
      ans = max(ans, j - mn);
    }
    for (int i = 0; i < N; i++) {
      P[i] *= -1;
    }
  }

  cout << ans << "\n";
  return 0;
}