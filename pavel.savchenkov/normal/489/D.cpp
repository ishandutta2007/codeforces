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
const int MAXN = 3000 + 5;

bool g[MAXN][MAXN];

int n, m;
int cnt[MAXN];

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  forn(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;

    g[a][b] = 1;
  }

  ll res = 0;

  forn(a, n) {
    memset (cnt, 0, sizeof cnt);

    forn(b, n) {
      if  (g[a][b]) {
        forn(c, n) {
          if  (g[b][c]) {
            ++cnt[c];
          } 
        } 
      }
    }

    forn(c, n) {
      if  (c != a) res += cnt[c] * 1ll * (cnt[c] - 1) / 2ll;
    }
  }

  cout << res << endl;
  return 0;
}