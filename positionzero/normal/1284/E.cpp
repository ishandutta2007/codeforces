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

struct Vec {
  int x, y;

  Vec(int x = 0, int y = 0) : x(x), y(y) {}

  ll operator*(const Vec& rhs) const { return x * (ll)rhs.y - y * (ll)rhs.x; }

  int region() const {
    if (y > 0 || (y == 0 && x > 0)) return 0;
    return 1;
  }
};

const int N = 2510;

int n;
int x[N], y[N];
Vec v[N * 2];

bool cmp(const Vec& lhs, const Vec& rhs) {
  if (lhs.region() != rhs.region()) return lhs.region() < rhs.region();
  return (lhs * rhs) > 0;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
  ll ans = n * (n - 1LL) * (n - 2LL) * (n - 3LL) * (n - 4LL) / 24;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      if (i != j)
        v[j - (j >= i)] = Vec(x[j] - x[i], y[j] - y[i]);
    sort(v + 1, v + n, cmp);
    copy(v + 1, v + n, v + n);
    int p = 1;
    for (int j = 1; j < n; ++j) {
      if (p < j) p = j;
      if (v[j] * v[j + 1] < 0) continue;
      while (v[j] * v[p + 1] > 0) ++p;
      int r = p - j;
      ans -= r * (r - 1LL) * (r - 2LL) / 6;
    }
  }
  cout << ans;

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}