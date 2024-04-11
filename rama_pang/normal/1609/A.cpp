#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long score = 0;
    int cnt = 0;
    for (int j = 0; j < n; j++) if (i != j) {
      int x = 0;
      while (a[j] % (1ll << x) == 0) {
        x += 1;
      }
      x -= 1;
      cnt += x;
      score += a[j] / (1 << x);
    }
    score += a[i] * (1ll << cnt);
    ans = max(ans, score);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) Main();  
}