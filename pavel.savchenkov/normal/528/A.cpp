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

const double EPS = 1e-9;

struct Cutter {
  int H;
  set<int> h;
  multiset<int> diffs;

  Cutter(int H = 0) : H(H) {
    h.insert(H);
    h.insert(0);
    diffs.insert(H);
  }

  int get_max() {
    return *diffs.rbegin();
  }

  void cut(int y) {
    auto it = h.upper_bound(y);
    auto prev = it;
    --prev;

    diffs.erase(diffs.find(*it - *prev));
    diffs.insert(*it - y);
    diffs.insert(y - *prev);
    h.insert(y);
  }
};

Cutter c1, c2;
int w, h, n;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> w >> h >> n;
  scanf("\n");

  Cutter c1(w);
  Cutter c2(h);

  forn(i, n) {
    char type = getchar();
    int x;
    scanf("%d\n", &x);

    if  (type == 'H') {
      c2.cut(x);
    } else {
      c1.cut(x);
    }

    ll ans = c1.get_max() * 1ll * c2.get_max();
    printf("%I64d\n", ans);
  }

  return 0;
}