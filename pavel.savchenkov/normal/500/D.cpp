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
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
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

struct Edge {
  int to, id;
};

vector<Edge> g[MAXN];
double p[MAXN];
int w[MAXN];
int n;

ll C3(int k) {
  ll res = k;
  res *= k - 1;
  res *= k - 2;
  res /= 6;
  return res;
}

ll C2(int k) {
  ll res = k;
  res *= k - 1;
  res /= 2;
  return res;
}

int dfs(int v, int par, int id) {
  int sz = 1;
  for (auto it : g[v]) {
    int to = it.to;
    if  (to != par) {
      sz += dfs(to, v, it.id);
    }
  } 

  if  (id != -1) {
    p[id] = (double(n - sz) * (double) C2(sz) / C3(n)) + (double(sz) * (double) C2(n - sz) / C3(n)); 
  }

  return sz;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d", &n);
  forn(i, n - 1) {
    int a, b, l;
    scanf("%d%d%d", &a, &b, &l);
    --a;
    --b;

    w[i] = l;
    g[a].pb({ b, i });
    g[b].pb({ a, i });
  }

  dfs(0, -1, -1);

  double ans = 0.0;
  forn(i, n - 1) {
    ans += w[i] * p[i];
  }

  int q;
  scanf("%d", &q);
  while (q --> 0) {
    int r, new_w;
    scanf("%d%d", &r, &new_w);
    --r;

    ans -= (w[r] - new_w) * p[r];
    w[r] = new_w;
    printf("%.10f\n", ans * 2.0);
  }

  return 0;
}