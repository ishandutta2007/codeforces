#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

bool Ask(const vector<int> &s) {
  cout << "? " << s.size();
  for (auto u : s) {
    cout << ' ' << u;
  }
  cout << endl;
  string res;
  cin >> res;
  return res == "YES";
}

bool Guess(int u) {
  cout << "! " << u << endl;
  string res;
  cin >> res;
  return res == ":)";
}

int32_t main() {
  int n;
  cin >> n;
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  for (int t = 0; t < 41 && a.size() > 2; t++) {
    vector<int> mod2;
    for (int i = 0; i < a.size(); i++) {
      if (i & 1) {
        mod2.push_back(a[i]);
      }
    }
    vector<int> mod4;
    for (int i = 0; i < a.size(); i++) {
      if (i >> 1 & 1) {
        mod4.push_back(a[i]);
      }
    }
    bool has2 = Ask(mod2);
    bool has4 = Ask(mod4);
    vector<int> b;
    for (int i = 0; i < a.size(); i++) {
      if ((i & 1) == has2 || (i >> 1 & 1) == has4) {
        b.push_back(a[i]);
      }
    }
    if (a.size() == b.size()) {
      assert(a.size() == 3);
      if (!Ask(vector<int>{a[2]})) {
        if (Guess(a[0])) {
          return 0;
        }
        assert(Guess(a[1]));
        return 0;
      }
      if (Guess(a[2])) {
        return 0;
      }
      if (Ask(vector<int>{a[0]})) {
        assert(Guess(a[0]));
      } else {
        assert(Guess(a[1]));
      }
      return 0;
    }
    swap(a, b);
  }
  for (auto u : a) {
    if (Guess(u)) {
      return 0;
    }
  }
  return 0;
}