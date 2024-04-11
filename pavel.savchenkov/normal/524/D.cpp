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

const double EPS = 1e-9;
const int MAXN = 10 * (24 * 60 * 60);

#define end end___

int n, M, T;
vi start[MAXN];
vi end[MAXN];

int cnt_color[MAXN];
int colors;
int mx = 0;

void del(int c) {
  --cnt_color[c];
  if  (cnt_color[c] == 0) {
    --colors;
  }
}

void put(int c) {
  if  (cnt_color[c] == 0) {
    ++colors;
    mx = max(mx, colors);
  }
  ++cnt_color[c];
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n >> M >> T;

  forn(i, n) {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);

    int S = s + m * 60 + h * 60 * 60;
    start[S].pb(i);
    end[S + T - 1].pb(i);
  }

  int c = 0;
  colors = 0;
  vi ans;
  for (int i = 0; i < 24 * 60 * 60; ++i) {
    for (int id : start[i]) {
      assert(sz(ans) == id);
      if  (colors == M) {
        int last = ans.back();
        ans.pb(last);
        put(last);
      } else {
        ans.pb(c);
        put(c);
        ++c;
      }
    }

    for (int id : end[i]) {
      del(ans[id]);
    }
  }

  if  (mx != M) {
    puts("No solution");
    return 0;
  }

  printf("%d\n", c);
  for (int x : ans) {
    printf("%d\n", x + 1);
  }

  return 0;
}