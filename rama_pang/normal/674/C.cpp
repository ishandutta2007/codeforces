#include <bits/stdc++.h>
using namespace std;

template<typename... Args>
void read(Args&... args) {
  ((cin >> args), ...);
}

template<typename... Args>
void write(Args&&... args) {
  ((cout << args), ...);
}

template<typename... Args>
void debug(Args&... args) {
  ((cerr << args), ...);
}

struct Line {
 public:
  int k = 0;
  double a = 0;
  double b = 1e18;
  Line() {}
  Line(int k, double a, double b) : k(k), a(a), b(b) {}
  pair<double, int> get(double x) { return {a * x + b, k}; }
};

class ConvexHull {
 public:
  int ptr = 0;
  vector<Line> ch;

  bool Bad(Line x, Line y, Line z) { // is line y bad?
    // a1x + b1 = a2x + b2
    // x = (b2 - b1) / (a1 - a2)
    return (y.b - x.b) / (x.a - y.a) > (z.b - y.b) / (y.a - z.a);
  }

  void Insert(Line x) {
    while (ch.size() >= 2 && Bad(end(ch)[-2], end(ch)[-1], x)) {
      ch.pop_back();
    }
    ch.emplace_back(x);
  }

  pair<double, int> Query(double x) {
    while (ptr >= ch.size()) ptr--;
    while (ptr + 1 < ch.size() && ch[ptr].get(x) >= ch[ptr + 1].get(x)) ptr += 1;
    return ch[ptr].get(x);
  }

  void clear() {
    ptr = 0;
    ch.clear();
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  read(N, K);

  vector<double> A(N + 1);
  vector<double> P(N + 1);
  for (int i = 1; i <= N; i++) {
    read(A[i]);
    P[i] = A[i] + P[i - 1];
  }

  // dp[j] min= dp[i] + value(i + 1, j)
  // value(i + 1, j) = \sum_{i < x <= j} (P[x] - P[i]) / A[x]
  //
  // Build E[x] = prefix sum of 1 / A[x]
  // Build C[x] = P[x] / A[x]
  // Build D[x] = prefix sum of C[x]
  //
  // value(i + 1, j) = -P[i] * (E[j] - E[i]) + \sum_{i < x <= j} C[x]
  // value(i + 1, j) = -P[i] * (E[j] - E[i]) + D[j] - D[i]
  //
  // dp[j] = minimize(i): D[j] - P[i] * E[j] + P[i] * E[i] - D[i] + dp[i]
  // Convex Hull Trick.
  //
  // -P[i] is decreasing, and query (E[j]) is increasing, so we can use a
  // stack and keep a pointer to answer everything in O(1). This runs in
  // O(N K).
  //
  // We can also use Lagrangian Relaxation / Alien's Trick to optimize
  // the complexity to O(N log MAX).

  vector<double> C(N + 1), D(N + 1), E(N + 1);
  for (int i = 1; i <= N; i++) {
    E[i] = 1.0 / A[i] + E[i - 1];
    C[i] = 1.0 * P[i] / A[i];
    D[i] = C[i] + D[i - 1];
  }

  ConvexHull cht;
  vector<pair<double, int>> dp(N + 1);
  const auto Check = [&](double lambda) -> pair<double, int> { // (value, segments)
    cht.clear();
    dp[0] = {0, 0};
    cht.Insert(Line(0, 0, 0));
    for (int j = 1; j <= N; j++) {
      // dp[j] = minimize(i): D[j] - P[i] * E[j] + P[i] * E[i] - D[i] + dp[i]
      auto q = cht.Query(E[j]);
      dp[j].first = D[j] + q.first + lambda;
      dp[j].second = 1 + q.second;
      cht.Insert(Line(dp[j].second, -P[j], P[j] * E[j] - D[j] + dp[j].first));
    }
    return dp[N];
  };

  double lo = 0, hi = 1e15;
  for (int rep = 0; rep < 70; rep++) {
    double md = (lo + hi) / 2;
    if (Check(md).second <= K) {
      hi = md;
    } else {
      lo = md;
    }
  }

  write(fixed, setprecision(12), Check(lo).first - K * lo, '\n');
  return 0;
}