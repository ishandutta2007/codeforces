#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  int curmin = 0;
  vector<int> in(n, 1);
  deque<int> dq;
  const auto Solve = [&](const auto &self, int rr) -> void {
    if (rr == 0) return;
    while (in[curmin] == 0) curmin++;
    for (int i = rr - 1; i >= 0; i--) {
      in[a[i]] = 0;
      if (a[i] == curmin) {
        self(self, i);
        dq.emplace_front(a[i]);
        for (int j = i + 1; j < rr; j++) {
          dq.emplace_back(a[j]);
        }
        return;
      }
    }
  };
  Solve(Solve, n);
  for (auto i : dq) cout << i + 1 << ' '; cout << '\n';
  return;
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