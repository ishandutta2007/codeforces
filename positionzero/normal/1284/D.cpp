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

const int N = 100010;

int n, m;
int sa[N], ea[N], sb[N], eb[N], disc[N * 4], tmp[N];
vector<int> ins[N * 4], rmv[N * 4];

bool solve() {
  for (int i = 1; i <= m; ++i) {
    ins[i].clear();
    rmv[i].clear();
  }
  for (int i = 1; i <= n; ++i) {
    ins[sa[i]].push_back(i);
    rmv[ea[i]].push_back(i);
  }
  multiset<int, greater<int>> lmax;
  multiset<int> rmin;
  for (int i = 1; i <= m; ++i) {
    for (int id : ins[i]) {
      lmax.insert(sb[id]);
      rmin.insert(eb[id]);
    }
    if (!lmax.empty() && *lmax.begin() > *rmin.begin()) return true;
    for (int id : rmv[i]) {
      lmax.erase(lmax.find(sb[id]));
      rmin.erase(rmin.find(eb[id]));
    }
  }
  return false;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d%d%d", &sa[i], &ea[i], &sb[i], &eb[i]);
  copy(sa + 1, sa + n + 1, disc + 1);
  copy(ea + 1, ea + n + 1, disc + n + 1);
  copy(sb + 1, sb + n + 1, disc + n * 2 + 1);
  copy(eb + 1, eb + n + 1, disc + n * 3 + 1);
  sort(disc + 1, disc + n * 4 + 1);
  m = unique(disc + 1, disc + n * 4 + 1) - disc - 1;
  for (int i = 1; i <= n; ++i) {
    sa[i] = lower_bound(disc + 1, disc + m + 1, sa[i]) - disc;
    ea[i] = lower_bound(disc + 1, disc + m + 1, ea[i]) - disc;
    sb[i] = lower_bound(disc + 1, disc + m + 1, sb[i]) - disc;
    eb[i] = lower_bound(disc + 1, disc + m + 1, eb[i]) - disc;
  }
  bool f = solve();
  copy(sa + 1, sa + n + 1, tmp + 1);
  copy(sb + 1, sb + n + 1, sa + 1);
  copy(tmp + 1, tmp + n + 1, sb + 1);
  copy(ea + 1, ea + n + 1, tmp + 1);
  copy(eb + 1, eb + n + 1, ea + 1);
  copy(tmp + 1, tmp + n + 1, eb + 1);
  f |= solve();
  puts(f ? "NO" : "YES");

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}