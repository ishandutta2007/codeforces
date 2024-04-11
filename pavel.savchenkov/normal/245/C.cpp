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

int n;
vi a;

bool read() {
  if  (scanf("%d", &n) < 1) {
    return 0;
  }
  a.resize(n);
  forn(i, n) {
    scanf("%d", &a[i]);
  }
  return 1;
}

int solve() {
  if  (n % 2 == 0 || n == 1) {
    return -1;
  }
  int ans = 0;
  ford(i, n) {
    if  (!i) {
      break;
    }
    while (a[i] > 0) {
      int x = (i + 1) / 2;
      int x2 = x * 2;
      int x2_1 = x2 + 1;
      --a[x - 1];
      --a[x2 - 1];
      --a[x2_1 - 1];
      ++ans;
    }
  } 
  ans += max(a[0], 0);
  return ans;
}

int main() {
#ifdef LOCAL
  freopen(FNAME ".in", "r", stdin);
  freopen(FNAME ".out", "w", stdout);
#endif

  while (read()) {
    int ans = solve();
    printf("%d\n", ans);
  }

  return 0;
}