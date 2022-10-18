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
const int MAXN = 2e5 + 10;

vi cnt;
int a[MAXN];
int b[MAXN];
int n, m;
int p;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n >> m >> p;

  vi coord;
  forn(i, n) {
    scanf("%d", &a[i]);
    coord.pb(a[i]);
  }

  forn(i, m) {
    scanf("%d", &b[i]);
    coord.pb(b[i]);
  }

  sort(all(coord));
  coord.resize(unique(all(coord)) - coord.begin());

  forn(i, n) a[i] = lower_bound(all(coord), a[i]) - coord.begin();
  forn(i, m) b[i] = lower_bound(all(coord), b[i]) - coord.begin();

  
  cnt.assign(sz(coord), 0);
  forn(i, m) ++cnt[b[i]];
  int cnt0 = 0;
  forn(i, sz(cnt)) cnt0 += cnt[i] == 0;
   
  vi ans;
  forn(q, p) {
    if  (q + (m - 1) * 1ll * p >= ll(n)) {
      continue;
    }

    for (int i = q; i <= q + (m - 1) * p; i += p) {
      cnt0 -= cnt[a[i]] == 0;
      --cnt[a[i]];
      cnt0 += cnt[a[i]] == 0;
    }

    int l = q;
    int r = l + (m - 1) * p; 
    
    while (r < n) {
      if  (cnt0 == sz(coord)) {
        ans.pb(l + 1);
      }

      if  (r + p >= n) break;

      // delete a[l]
      cnt0 -= cnt[a[l]] == 0;
      ++cnt[a[l]];
      cnt0 += cnt[a[l]] == 0;

      // add a[r + p]
      cnt0 -= cnt[a[r + p]] == 0;
      --cnt[a[r + p]];
      cnt0 += cnt[a[r + p]] == 0;

      l += p;
      r += p;
    }

    for (int i = l; i <= r; i += p) {
      cnt0 -= cnt[a[i]] == 0;
      ++cnt[a[i]];
      cnt0 += cnt[a[i]] == 0;
    }
  }

  sort(all(ans));
  printf("%d\n", sz(ans));
  for (int x : ans) printf("%d ", x);
  return 0;
}