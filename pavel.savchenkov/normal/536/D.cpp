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
const int MAXN = 2e3 + 10;
const ll INF = 1e18;

struct Point {
  int x, y, cost;

  Point(int x, int y, int cost) : x(x), y(y), cost(cost) {}

  void print() const {
    printf("%d %d %d\n", x, y, cost);
  }
};

vector<Point> points;

ll dp[2][MAXN][MAXN];
int left_x[MAXN][MAXN];
int down_y[MAXN][MAXN];
bool have_point[MAXN][MAXN];
ll sum_cost[MAXN][MAXN];
int min_dp[2][MAXN][MAXN];

ll get_sum(int x1, int x2, int y1, int y2) {
  if  (x1 > x2 || y1 > y2) {
    return 0;
  }
  ll res = sum_cost[x2][y2];
  if  (x1 > 0) {
    res -= sum_cost[x1 - 1][y2];
  }
  if  (y1 > 0) {
    res -= sum_cost[x2][y1 - 1];
  }
  if  (x1 > 0 && y1 > 0) {
    res += sum_cost[x1 - 1][y1 - 1];
  }
  return res;
}

ll solve() {
  for (auto& p : points) {
    ++p.x;
    ++p.y;
  }

/*
  for (auto p : points) {
    p.print();
  }
*/

  memset (have_point, false, sizeof have_point);
  for (auto p : points) {
    have_point[p.x][p.y] = true;
  }  

  int max_x = -1;
  int max_y = -1;
  for (auto p : points) {
    max_x = max(max_x, p.x);
    max_y = max(max_y, p.y);
  }

  ford(x, max_x + 1) ford(y, max_y + 1) {
    left_x[x][y] = 1e9;
    if  (x + 1 <= max_x) {
      left_x[x][y] = min(left_x[x][y], left_x[x + 1][y]);
    }  
    if  (y + 1 <= max_y) {
      left_x[x][y] = min(left_x[x][y], left_x[x][y + 1]);
    }
    if  (have_point[x + 1][y + 1]) {
      left_x[x][y] = x + 1;
    }

    down_y[x][y] = 1e9;
    if  (x + 1 <= max_x) {
      down_y[x][y] = min(down_y[x][y], down_y[x + 1][y]);
    }
    if  (y + 1 <= max_y) {
      down_y[x][y] = min(down_y[x][y], down_y[x][y + 1]);
    }
    if  (have_point[x + 1][y + 1]) {
      down_y[x][y] = y + 1;
    } 
  }

  memset (sum_cost, 0, sizeof sum_cost);
  for (auto p : points) {
    sum_cost[p.x][p.y] += p.cost;
  }
  forn(x, max_x + 2) {
    forn(y, max_y + 2) {
      if  (x > 0) {
        sum_cost[x][y] += sum_cost[x - 1][y];
      }
      if  (y > 0) {
        sum_cost[x][y] += sum_cost[x][y - 1];
      }
      if  (x > 0 && y > 0) {
        sum_cost[x][y] -= sum_cost[x - 1][y - 1];
      }
    }
  }

  memset (min_dp, -1, sizeof min_dp);
  ford(x, max_x + 1) {
    ford(y, max_y + 1) {
      // 0
      int x2 = left_x[x][y];
      if  (x2 >= (int) 1e9) {
        dp[0][x][y] = 0;
      } else {
        int x3 = min_dp[1][x2][y];
        dp[0][x][y] = get_sum(x + 1, x3, y + 1, max_y) + (get_sum(x3 + 1, max_x, y + 1, max_y) - dp[1][x3][y]);
      }

      min_dp[0][x][y] = min_dp[0][x][y + 1];
      if  (min_dp[0][x][y] == -1 || dp[0][x][y] < dp[0][x][min_dp[0][x][y]]) {
        min_dp[0][x][y] = y;
      }

//      printf("dp[0][%d][%d] = %I64d\n", x, y, dp[0][x][y]);

      // 1
      int y2 = down_y[x][y];
      if  (y2 >= (int) 1e9) {
        dp[1][x][y] = 0;
      } else {
        int y3 = min_dp[0][x][y2];
        dp[1][x][y] = get_sum(x + 1, max_x, y + 1, y3) + (get_sum(x + 1, max_x, y3 + 1, max_y) - dp[0][x][y3]);
      }
    
      min_dp[1][x][y] = min_dp[1][x + 1][y];
      if  (min_dp[1][x][y] == -1 || dp[1][x][y] < dp[1][min_dp[1][x][y]][y]) {
        min_dp[1][x][y] = x;
      }

//      printf("dp[1][%d][%d] = %I64d\n", x, y, dp[1][x][y]);
    }
  }

  return dp[0][0][0];
}

vii g[MAXN];
int n, m;
int p[MAXN];

vll calc_dists(int s) {
  vll d(n, INF);
  d[s] = 0;
  set<pair<ll, int>> S;
  S.insert(mp(0, s));
  while (!S.empty()) {
    int v = S.begin()->snd;
    S.erase(S.begin());
    for (auto e : g[v]) {
      int to = e.fst;
      int cost = e.snd;
      if  (d[v] + cost < d[to]) {
        S.erase(mp(d[to], to));
        d[to] = d[v] + cost;
        S.insert(mp(d[to], to));
      }
    }
  }
  return d;
}

int s, t;

bool read() {
  if  (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  scanf("%d%d", &s, &t);
  --s;
  --t;
  forn(i, n) {
    scanf("%d", &p[i]);
  }
  forn(i, n) {
    g[i].clear();
  }
  points.clear();
  forn(i, m) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a;
    --b;
    g[a].pb(mp(b, c));
    g[b].pb(mp(a, c));
  }
  return true;
}

void go_solve() {
  auto d0 = calc_dists(s); // x
  auto d1 = calc_dists(t); // y

  vll all_x;
  for (auto x : d0) all_x.pb(x);
  sort(all(all_x));
  all_x.resize(unique(all(all_x)) - all_x.begin());

  vll all_y;
  for (auto y : d1) all_y.pb(y);
  sort(all(all_y));
  all_y.resize(unique(all(all_y)) - all_y.begin());

  forn(v, n) {
    int x = lower_bound(all(all_x), d0[v]) - all_x.begin();
    int y = lower_bound(all(all_y), d1[v]) - all_y.begin();
    points.pb(Point(x, y, p[v]));
  }

  ll val = solve();
  ll s = 0;
  forn(v, n) s += p[v];
  ll val2 = s - val;
  if  (val > val2) {
    puts("Break a heart");
  } else if  (val == val2) {
    puts("Flowers");
  } else {
    puts("Cry");
  }
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif

  while (read()) {
    go_solve();
//    break;
  }

  return 0;
}