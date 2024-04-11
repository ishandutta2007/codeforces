#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  lint score = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2 == 0) {
      score += a[i];
    }
  }
  lint ans = score;
  int cnt = 0;
  for (int i = n - 1; i >= 0; i = (i + n - 2) % n) {
    cnt++;
    score -= a[i];
    score += a[(i + n - 1) % n];
    ans = max(ans, score);
    if (cnt == 3 * n) {
      break;
    }
  }
  cout << ans << "\n";
  return 0;
}