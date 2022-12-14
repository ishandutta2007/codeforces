/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct Event {
  double at;
  double da;
  double db;
  double dc;
};

class TaskE {
 public:
  double evalAreaSimplest(double x1, double x2, double nx1, double nx2, bool sameSide) {
    double mx1 = (x1 + nx1) / 2;
    double mx2 = (x2 + nx2) / 2;
    if (sameSide) {
      return abs(mx1 - mx2);
    } else {
      return max(mx1, mx2);
    }
  }

  double evalAreaSimple(double x1, double x2, double nx1, double nx2) {
    bool sameSide = true;
    if (x1 + nx1 < 0) {
      x1 = -x1;
      nx1 = -nx1;
      sameSide = !sameSide;
    }
    if (x2 + nx2 < 0) {
      x2 = -x2;
      nx2 = -nx2;
      sameSide = !sameSide;
    }
    if ((x2 - x1) * (nx2 - nx1) < 0) {
      double y = (x2 - x1) / (nx1 - x1 - nx2 + x2);
      return evalAreaSimplest(x1, x2, x1 + y * (nx1 - x1), x2 + y * (nx2 - x2), sameSide) * y
          + evalAreaSimplest(x1 + y * (nx1 - x1), x2 + y * (nx2 - x2), nx1, nx2, sameSide) * (1 - y);
    } else {
      return evalAreaSimplest(x1, x2, nx1, nx2, sameSide);
    }
  }

  double evalArea(double x1, double x2, double nx1, double nx2, double xmid) {
    x1 -= xmid;
    x2 -= xmid;
    nx1 -= xmid;
    nx2 -= xmid;
    vector<double> interesting;
    interesting.push_back(0);
    interesting.push_back(1);
    if (x1 * nx1 < 0) {
      double y = x1 / (x1 - nx1);
      interesting.push_back(y);
    }
    if (x2 * nx2 < 0) {
      double y = x2 / (x2 - nx2);
      interesting.push_back(y);
    }
    sort(interesting.begin(), interesting.end());
    double prev = 0;
    double res = 0;
    for (int i = 1; i < interesting.size(); ++i) {
      if (interesting[i] < prev + 1e-9) continue;
      double cur = interesting[i];

      res += evalAreaSimple(x1 + prev * (nx1 - x1), x2 + prev * (nx2 - x2), x1 + cur * (nx1 - x1), x2 + cur * (nx2 - x2)) * (cur - prev);

      prev = cur;
    }
    return res;
  }

  void solveOne(istream &in, ostream &out) {
    int n, numQueries;
    in >> n >> numQueries;
    vector<ii> p(n);
    for (auto& pp : p) {
      in >> pp.first >> pp.second;
    }
    int top = 0;
    for (int j = 1; j < n; ++j) if (p[j].second > p[top].second) top = j;
    int bottom = 0;
    for (int j = 1; j < n; ++j) if (p[j].second < p[bottom].second) bottom = j;
    int left = 0;
    for (int j = 1; j < n; ++j) if (p[j].first < p[left].first) left = j;
    int leftx = p[left].first;
    int right = 0;
    for (int j = 1; j < n; ++j) if (p[j].first > p[right].first) right = j;
    int rightx = p[right].first;
    int p1 = top;
    --p1;
    if (p1 < 0) p1 += n;
    int p2 = top;
    ++p2;
    if (p2 >= n) p2 -= n;
    int y = p[top].second;

    vector<Event> events;

    while (y > p[bottom].second) {
      int ny = max(p[p1].second, p[p2].second);
      assert(ny < y);

      int q1 = p1 + 1;
      if (q1 >= n) q1 -= n;
      int q2 = p2 - 1;
      if (q2 < 0) q2 += n;

      double x1 = p[q1].first + (y - p[q1].second) / (double) (p[p1].second - p[q1].second) * (p[p1].first - p[q1].first);
      double nx1 = p[q1].first + (ny - p[q1].second) / (double) (p[p1].second - p[q1].second) * (p[p1].first - p[q1].first);
      double x2 = p[q2].first + (y - p[q2].second) / (double) (p[p2].second - p[q2].second) * (p[p2].first - p[q2].first);
      double nx2 = p[q2].first + (ny - p[q2].second) / (double) (p[p2].second - p[q2].second) * (p[p2].first - p[q2].first);

      vector<double> flips;
      flips.push_back((x1 + x2) / 2);
      flips.push_back((nx1 + nx2) / 2);
      flips.push_back(x1);
      flips.push_back(x2);
      flips.push_back(nx1);
      flips.push_back(nx2);
      flips.push_back(leftx);
      flips.push_back(rightx);
      sort(flips.begin(), flips.end());

      double prev = flips[0];
      double ca = 0;
      double cb = 0;
      double cc = 0;
      for (int i = 1; i < flips.size(); ++i) {
        if (flips[i] < prev + 1e-9) continue;
        double cur = flips[i];

        double v0 = evalArea(x1, x2, nx1, nx2, (3 * prev + cur) / 4) * (y - ny);
        double v1 = evalArea(x1, x2, nx1, nx2, (prev + cur) / 2) * (y - ny);
        double v2 = evalArea(x1, x2, nx1, nx2, (prev + 3 * cur) / 4) * (y - ny);

        double c = v1;
        double a = ((v0 + v2) - 2 * c) / 2;
        double b = (v2 - v0) / 2;

        double k = 1 / ((cur - prev) / 4);
        double r = -(cur + prev) / 2 * k;

        double na = a * k * k;
        double nb = a * 2 * k * r + b * k;
        double nc = a * r * r + b * r + c;

        Event e;
        e.at = prev;
        e.da = na - ca;
        e.db = nb - cb;
        e.dc = nc - cc;
        ca = na;
        cb = nb;
        cc = nc;
        events.push_back(e);

        prev = cur;
      }

      if (ny > p[bottom].second) {
        if (ny == p[p1].second) {
          --p1;
          if (p1 < 0) p1 += n;
        }
        if (ny == p[p2].second) {
          ++p2;
          if (p2 >= n) p2 -= n;
        }
      }
      y = ny;
    }

    sort(events.begin(), events.end(), [](const Event& a, const Event& b) { return a.at < b.at; });

    vector<pair<double, int>> queries;
    for (int i = 0; i < numQueries; ++i) {
      double x;
      in >> x;
      queries.emplace_back(x, i);
    }
    sort(queries.begin(), queries.end());

    double sa = 0;
    double sb = 0;
    double sc = 0;

    vector<double> res(numQueries);
    int i = 0;
    for (const auto& p : queries) {
      while (i < events.size() && events[i].at <= p.first) {
        sa += events[i].da;
        sb += events[i].db;
        sc += events[i].dc;
        ++i;
      }
      res[p.second] = sa * p.first * p.first + sb * p.first + sc;
    }

    for (double x : res) {
      out << x << "\n";
    }
  }

  void solve(std::istream &in, std::ostream &out) {
    out.precision(20);
    int nt = 1;
    for (int it = 0; it < nt; ++it) {
      solveOne(in, out);
    }
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TaskE solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}