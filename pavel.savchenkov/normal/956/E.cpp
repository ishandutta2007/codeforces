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
#include <bitset>

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

int n, l, r;
vi a;
vi b;

bool read() {
  if  (scanf("%d", &n) < 1) {
    return 0;
  }
  scanf("%d%d", &l, &r);
  a.resize(n);
  forn(i, n) {
    scanf("%d", &a[i]);
  }
  b.resize(n);
  forn(i, n) {
    scanf("%d", &b[i]);
  }
  return 1;
}

const int MAXN = 1e4 + 10;

bitset<MAXN> solve0(const vi& rest) {
  bitset<MAXN> dp;
  dp[0] = 1;
  for (int x : rest) {
    dp |= dp << x;
  }
  return dp;
}

void solve() {
  vi as;
  vi rest;
  forn(i, n) {
    if  (b[i]) {
      as.pb(a[i]);
    } else {
      rest.pb(a[i]);
    }
  }

  auto dp_rest = solve0(rest);
  a = as;
  n = sz(a);

  sort(all(a));

  static int max_inside[MAXN];
  {
    memset (max_inside, 0, sizeof max_inside);
    int ptr = 0;
    int sum = 0;
    for (int h = 0; h < MAXN; ++h) {
      while (ptr < n && sum + a[ptr] <= h) {
        sum += a[ptr];
        ++ptr;
      }
      max_inside[h] = ptr;
    }
  }

  reverse(all(a));

  int ans = 0;
  bitset<MAXN> dp = dp_rest;
  bitset<MAXN> dp_not_all;
  dp[0] = 1;
  forn(i, n + 1) {
//    eprintf("i = %d\n", i);
//    forn(h, MAXN) {
//      if  (dp[h]) {
//        eprintf("%d ", h);
//      }
//    }
//    eprintf("\n");
//    forn(h, MAXN) {
//      if  (dp_not_all[h]) {
//        eprintf("%d ", h);
//      }
//    }
//    eprintf("\n");

    for (int h = l; h <= r; ++h) {
      if  (dp[h]) {
        int put = n - i;
        int slots = r - h + 1;
        --slots;
        put = min(put, max_inside[slots]);

        int cur = put;
        if  (put + i < n || dp_not_all[h]) {
          ++cur;
        }
        ans = max(ans, cur);
        break;
      }
    }

    dp_not_all |= dp_not_all << a[i];
    dp_not_all |= dp;
    dp |= dp << a[i];
  }

  printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
  freopen(FNAME ".in", "r", stdin);
  freopen(FNAME ".out", "w", stdout);
#endif

  while (read()) {
    solve();

    eprintf("\n");
  }

  return 0;
}