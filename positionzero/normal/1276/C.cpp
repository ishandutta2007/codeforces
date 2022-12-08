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

const int N = 400010;

int n;
pair<int, int> b[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  map<int, int> mp;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    ++mp[x];
  }
  int m = 0;
  for (const auto& pr : mp)
    b[++m] = make_pair(pr.second, pr.first);
  sort(b + 1, b + m + 1, greater<pair<int, int>>());
  int p = 1;
  int cur = n;
  int best = 0, besti = 0;
  for (int i = n; i; --i) {
    while (p <= m && b[p].first > i) {
      cur -= b[p++].first;
    }
    int can = cur + (p - 1) * i;
    if (can / i >= i) {
      int real = can / i * i;
      if (best < real) {
        best = real;
        besti = i;
      }
    }
  }
  printf("%d\n%d %d\n", best, besti, best / besti);
  int nn = besti, mm = best / besti;
  vector<vector<int>> ans(nn, vector<int>(mm, 0));
  int k = 1, cc = 0;
  for (int j = 0; j < mm; ++j) {
    for (int i = 0; i < nn; ++i) {
      if (cc == min(nn, b[k].first)) {
        ++k;
        cc = 0;
      }
      ++cc;
      ans[i][(j + i) % mm] = b[k].second;
    }
  }

  for (int i = 0; i < nn; ++i) {
    for (int j = 0; j < mm; ++j) {
      printf("%d ", ans[i][j]);
    }
    putchar('\n');
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}