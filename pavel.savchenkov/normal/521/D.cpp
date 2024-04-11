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
#define hash kjfdkljkdhgjdkfhgurehg
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
typedef long double ld;

const double EPS = 1e-9;
const int MAXN = 1e5 + 10;

int type[MAXN];
int who[MAXN];
int b[MAXN];

int id_max_b[MAXN];
ll a[MAXN];

set<pair<ld, int> > S;

set<pii> adds[MAXN];

void solve() {
  int k, n, m;
  cin >> k >> n >> m;
  forn(i, k) {
    scanf("%I64d", &a[i]);
  }

  memset (id_max_b, -1, sizeof id_max_b);
  forn(i, n) {
    scanf("%d%d%d", &type[i], &who[i], &b[i]);
    --who[i];

    if  (type[i] == 3) {
      S.insert(mp(b[i], i));  
    } else if  (type[i] == 2) {
      adds[who[i]].insert(mp(b[i], i));
    } else {
      if  (id_max_b[who[i]] == -1 || b[id_max_b[who[i]]] < b[i]) {
        id_max_b[who[i]] = i;
      }
    }
  }

  forn(i, k) {
    if  (id_max_b[i] != -1) {
      if  (b[id_max_b[i]] > a[i]) {
        adds[i].insert(mp(b[id_max_b[i]] - a[i], id_max_b[i]));
      }
    }
  }

  forn(i, k) {
    if  (!adds[i].empty()) {
      S.insert(mp((ld) (a[i] + adds[i].rbegin()->fst) / a[i], adds[i].rbegin()->snd));
    }
  }

  vi ans;

  forn(it, m) {
    if  (S.empty()) {
      break;
    }

    auto cur = *S.rbegin();
    S.erase(cur);

    int id_op = cur.snd;

    ans.pb(id_op);

    if  (type[id_op] == 3) {
      continue;
    }

    int id = who[id_op];
    a[id] += b[id_op];
    adds[id].erase(*adds[id].rbegin());
    if  (!adds[id].empty()) {
      S.insert(mp((ld) (a[id] + adds[id].rbegin()->fst) / a[id], adds[id].rbegin()->snd));
    }
  }

  sort(all(ans), [&](int i, int j) { return type[i] < type[j]; });

  printf("%d\n", sz(ans));
  for (int x : ans) {
    printf("%d ", x + 1);
  }
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif
   
  solve();

  return 0;
}