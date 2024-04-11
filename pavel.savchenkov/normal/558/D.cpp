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

#define FILE_NAME ""

const ld EPS = 1e-9;

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  ll h;
  int q;
  cin >> h >> q;
  ll l = 1ll << (h - 1);
  ll r = (1ll << h) - 1;
  vector<pll> segs_not;
  while (q --> 0) {
    int i;
    ll L, R;
    int ans;
    cin >> i >> L >> R >> ans;
    forn(it, h - i) {
      L *= 2;
      R = R * 2 + 1;
    }
    if  (ans) {
      l = max(l, L);
      r = min(r, R);
    } else {
      segs_not.pb(mp(L, R));
    }    
  }

  sort(all(segs_not));
  vector<pll> nsegs_not;
  for (const auto& p : segs_not) {
    if  (nsegs_not.empty()) {
      nsegs_not.pb(p);
      continue;
    }
    if  (nsegs_not.back().snd >= p.fst) {
      nsegs_not.back().snd = max(nsegs_not.back().snd, p.snd);
    } else {
      nsegs_not.pb(p);
    }
  }
  segs_not.swap(nsegs_not);

  ll LL = (1ll << (h - 1)) - 1;
  segs_not.pb(mp(LL, LL));
  ll RR = 1ll << h;
  segs_not.pb(mp(RR, RR));
  sort(all(segs_not));

  ll cnt_good = 0;
  ll good = -1;
  forn(i, sz(segs_not) - 1) {
    ll left = segs_not[i].snd + 1;
    ll right = segs_not[i + 1].fst - 1;
    left = max(left, l);
    right = min(right, r);
    cnt_good += max(0ll, right - left + 1);
    if  (left <= right) {
      good = left;
    }
  }

  if  (cnt_good <= 0) {
    puts("Game cheated!");
  } else if  (cnt_good == 1) {
    cout << good << endl;
  } else {
    puts("Data not sufficient!");
  }

  return 0;
}