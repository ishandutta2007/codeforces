#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 1e18;
  for (int z = 0; z < n; z++) {
    long long score = 0;
    long long last = 0;
    for (int i = z - 1; i >= 0; i--) {
      score += last / a[i] + 1;
      last = (last / a[i] + 1) * a[i];
    }
    last = 0;
    for (int i = z + 1; i < n; i++) {
      score += last / a[i] + 1;
      last = (last / a[i] + 1) * a[i];
    }
    ans = min(ans, score);
  }
  cout << ans << '\n';
  return 0;
}