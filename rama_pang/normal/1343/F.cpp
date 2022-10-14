#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Solve() {
  int n;
  cin >> n;
  vector<set<int>> segs, original;
  set<set<int>> exist;
  for (int i = 1; i < n; i++) {
    int k;
    cin >> k;
    segs.emplace_back();
    for (int j = 0; j < k; j++) {
      int a;
      cin >> a;
      segs.back().emplace(--a);
    }
    exist.emplace(segs.back());
  }
  original = segs;

  for (int first = 0; first < n; first++) {
    segs = original;
    vector<int> p;
    p.emplace_back(first);
    for (int i = 0; i < (int) segs.size(); i++) {
      if (segs[i].count(first)) {
        segs[i].erase(first);
      }
    }
    while (p.size() < n) {
      bool has = false;
      for (int i = 0; i < (int) segs.size(); i++) {
        if (segs[i].size() == 1) {
          p.emplace_back(*begin(segs[i]));
          has = true;
          break;
        }
      }
      if (!has) break;
      for (int i = 0; i < (int) segs.size(); i++) {
        if (segs[i].count(p.back())) {
          segs[i].erase(p.back());
        }
      }
    }

    if (p.size() < n) continue;
    bool can = true;
    for (int i = 1; i < n; i++) {
      set<int> cur;
      cur.emplace(p[i]);
      int cnt = 0;
      for (int j = i - 1; j >= 0; j--) {
        cur.emplace(p[j]);
        if (exist.count(cur)) {
          cnt++;
        }
      }
      if (cnt != 1) {
        can = false;
        break;
      }
    }

    if (can) {
      for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " \n"[i == n - 1];
      }
      return;
    }
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    Solve();
  }

}