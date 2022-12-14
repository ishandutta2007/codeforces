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
typedef unsigned long long uint64;
typedef vector<int> vi;
typedef pair<int, int> ii;

class TaskD {
 public:
  uint64 compute(vector<ii>& a, const vector<uint64>& tag) {
    vector<ii> events;
    for (int i = 0; i < a.size(); ++i) {
      events.emplace_back(a[i].first, -(i + 1));
      events.emplace_back(a[i].second, i + 1);
    }
    sort(events.begin(), events.end());
    uint64 sum = 0;
    uint64 res = 0;
    for (const auto& e : events) {
      if (e.second < 0) {
        res += sum * tag[-e.second - 1];
        sum += tag[-e.second - 1];
      } else {
        sum -= tag[e.second - 1];
      }
    }
    return res;
  }

  void solveOne(istream &in, ostream &out) {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    uniform_int_distribution<uint64> distrib;
    int n; in >> n;
    vector<ii> a(n);
    vector<ii> b(n);
    vector<uint64> tag(n);
    for (int i = 0; i < n; ++i) {
      in >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
      tag[i] = distrib(rng) * 2 + 1;
    }
    auto ha = compute(a, tag);
    auto hb = compute(b, tag);
    if (ha == hb) {
      out << "YES\n";
    } else {
      out << "NO\n";
    }
  }

  void solve(std::istream &in, std::ostream &out) {
    int nt = 1;
    for (int it = 0; it < nt; ++it) {
      solveOne(in, out);
    }
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TaskD solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}