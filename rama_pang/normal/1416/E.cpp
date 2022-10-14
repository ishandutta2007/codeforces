#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    lint zero = 0;
    lint two = -1;
    set<pair<lint, lint>> one;

    lint offset = 0;
    lint sign = 1;

    vector<lint> A(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
      lint a = A[i];
      if (two != -1) {
        zero += 2;
        offset = 0;
        sign = 1;
        one.clear();
        if (two < a) {
          one.emplace(a - two, a - two);
        }
      } else if (!one.empty()) {
        zero += 1;
        while (!one.empty() && offset + sign * rbegin(one)->second >= a) {
          auto p = *rbegin(one);
          one.erase(p);
          if (offset + sign * p.first < a) {
            one.emplace(p.first, (a - 1 - offset) / sign);
          }
        }
        while (!one.empty() && offset + sign * begin(one)->first >= a) {
          auto p = *begin(one);
          one.erase(p);
          if (offset + sign * p.second < a) {
            one.emplace((a - 1 - offset) / sign, p.second);
          }
        }
        offset = a - offset;
        sign *= -1;
      } else {
        lint lim = min(A[i - 1], a) - 1;
        // reverse on [1, lim]
        if (1 <= lim) {
          sign = -1;
          offset = a;
          one.clear();
          one.emplace(1, lim);
        } else {
          sign = 1;
          offset = 0;
          one.clear();
        }
      }
      two = -1;
      if (a % 2 == 0) {
        auto it = one.lower_bound({(a / 2 - offset) / sign + 1, -1e18});
        if (it != begin(one) && prev(it)->first <= (a / 2 - offset) / sign && (a / 2 - offset) / sign <= prev(it)->second) {
          two = a / 2;
        } else {
          one.emplace((a / 2 - offset) / sign, (a / 2 - offset) / sign);
        }
      }
    }

    int ans = zero + (two != -1 ? 2 : (!one.empty() ? 1 : 0));
    cout << 2 * N - ans << '\n';
  }
  return 0;
}