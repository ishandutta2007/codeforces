#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  double C, M, P, V;
  cin >> C >> M >> P >> V;

  vector<pair<array<double, 3>, double>> memo;
  const double EPS = 1e-9;
  const auto Get = [&](double c, double m, double p) -> pair<bool, double> {
    for (auto &[s, val] : memo) {
      if (abs(s[0] - c) < EPS && abs(s[1] - m) < EPS && abs(s[2] - p) < EPS) {
        return {true, val};
      }
    }
    return {false, 0};
  };
  const auto Transform = [&](int ops, double c, double m, double p) -> array<double, 3> {
    if (ops == 0) {
      double a = min(c, V);
      c -= a;
      if (!(m < EPS)) {
        m += a / 2;
        p += a / 2;
      } else {
        p += a;
      }
    } else if (ops == 1) {
      double a = min(m, V);
      m -= a;
      if (!(c < EPS)) {
        c += a / 2;
        p += a / 2;
      } else {
        p += a;
      }
    }
    return {c, m, p};
  };
  const auto Dfs = [&](const auto &self, double c, double m, double p) {
    auto gg = Get(c, m, p);
    if (gg.first) {
      return gg.second;
    }
    double ev = 1;
    array<double, 3> s = {c, m, p};
    for (int i = 0; i < 2; i++) {
      if (s[i] < EPS) continue;
      auto nxt = Transform(i, c, m, p);
      ev += s[i] * self(self, nxt[0], nxt[1], nxt[2]);
    }
    memo.push_back(pair(s, ev));
    return ev;
  };

  cout << fixed << setprecision(12) << Dfs(Dfs, C, M, P) << '\n';
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