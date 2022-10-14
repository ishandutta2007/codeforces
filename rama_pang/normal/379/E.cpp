#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;
  vector<vector<int>> S(N, vector<int>(K + 1));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= K; j++) {
      cin >> S[i][j];
    }
  }

  const auto GetArea = [&](vector<pair<double, double>> segments) -> double {
    { // erase lines with same slope
      sort(begin(segments), end(segments));
      static vector<pair<double, double>> ns; ns.clear();
      for (auto s : segments) {
        if (!ns.empty() && ns.back().first == s.first) {
          ns.pop_back();
        }
        ns.emplace_back(s);
      }
      segments = ns;
    }

    static vector<pair<double, double>> cht; cht.clear();
    static const auto Intersection = [&](pair<double, double> one, pair<double, double> two) -> double {
      // x-intersection
      // y = m1 * x + c1
      // y = m2 * x + c2
      // m1 * x + c1 = m2 * x + c2
      // (m1 - m2) * x = c2 - c1
      // x = (c2 - c1) / (m1 - m2)
      return (two.second - one.second) / (one.first - two.first);
    };
    for (const auto &s : segments) {
      while (cht.size() > 1 && Intersection(end(cht)[-2], s) <= Intersection(end(cht)[-2], end(cht)[-1])) {
        cht.pop_back();
      }
      cht.emplace_back(s);
    }

    static const auto Evaluate = [&](const pair<double, double> &s, double x) {
      return s.first * x + s.second;
    };

    while (cht.size() > 1 && Intersection(end(cht)[-2], end(cht)[-1]) > 1) {
      cht.pop_back();
    }

    reverse(begin(cht), end(cht));
    while (cht.size() > 1 && Intersection(end(cht)[-2], end(cht)[-1]) < 0) {
      cht.pop_back();
    }
    reverse(begin(cht), end(cht));

    static vector<pair<double, double>> points; points.clear();
    points.emplace_back(0, 0);
    points.emplace_back(0, Evaluate(cht[0], 0));
    for (int i = 0; i + 1 < cht.size(); i++) {
      double x = Intersection(cht[i], cht[i + 1]);
      points.emplace_back(x, Evaluate(cht[i], x));
    }
    points.emplace_back(1, Evaluate(cht.back(), 1));
    points.emplace_back(1, 0);

    double area = 0;
    for (int i = 0; i + 1 < points.size(); i++) {
      area += points[i].first * points[i + 1].second;
      area -= points[i].second * points[i + 1].first;
    }
    area += points.back().first * points.front().second;
    area -= points.back().second * points.front().first;

    return abs(area) / 2;
  };

  vector<double> ans(N);
  for (int k = 0; k < K; k++) {
    vector<pair<double, double>> segs;
    for (int i = 0; i < N; i++) {
      segs.emplace_back(pair(S[i][k + 1] - S[i][k], S[i][k]));
      for (int j = int(segs.size()) - 2; j >= 0; j--) {
        if (segs[j] > segs[j + 1]) {
          swap(segs[j], segs[j + 1]);
        }
      }
      ans[i] += GetArea(segs);
    }
  }

  cout << fixed << setprecision(20);
  for (int i = 0; i < N; i++) {
    cout << ans[i] - (i > 0 ? ans[i - 1] : 0) << '\n';
  }
  return 0;
}