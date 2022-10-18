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
const int MAXN = 1e5 + 10;
const int AL = 26;

char s[MAXN];

pair<vi, string> read() {
  gets(s);
  vi cnt(AL, 0);
  string t(s);
  forn(i, sz(t)) ++cnt[t[i] - 'a'];
  return mp(cnt, t);
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
  freopen(FILE_NAME ".out", "w", stdout);
#endif

  vi a;
  string A;
  tie(a, A) = read();

  vi b;
  string B;
  tie(b, B) = read();

  vi c;
  string C;
  tie(c, C) = read();

  int cnt_B = 0;
  int cnt_C = 0;
  forn(cnt_b, MAXN) {
    vi rest(AL, 0);
    bool bad = false;
    forn(i, AL) {
      ll val = a[i] - b[i] * 1ll * cnt_b;
      if  (val < 0) {
        bad = true;
        break;
      }
      rest[i] = val;
    }
    if  (bad) {
      break;
    }

    int cnt_c = MAXN;
    forn(i, AL) {
      if  (!c[i]) continue;
      // c[i] * cnt <= rest[i]
      int cnt = rest[i] / c[i];
      cnt_c = min(cnt_c, cnt);
    }

    if  (cnt_b + cnt_c > cnt_B + cnt_C) {
      cnt_B = cnt_b;
      cnt_C = cnt_c;
    }
  }
    
  forn(i, cnt_B) {
    printf("%s", B.c_str());
  }
  forn(i, cnt_C) {
    printf("%s", C.c_str());
  }

  forn(i, AL) {
    int rest = a[i] - b[i] * cnt_B - c[i] * cnt_C;
    forn(j, rest) {
      putchar('a' + i);
    }
  }

  return 0;
}