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
vi m;

bool read() {
  if  (scanf("%d", &n) < 1) {
    return 0;
  }
  m.resize(n);
  forn(i, n) {
    scanf("%d", &m[i]);
  }
  return 1;
}

void solve() {
  vi dp(n);
  dp[n - 1] = 0;
  ford(i, n - 1) {
    int want = m[i + 1] + dp[i + 1];
    // m[i] + 1 + dp[i] >= want
    dp[i] = max(0, want - m[i] - 1);
  }
  eprintf("dp:\n");
  forn(i, n) {
    eprintf("%d ", dp[i]);
  }
  eprintf("\n");
  assert(dp[0] == 0);

  ll ans = 0;
  int got = 0;
  forn(i, n) {
    int want = m[i] + 1 + dp[i];
    if  (got < want) {
      assert(got + 1 == want);
      ++got;
    }
    ans += got - 1 - m[i];
  }
  printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
  freopen(FNAME ".in", "r", stdin);
  freopen(FNAME ".out", "w", stdout);
#endif

  while (read()) {
    solve();
  }

  return 0;
}