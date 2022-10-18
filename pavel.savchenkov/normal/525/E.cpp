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
#include <complex>
#include <bitset>

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
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

const ld EPS = 1e-9;
const ll INF = 1e16 + 10;

ll fac[50];
ll fact(int n) {
  if  (n >= 19) {
    return INF;
  }
  return fac[n];
}

bool bit(int mask, int i) {
  return (mask >> i) & 1;
}
 
void precalc() {
  fac[0] = 1ll;
  for (int i = 1; i <= 19; ++i) {
    fac[i] = fac[i - 1] * i;
  } 
}

// (sum, facts)
vector<pair<ll, int> > gen(const vi& a) {
  vector<pair<ll, int> > res;

  int n = sz(a);
  forn(mask, 1 << n) {
    ll s = 0;
    forn(i, n) if  (bit(mask, i)) s += a[i];

    for (int sub = mask; ; sub = (sub - 1) & mask) {
      ll ss = s;
      forn(i, n) {
        if  (bit(sub, i)) {
          ss -= a[i];
          ss += fact(a[i]);
        }
      }

      if  (ss < INF) {
        res.pb(mp(ss, __builtin_popcount(sub)));
      }

      if  (!sub) {
        break;
      } 
    }
  }

  return res;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  precalc();

  int n, k;
  ll S;
  cin >> n >> k >> S;

  vi a(n);
  forn(i, n) {
    scanf("%d", &a[i]);
  }

  vi a1;
  vi a2;
  forn(i, n) {
    if  (i < n / 2) {
      a1.pb(a[i]);  
    } else {
      a2.pb(a[i]);
    }
  }
  
  auto g1 = gen(a1); sort(all(g1));
  auto g2 = gen(a2); sort(all(g2));
/*  
  forn(i, sz(g1)) {
    cout << g1[i].fst << " " << g1[i].snd << endl;
  }
  puts("");

  forn(i, sz(g2)) {
    cout << g2[i].fst << " " << g2[i].snd << endl;
  }
  puts("");
*/

  ll ans = 0;
  int prev = -1;
  forn(i, sz(g1)) {
    if  (i + 1 < sz(g1) && g1[i] == g1[i + 1]) {
      continue;
    }

    int cnt1 = i - prev;
    prev = i;

    ll s1;
    int k1;
    tie(s1, k1) = g1[i];

    int cnt2 = upper_bound(all(g2), mp(S - s1, k - k1)) - lower_bound(all(g2), mp(S - s1, 0));

//    printf("cnt1=%d, s1=%I64d, k1=%d, cnt2=%d\n", cnt1, s1, k1, cnt2);
    ans += cnt1 * 1ll * cnt2;
  }

  cout << ans << endl;   
  return 0;
}