#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> p(n, -1);
  vector<int> deg(n);
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    p[i]--;
    deg[p[i]]++;
  }
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<set<pair<long long, long long>>> s(n);
  const auto Insert = [&](int id, pair<long long, long long> nw) {
    auto it = s[id].lower_bound({nw.first, -1});
    while (it != end(s[id]) && it->first == nw.first) {
      nw.second += it->second;
      it = s[id].erase(it);
    }
    s[id].insert(nw);
  };

  for (int i = n - 1; i >= 0; i--) {
    if (deg[i] == 0) {
      Insert(i, {a[i], 1});
    } else {
      while (a[i] > 0) {
        auto cur = *begin(s[i]);
        s[i].erase(cur);
        if (a[i] < cur.second) {
          Insert(i, {cur.first + 1, a[i]});
          Insert(i, {cur.first, cur.second - a[i]});
          break;
        }
        if (s[i].empty()) {
          long long all = a[i] / cur.second;
          cur.first += all;
          a[i] %= cur.second;
          Insert(i, cur);
        } else {
          auto nxt = begin(s[i]);
          long long all = min(a[i] / cur.second, nxt->first - cur.first);
          cur.first += all;
          a[i] -= all * cur.second;
          Insert(i, cur);
        }
      }
    }

    if (i > 0) {
      if (s[p[i]].size() < s[i].size()) {
        swap(s[p[i]], s[i]);
      }
      for (auto j : s[i]) {
        Insert(p[i], j);
      }
    }
  }

  cout << rbegin(s[0])->first << "\n";
  return 0;
}