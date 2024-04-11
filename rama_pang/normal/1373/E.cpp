#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint Solve(int n, int k) {
  lint ans = -1;
  auto Build = [&](int sum, bool extra) {
    if (sum == 0) return 0ll;
    vector<int> digits;
    if (extra) {
      digits.emplace_back(min(8, sum));
      sum -= digits[0];
    }
    while (sum > 0) {
      if (sum >= 9) {
        sum -= 9;
        digits.emplace_back(9);
      } else {
        digits.emplace_back(sum);
        sum = 0;
      }
    }
    reverse(begin(digits), end(digits));
    lint res = 0;
    for (auto i : digits) {
      res *= 10;
      res += i;
    }
    return res;
  };

  for (int st = 0; st < 10; st++) {
    int ones = 0;
    int extra = 0;
    for (int i = 0; i <= k; i++) {
      ones += (st + i) % 10;
      extra += (st + i) / 10;
    }
    int need = n - ones - extra;
    if (need < 0 || need % (k + 1) != 0) continue;
    lint res = Build(need / (k + 1), extra > 0);
    res *= 10;
    res += st;
    if (ans == -1) ans = res;
    ans = min(ans, res);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    cout << Solve(n, k) << "\n";
  }    
}