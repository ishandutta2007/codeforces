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

struct Card {
  int left;
  int right;
  bool wasRev = false;
};

struct dsu {
 public:
  dsu() : _n(0) {}
  dsu(int n) : colorDelta(n), _n(n), parent_or_size(n, -1) {}

  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y) return x;
    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    colorDelta[y] = colorDelta[a] ^ colorDelta[b] ^ 1;
    return x;
  }

  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0) return a;
    int res = leader(parent_or_size[a]);
    colorDelta[a] ^= colorDelta[parent_or_size[a]];
    parent_or_size[a] = res;
    return res;
  }

  int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }

  std::vector<std::vector<int>> groups() {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(
        std::remove_if(result.begin(), result.end(),
                       [&](const std::vector<int>& v) { return v.empty(); }),
        result.end());
    return result;
  }

  std::vector<int> colorDelta;

 private:
  int _n;
  // root node: -1 * component size
  // otherwise: parent
  std::vector<int> parent_or_size;
};

class DPereverniteKarti {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<Card> card(n);
    for (auto& c : card) {
      cin >> c.left >> c.right;
      --c.left; --c.right;
      if (c.left > c.right) {
        swap(c.left, c.right);
        c.wasRev = true;
      }
    }
    int minRight = card[0].right;
    int maxLeft = card[0].left;
    for (auto c : card) {
      minRight = min(minRight, c.right);
      maxLeft = max(maxLeft, c.left);
    }
    if (minRight < maxLeft) {
      cout << -1 << "\n";
      return;
    }
    sort(all(card), [](const Card& a, const Card& b) {
      return a.left < b.left;
    });
    vector<int> rightToIndex(2 * n, -1);
    for (int i = 0; i < n; ++i) rightToIndex[card[i].right] = i;
    vector<int> smallest0(n, -1);
    vector<int> smallest1(n, -1);
    dsu comp(n);
    set<int> interesting;
    const int INF = (int) 1e9;
    for (int i = 0; i < n; ++i) {
      smallest0[i] = card[i].right;
      smallest1[i] = INF;
      while (!interesting.empty() && *interesting.begin() < card[i].right) {
        int a = rightToIndex[*interesting.begin()];
        interesting.erase(interesting.begin());
        int la = comp.leader(a);
        int lb = comp.leader(i);
        if (la == lb) {
          if (comp.colorDelta[a] == comp.colorDelta[i]) {
            cout << -1 << "\n";
            return;
          }
        } else {
          int r = comp.merge(a, i);
          if (r == la) {
            if (comp.colorDelta[lb] == 0) {
              smallest0[r] = min(smallest0[r], smallest0[lb]);
              smallest1[r] = min(smallest1[r], smallest1[lb]);
            } else {
              smallest0[r] = min(smallest0[r], smallest1[lb]);
              smallest1[r] = min(smallest1[r], smallest0[lb]);
            }
          } else {
            if (comp.colorDelta[la] == 0) {
              smallest0[r] = min(smallest0[r], smallest0[la]);
              smallest1[r] = min(smallest1[r], smallest1[la]);
            } else {
              smallest0[r] = min(smallest0[r], smallest1[la]);
              smallest1[r] = min(smallest1[r], smallest0[la]);
            }
          }
        }
      }
      int r = comp.leader(i);
      if (smallest0[r] < INF) interesting.insert(smallest0[r]);
      if (smallest1[r] < INF) interesting.insert(smallest1[r]);
    }
    vector<int> scoreIfNotRev(n);
    vector<int> scoreIfRev(n);
    for (int i = 0; i < n; ++i) {
      int r = comp.leader(i);
      if (comp.colorDelta[i] == 0) {
        if (card[i].wasRev) {
          ++scoreIfRev[r];
        } else {
          ++scoreIfNotRev[r];
        }
      } else {
        if (!card[i].wasRev) {
          ++scoreIfRev[r];
        } else {
          ++scoreIfNotRev[r];
        }
      }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      res += min(scoreIfNotRev[i], scoreIfRev[i]);
    }
    cout << res << "\n";
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
    DPereverniteKarti solver;


    solver.solve();
    return 0;
}