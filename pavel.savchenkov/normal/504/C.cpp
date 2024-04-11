#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define all(C) begin(C), end(C)

#define debug(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr(T x) {
  return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;

ll brut(vi a, bool out = false) {
  ll ans = 0;
  vi c;
  for (int x : a) c.pb(x);
  sort(all(c));
  c.resize(unique(all(c)) - c.begin());
  for (int& x : a) x = lower_bound(all(c), x) - c.begin();

  forn(l, sz(a)) {
    for (int r = l; r < sz(a); ++r) {
      vi cnt(sz(a), 0);
      for (int i = l; i <= r; ++i) {
        ++cnt[a[i]];
      }

      forn(i, sz(a)) {
        bool me = l <= i && i <= r;
        bool fr = l <= sz(a) - i - 1 && sz(a) - i - 1 <= r;
        if  (!me && fr) {
          --cnt[a[i]];
        }
        if  (!me && !fr) {
          if  (a[i] != a[sz(a) - i - 1]) {
            cnt[0] = -1;
          }
        }
      }

      int who1 = -1;
      vi cnt_all(sz(a), 0);
      for (int x : a) ++cnt_all[x];
      forn(i, sz(a)) {
        if  (cnt_all[i] & 1) {
          if  (who1 != -1) {
            return 0;
          }
          who1 = i;
        }
      }

      bool ok = true;
      forn(i, sz(a)) {
        if  (cnt[i] < 0) ok = false;
        if  (cnt[i] & 1) ok &= who1 == -1 || who1 == i;
      }

      if  (ok) {
        if  (out) printf("%d %d\n", l, r);
        ++ans;
      }
    }
  }

  return ans;
}

ll calc_pref(vi a) {
  int n = sz(a);
  assert(a[0] != a[n - 1]);
  
  vi c;
  for (int x : a) c.pb(x);
  sort(all(c));
  c.resize(unique(all(c)) - c.begin());
  for (int& x : a) x = lower_bound(all(c), x) - c.begin();

  vi cnt(n, 0);
  for (int x : a) ++cnt[x];

  int who1 = -1;
  forn(i, n) {
    if  (cnt[i] & 1) {
      who1 = i;
    }
  }

  vi cnt_seen(n, 0);
  ford(i, n) {
    if  ((n & 1) && i == n / 2) {
      if  (a[i] != who1) {
        return n - i - 1;
      }
    } else if  (i >= n / 2) {
      int paired_inside = cnt[a[i]] / 2 - cnt_seen[a[i]];
      if  (!paired_inside) {
        return n - i - 1;
      }
    } else {
      if  (a[i] != a[n - i - 1]) {
        return n - i - 1;
      }
    }

    ++cnt_seen[a[i]];
  }

  assert(false);
  return -1;
}      

ll solve(vi a, bool out = false) {
  int n = sz(a);

  vi cnt(n, 0);
  for (int x : a) ++cnt[x];

  int cnt1 = 0;
  for (int x : cnt) cnt1 += x & 1;

  if  (cnt1 > 1) {
    return 0;
  }

  bool already = true;
  forn(i, n) {
    already &= a[i] == a[n - i - 1];
  }

  if  (already) {
    if  (out) puts("already");
    return n * 1ll * (n + 1) / 2;
  }

  int l = -1;
  int r = -1;
  forn(i, (n + 1) / 2) {
    if  (a[i] != a[n - i - 1]) {
      l = i;
      r = n - i - 1;
      break;
    } 
  }

  assert(l != -1);
  
  vi mid;
  for (int i = l; i <= r; ++i) {
    mid.pb(a[i]);
  }

  if  (out) debug(l);
  ll ans = (l + 1) * 1ll * (l + 1);
  ll pref = calc_pref(mid);
  if  (out) debug(pref);
  ans += pref * (l + 1);

  reverse(all(mid));
  ll suff = calc_pref(mid);
  if  (out) debug(suff);
  ans += suff * (l + 1);

  return ans;
}           

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  int n;
  scanf("%d", &n);
  vi a(n);
  forn(i, n) {
    scanf("%d", &a[i]);
    --a[i];
  }

  cout << solve(a) << endl;
  return 0;

  while (1) {
    int n = rand() % 10 + 1;
    vi a(n);
    forn(i, n) a[i] = rand() % max(1, min(n, 3));
//    cout << solve(a) << endl;
//    cout << "brut force: " << brut(a) << endl;

    if  (solve(a) != brut(a)) {
      printf("n = %d\n", n);
      forn(i, n) printf("%d ", a[i]);
      puts("");
      printf("my = %I64d, brut = %I64d\n", solve(a, true), brut(a, true));
      return 0;
    } else {
      printf("OK n = %d\n", n);
    }

  }

  return 0;
}