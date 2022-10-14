#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    long long s;
    cin >> n >> s;
    vector<pair<long long, long long>> crit(n); // cirteria
    for (auto& i : crit) {
      cin >> i.first >> i.second;
    }
    sort(begin(crit), end(crit), greater<pair<long long, long long>>());
    
    auto check = [&](long long mn) {
      int cnt = 0;
      long long money = s;
      vector<pair<long long, long long>> undec;
      for (auto& i : crit) {
        if (i.second < mn) {
          money -= i.first;
          continue;
        }
        if (mn <= i.first) {
          money -= i.first;
          cnt++;
          continue;
        }
        undec.emplace_back(i);
      }

      if (undec.size() + cnt < (n + 1) / 2) {
        return false;
      }
      int rem = (n + 1) / 2 - cnt;
      for (int i = 0; i < rem; i++) {
        money -= mn;
      }
      for (int i = rem; i < undec.size(); i++) {
        money -= undec[i].first;
      }
      return money >= 0;
    };

    long long lo = 0, hi = 1e17;
    while (lo < hi) {
      long long mid = (lo + hi + 1) / 2;
      if (check(mid)) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    cout << lo << "\n";
  }

}