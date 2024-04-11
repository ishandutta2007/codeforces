#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;

  vector<long long> a(n);
  vector<long long> b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  
  if (n == 1) {
    if (a == b) {
      cout << "SMALL" << "\n";
      cout << 0 << "\n";
      cout << "\n";
    } else {
      cout << "IMPOSSIBLE\n";
    }
  } else if (n == 2) {
    int swapa = 0;
    if (a[0] > a[1]) swapa = 1, swap(a[0], a[1]);

    vector<pair<int, long long>> history;
    while (a[0] != b[0]) {
      if (b[0] > b[1]) {
        history.emplace_back(2, 1);
        swap(b[0], b[1]);
      } else {
        if (b[0] == 0) break;
        history.emplace_back(1, b[1] / b[0]);
        b[1] %= b[0];
      }
    }
    if (a[0] == b[0]) {
      if (abs(b[1] - a[1]) % a[0] != 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
      } else {
        history.emplace_back(1, (b[1] - a[1]) / a[0]);
      }
    } else {
      cout << "IMPOSSIBLE\n";
      return 0;
    }

    if (swapa) {
      history.emplace_back(2, 1);
    }
    reverse(begin(history), end(history));

    long long all = 0;
    long long pref = 0;
    for (auto i : history) {
      if (i.first == 1) {
        pref += i.second;
      }
      all += i.second;
    }
    if (pref <= 200000) {
      cout << "SMALL" << "\n";
      cout << all << "\n";
      for (auto i : history) {
        while (i.second--) {
          if (i.first == 1) {
            cout << 'P';
          } else {
            cout << 'R';
          }
        }
      }
      cout << "\n";
    } else {
      cout << "BIG" << "\n";
      cout << pref << "\n";
      cout << "\n";
    }


  } else {
    vector<int> history;
    while (true) {
      if (a == b) {
        break;
      }
      if (is_sorted(begin(b), end(b), [&](long long p, long long q) { return p <= q; })) {
        history.emplace_back(1);
        for (int i = n - 1; i > 0; i--) {
          b[i] -= b[i - 1];
        }
      } else if (is_sorted(begin(b), end(b), [&](long long p, long long q) { return p >= q; })) {
        history.emplace_back(2);
        reverse(begin(b), end(b));
      } else {
        if (a == b) {
          break;
        }
        reverse(begin(b), end(b));
        history.emplace_back(2);
        if (a == b) {
          break;
        }
        cout << "IMPOSSIBLE\n";
        return 0;
      }
    }
    reverse(begin(history), end(history));
    int pref = 0;
    for (auto i : history) {
      if (i == 1) {
        pref++;
      }
    }
    if (pref > 200000) {
      cout << "BIG" << "\n";
      cout << pref << "\n";
    } else {
      cout << "SMALL" << "\n";
      cout << history.size() << "\n";
      for (auto i : history) {
        if (i == 1) {
          cout << 'P';
        } else {
          cout << 'R';
        }
      }
      cout << "\n";
    }
  }

  return 0;
}