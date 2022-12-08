#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int m = count(s.begin(), s.end(), '(');
    string t;
    for (int rep = 1; rep < k; ++rep) {
      t.push_back('(');
      t.push_back(')');
    }
    for (int rep = 0; rep < m - k + 1; ++rep)
      t.push_back('(');
    for (int rep = 0; rep < m - k + 1; ++rep)
      t.push_back(')');
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
      int j = i;
      while (s[j] != t[i])
        ++j;
      ans.emplace_back(i, j);
      reverse(s.begin() + i, s.begin() + j + 1);
    }
    cout << ans.size() << '\n';
    for (auto [l, r] : ans)
      cout << l + 1 << ' ' << r + 1 << '\n';
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}