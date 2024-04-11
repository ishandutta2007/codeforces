#include <bits/stdc++.h>
using namespace std;

using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  // dpL[n][x] = left is k[n], right is x
  // dpR[n][x] = left is x, right is k[n]
  // dpL[n + 1][x] = 
  // - loL[n + 1] <= k[n + 1] && k[n + 1] <= hiL[n] && 
  //   ((dpL[n][x] && loR[n + 1] <= x && x <= hiR[n + 1]) || 
  //    (dpR[n][.] && loR[n + 1] <= k[n] && k[n] <= hiR[n + 1]))

  set<pair<int, int>> dpL, dpR;
  dpL.emplace(0, -1);
  dpR.emplace(0, -1);
  map<array<int, 3>, array<int, 3>> prv;
  int lastItem = 0;
  for (int i = 0; i < N; i++) {
    int k, loL, hiL, loR, hiR;
    cin >> k >> loL >> hiL >> loR >> hiR;
    pair<int, int> szL = dpL.empty() ? pair(-1, -1) : *begin(dpL);
    pair<int, int> szR = dpR.empty() ? pair(-1, -1) : *begin(dpR);
    if (loL <= k && k <= hiL) {
      while (!dpL.empty() && begin(dpL)->first < loR) {        
        dpL.erase(begin(dpL));
      }
      while (!dpL.empty() && rbegin(dpL)->first > hiR) {
        dpL.erase(prev(end(dpL)));
      }
      if (szR.first != -1 && loR <= lastItem && lastItem <= hiR) {
        dpL.emplace(lastItem, i);
        prv[{0, lastItem, i}] = {1, szR.first, szR.second};
      }
    } else {
      while (!dpL.empty()) {
        dpL.erase(begin(dpL));
      }
    }
    if (loR <= k && k <= hiR) {
      while (!dpR.empty() && begin(dpR)->first < loL) {
        dpR.erase(begin(dpR));
      }
      while (!dpR.empty() && rbegin(dpR)->first > hiL) {
        dpR.erase(prev(end(dpR)));
      }
      if (szL.first != -1 && loL <= lastItem && lastItem <= hiL) {
        prv[{1, lastItem, i}] = {0, szL.first, szL.second};
        dpR.emplace(lastItem, i);
      }
    } else {
      while (!dpR.empty()) {
        dpR.erase(begin(dpR));
      }
    }
    lastItem = k;
  }
  if (dpL.empty() && dpR.empty()) {
    cout << "No\n";
    return 0;
  }

  array<int, 3> last = {-1, -1, -1};
  while (!dpL.empty()) {
    last = {0, begin(dpL)->first, begin(dpL)->second};
    dpL.erase(begin(dpL));
  }
  while (!dpR.empty()) {
    last = {1, begin(dpR)->first, begin(dpR)->second};
    dpR.erase(begin(dpR));
  }

  int t = N;
  vector<int> ans;
  while (true) {
    int tp = last[0];
    if (prv.count(last) == 0) {
      while (ans.size() < N) ans.emplace_back(tp);
      break;
    } else {
      int diff = t - last[2];
      t = last[2];
      while (diff--) ans.emplace_back(tp);
      last = prv[last];
    }
  }

  reverse(begin(ans), end(ans));

  cout << "Yes\n";
  for (auto x : ans) cout << x << ' '; cout << '\n';  
  return 0;
}