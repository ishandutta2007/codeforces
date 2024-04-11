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
#include <fstream>
#include <unordered_map>
#include <unordered_set>

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
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

int n, k, b, c;
vi t;

bool read() {
  if  (scanf("%d%d%d%d", &n, &k, &b, &c) < 4) {
    return false;
  }
  t.resize(n);
  forn(i, n) {
    scanf("%d", &t[i]);
  }
  return true;
}

const ll INF = 1e18;

ll solve(vi t, int rem) {
  vi aux(n, 0);
  forn(i, n) {
    while ((t[i] % 5 + 5) % 5 != rem) {
      ++t[i];
      aux[i] += c;
    }
  }

  ll ans = INF;

  // ans = (t * k - sum) / 5 * b + aux
  // ans = t * k / 5 * b - sum / 5 * b + aux
  // -sum / 5 + aux --> max
  // -sum + 5 * aux --> max
  multiset<ll> s;
  ll S = 0;
  forn(i, n) {
    ll val = -t[i] * 1ll * b + 5 * aux[i];
    s.insert(val);
    S += val;
    if  (sz(s) > k) {
      S -= *s.rbegin();
      s.erase(s.find(*s.rbegin()));
    } 

    if  (sz(s) == k) {
      ll cur = t[i] * 1ll * k * 1ll * b + S;
      ans = min(ans, t[i] * 1ll * k * 1ll * b + S);
    }
  }
          
  return ans / 5;
}

ll solve() {
  sort(all(t));

  if  (c * 5 <= b) {
    ll ans = INF;
    ll s = 0;
    forn(i, n) {
      s += t[i];
      if  (i - k >= 0) {
        s -= t[i - k];
      }
      if  (i >= k - 1) {
        ans = min(ans, (k * 1ll * t[i] - s) * c);
      }
    } 
    return ans;
  }

  ll ans = INF;
  forn(rem, 5) {
    ans = min(ans, solve(t, rem));
  }
  return ans;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
  //freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    cout << solve() << endl;
    break;
  }

#ifdef LOCAL
  cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}