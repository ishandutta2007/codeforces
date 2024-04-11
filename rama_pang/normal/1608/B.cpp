#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n, a, b;
  cin >> n >> a >> b;
  int cnt = 0;
  vector<int> mark(n);
  for (int i = 1; i < n - 1; i += 2) {
    mark[i] = 1;
    cnt += 1;
    if (cnt == a) {
      break;
    }
  }
  for (int r = 0; r < 2; r++) {
    vector<int> ans(n, -1);
    int ptr = 0;
    for (int i = 0; i < n; i += 2) {
      ans[i] = ptr++;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (ans[i] == -1) ans[i] = ptr++;
    }
    if (r == 1) {
      for (int i = 0; i < n; i++) {
        ans[i] = n - 1 - ans[i];
      }
    }
    int localmin = 0, localmax = 0;
    for (int i = 0; i < n; i++) {
      if (i >= 2) {
        localmin += ans[i - 1] < ans[i] && ans[i - 1] < ans[i - 2];
        localmax += ans[i - 1] > ans[i] && ans[i - 1] > ans[i - 2];
      }
      const auto ok = [&]() {
        int cntb = 0, cnta = 0;
        for (int i = 1; i <= n - 2; i++) {
          if (ans[i - 1] < ans[i] && ans[i + 1] < ans[i]) cnta++;
          if (ans[i - 1] > ans[i] && ans[i + 1] > ans[i]) cntb++;
        }
        if (a == cnta && b == cntb) {
          for (int i = 0; i < n; i++) cout << ans[i] + 1 << ' '; cout << '\n';
        }
        return a == cnta && b == cntb;
      };
      if (localmax == a && localmin == b) {
        sort(begin(ans) + i, end(ans));
        if (ok()) return;
        reverse(begin(ans) + i, end(ans));
        if (ok()) return;
        assert(false);
      }
    }
  }
  cout << -1 << '\n';
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