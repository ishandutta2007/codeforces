#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  // T = 100;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    // a = 10000, b = 10000, c = 10000;

    pair<pair<int, int>, pair<int, int>> ans = {{(a + b + c - 3), 1}, {1, 1}};
    for (int A = 1; A <= 30000; A++) {
      for (int B = A; B <= 30000; B += A) {
        int C = c / B * B;
        ans = min(ans, {{abs(a - A) + abs(b - B) + abs(c - C), A}, {B, C}}); // floor
        C += B;
        ans = min(ans, {{abs(a - A) + abs(b - B) + abs(c - C), A}, {B, C}}); // ceiling
      }
    }

    cout << ans.first.first << "\n";
    cout << ans.first.second << " " << ans.second.first << " " << ans.second.second << "\n";
  }
}