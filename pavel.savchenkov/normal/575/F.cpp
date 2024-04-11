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
const int MAXN = 5e3 + 10;
const ll INF = 1e18;

ll dp[2][2*MAXN];
vi points;
int n, x;
vii segs;

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  cin >> n >> x;
  points.pb(x);
  forn(i, n) {
    int l, r;
    scanf("%d%d", &l, &r);
    segs.pb(mp(l, r));
    points.pb(l);
    points.pb(r);
  }

  sort(all(points));
  points.resize(unique(all(points)) - points.begin());

  int c = 0;             
  forn(j, sz(points)) {
    dp[c][j] = 0;
  }
  c ^= 1;

  ford(i, n) {
    // cur --> c
    int l, r;
    tie(l, r) = segs[i];

    int pos = lower_bound(all(points), l) - points.begin();
    for (int j = pos; j < sz(points) && points[j] <= r; ++j) {
      dp[c][j] = dp[c ^ 1][j];
    }

    ll mn = INF;
    for (int j = pos; j >= 0; --j) {
      mn = min(mn, dp[c ^ 1][j]);
      dp[c][j] = (l - points[j]) + mn;
    }

    pos = lower_bound(all(points), r) - points.begin();
    mn = INF;
    for (int j = pos; j < sz(points); ++j) {
      mn = min(mn, dp[c ^ 1][j]);
      dp[c][j] = (points[j] - r) + mn;
    }

    c ^= 1;
  }

  
  cout << dp[c ^ 1][lower_bound(all(points), x) - points.begin()] << endl;

  return 0;
}