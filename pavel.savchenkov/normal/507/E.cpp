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
const int MAXN = 1e5 + 10;
const int INF = 1e9;

vii g[MAXN];
int dist[MAXN];
int max_x[MAXN];
int prev[MAXN];
bool on[MAXN];
int n, m;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n >> m;
  forn(i, m) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    --x;
    --y;

    g[x].pb(mp(y, z));
    g[y].pb(mp(x, z));
  }

  forn(i, n) {
    dist[i] = INF;
    max_x[i] = -1;
    prev[i] = -1;
  }

  dist[0] = 0;    
  max_x[0] = 0;
  vi lay;
  lay.pb(0);

  while (1) {
    vi nlay;
    for (int v : lay) {
      for (auto it : g[v]) {
        int to, z;
        tie(to, z) = it;
        if  (dist[v] + 1 < dist[to]) {
          dist[to] = dist[v] + 1;
          max_x[to] = max_x[v] + z;
          prev[to] = v;
          nlay.pb(to);
        } else if  (dist[v] + 1 == dist[to] && max_x[v] + z > max_x[to]) {
          max_x[to] = max_x[v] + z;
          prev[to] = v;
          nlay.pb(to);
        }
      }
    } 

    sort(all(nlay));
    nlay.resize(unique(all(nlay)) - nlay.begin());

    if  (nlay.empty()) break;

    lay = nlay;
  }

  memset (on, false, sizeof on);
  assert(prev[n - 1] != -1);
  int v = n - 1;
  while (v) {
    on[v] = true;
    v = prev[v];
  }
  on[0] = true;

  int cnt_on = 0;
  forn(v, n) cnt_on += on[v];
  assert(cnt_on == dist[n - 1] + 1);

/*
  puts("dist:");
  forn(v, n) printf("%d ", dist[v]);
  puts("");
  puts("prev:");
  forn(v, n) printf("%d ", prev[v]);
  puts("");
  puts("on:");
  forn(v, n) printf("%d ", on[v]);
  puts("");
*/
  vector<pair<int, pii>> res;
  forn(v, n) for (auto it : g[v]) {
    int to, z;
    tie(to, z) = it;
    if  (on[v] && on[to]) {
      if  (z == 0 && prev[to] == v) {
        res.pb(mp(v + 1, mp(to + 1, 1)));
      }
    } else {
      if  (z == 1 && v < to) {
        res.pb(mp(v + 1, mp(to + 1, 0)));
      }
    }
  }

  printf("%d\n", sz(res));
  forn(i, sz(res)) printf("%d %d %d\n", res[i].fst, res[i].snd.fst, res[i].snd.snd);
  return 0;                                            
}