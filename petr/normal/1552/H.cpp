/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

// Actual solution is at the bottom

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
//#include "../atcoder/all"

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int64_t int64;
typedef pair<int, int> ii;

void resolve(vector<ii> cands, int togo) {
  if (cands.empty()) return;
  if (togo == 0) {
    assert(cands.size() == 1);
  }
  int bw = -1;
  int bs = (int) 1e9;
  for (int w = 2; w <= 200; ++w) {
    map<int, vector<ii>> poss;
    for (ii x : cands) {
      int got = x.first / w * x.second;
      poss[got].push_back(x);
      if (x.first % w != 0) {
        got += x.second;
        poss[got].push_back(x);
      }
    }
    int score = 0;
    for (auto p : poss) score = max(score, (int) p.second.size());
    if (score < bs) {
      bs = score;
      bw = w;
    }
  }
  {
    int w = bw;
    map<int, vector<ii>> poss;
    for (ii x : cands) {
      int got = x.first / w * x.second;
      poss[got].push_back(x);
      if (x.first % w != 0) {
        got += x.second;
        poss[got].push_back(x);
      }
    }
    for (auto p : poss) {
      resolve(p.second, togo - 1);
    }
  }
}

class HUgadaitePerimetr {
 public:
  void solveOne() {
/*    map<int, vector<pair<int, int>>> mx;
    for (int a = 2; a <= 200; ++a) {
      for (int b = 2; b <= 200; ++b) {
        mx[a * b].emplace_back(a, b);
      }
    }
    int r = 0;
    for (const auto& p : mx) {
      cerr << p.first << endl;
      resolve(p.second, 3);
    }
    cout << r << "\n";*/
    vector<ii> cands;
    for (int a = 2; a <= 200; ++a) {
      for (int b = 2; b <= 200; ++b) {
        cands.emplace_back(a, b);
      }
    }
    auto apply = [&](int w) {
      vector<ii> q;
      for (int i = 0; i < 200; ++i) {
        for (int j = 0; j < 200; ++j) {
          if (i % w == 0) {
            q.emplace_back(i, j);
          }
        }
      }
      cout << "? " << q.size() << "\n";
      for (auto p : q) cout << p.first + 1 << " " << p.second + 1 << " ";
      cout << "\n";
      cout.flush();
      int got;
      cin >> got;
      vector<ii> ncands;
      for (ii x : cands) {
        int could = x.first / w * x.second;
        if (could == got) ncands.push_back(x);
        if (x.first % w != 0) {
          could += x.second;
          if (could == got) ncands.push_back(x);
        }
      }
      cands.swap(ncands);
    };
    apply(1);
    while (cands.size() > 1) {
      int bw = -1;
      int bs = (int) 1e9;
      for (int w = 2; w <= 200; ++w) {
        map<int, vector<ii>> poss;
        for (ii x : cands) {
          int got = x.first / w * x.second;
          poss[got].push_back(x);
          if (x.first % w != 0) {
            got += x.second;
            poss[got].push_back(x);
          }
        }
        int score = 0;
        for (auto p : poss) score = max(score, (int) p.second.size());
        if (score < bs) {
          bs = score;
          bw = w;
        }
      }
      apply(bw);
    }
    cout << "! " << 2 * ((cands[0].first - 1) + (cands[0].second - 1)) << "\n";
    cout.flush();
  }

  void solve() {
    int nt = 1;
    for (int it = 0; it < nt; ++it) {
      solveOne();
    }
  }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    HUgadaitePerimetr solver;


    solver.solve();
    return 0;
}