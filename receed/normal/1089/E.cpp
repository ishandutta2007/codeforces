#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  while (cin >> n) {
    vector<pair<int, int>> ans;
    rep(i, 6) {
      if (i % 2)
        for (int j = 7; j >= 0; j--)
          ans.push_back({j, i});
      else
        rep(j, 8)
          ans.push_back({j, i});
    }
    int sw = (n == 63);
    rep(i, 8) {
      if ((i % 2) ^ sw) {
        ans.push_back({i, 7});
        ans.push_back({i, 6});
      } else {
        ans.push_back({i, 6});
        ans.push_back({i, 7});
      }
    }
    if (n < 63) {
      ans.resize(n);
        
      if (ans.back().first != 7 && ans.back().second != 7) {
        ans.pop_back();
        auto pp = ans.back();
        if (pp.first == 7)
          pp.second++;
        else if (pp.second == 7)
          pp.first++;
        else {
          pp.first = 7;
          if (find(all(ans), pp) != ans.end()) {
            pp = ans.back();
            pp.second = 7;
          }
        }
        ans.push_back(pp);
      }
      ans.push_back({7, 7});
    }
    assert(ans.size() == n + 1);
    rep(i, n)
      assert(ans[i].first == ans[i + 1].first || ans[i].second == ans[i + 1].second);
    for (auto &pp : ans)
      cout << (char) (pp.first + 'a') << pp.second + 1 << ' ';
    cout << '\n';
    sort(all(ans));
    assert(unique(all(ans)) == ans.end());
  }
}