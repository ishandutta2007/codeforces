#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <memory.h>
#include <algorithm>
#include <cassert>

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fst first
#define snd second

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;

#define FNAME "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#endif

int x2;

bool read() {
  if  (scanf("%d", &x2) < 1) {
    return 0;
  }
  return 1;
}

const int MAX = 1e6 + 10;

bool is_p[MAX];
int maxp[MAX];

void precalc() {
  memset (is_p, 1, sizeof is_p);
  for (int i = 2; i < MAX; ++i) {
    if  (is_p[i]) {
      for (int j = 2 * i; j < MAX; j += i) {
        is_p[j] = 0;
      }
    }
  }

  memset (maxp, -1, sizeof maxp);
  for (int i = 2; i < MAX; ++i) {
    if  (is_p[i]) {
      for (int j = i; j < MAX; j += i) {
        maxp[j] = max(maxp[j], i);
      }
    }
  }
}

int solve() {
  int ans = MAX;

  int tmp = x2;
  while (maxp[tmp] != -1) {
    const int p = maxp[tmp];
    while (maxp[tmp] == p) {
      tmp /= p;
    }

    assert(p < x2);
    for (int x1 = x2 - p + 1; x1 <= x2; ++x1) {
      const int pp = maxp[x1];
      if  (pp != x1) {
        ans = min(ans, x1 - pp + 1);
      }
    }
  }

  return ans;
}

int main() {
#ifdef LOCAL
  freopen(FNAME ".in", "r", stdin);
  freopen(FNAME ".out", "w", stdout);
#endif

  precalc();

  while (read()) {
    cout << solve() << '\n';
  }

  return 0;
}