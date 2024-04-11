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
vi V;
vi T;

bool read() {
  if  (scanf("%d", &n) < 1) {
    return 0;
  }
  V.resize(n);
  forn(i, n) {
    scanf("%d", &V[i]);
  }
  T.resize(n);
  forn(i, n) {
    scanf("%d", &T[i]);
  }
  return 1;
}

struct Set {
  multiset<ll> s;
  ll aux;

  Set() {
    aux = 0;
  }

  void do_add(ll val) {
    aux += val;
  }

  void insert(ll val) {
    s.insert(val - aux);
  }

  void erase(ll val) {
    s.erase(s.find(val - aux));
  }

  ll get_min() const {
    assert(!s.empty());
    return *s.begin() + aux;
  }

  int size() const {
    return sz(s);
  }
};

void solve() {
  Set s;

  forn(i, n) {
    s.insert(V[i]);

    ll ans = 0;
    while (sz(s) > 0) {
      ll mn = s.get_min();
      if  (mn > T[i]) {
        break;
      }
      ans += mn;
      s.erase(mn);
    }

    ans += sz(s) * 1ll * T[i];
    s.do_add(-T[i]);

    printf("%lld ", ans);
  }
  printf("\n");
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