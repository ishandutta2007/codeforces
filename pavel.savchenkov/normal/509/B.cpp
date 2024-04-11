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

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  int n, k;
  scanf("%d%d", &n, &k);
  vi a(n);
  forn(i, n) {
    scanf("%d", &a[i]);
  }

  vvi ans(n);
  int j = 0;
  while (1) {
    bool was = false;
    forn(i, n) {
      if  (a[i]) {
        --a[i];
        ans[i].pb(j);
        was = true;
      }
    }

    if  (!was) {
      break;
    }

    ++j;
    if  (j == k) {
      j = 0;
    }
  }

  forn(i, n) forn(j, n) {
    vi cnt(150, 0);
    for (int z : ans[i]) {
      ++cnt[z];
    }
    for (int z : ans[j]) {
      --cnt[z];
    }

    forn(c, 150) {
      if  (abs(cnt[c]) > 1) {
        puts("NO");
        return 0;
      }
    }
  }

  puts("YES");
  forn(i, n) {
    forn(z, sz(ans[i])) {
      printf("%d ", ans[i][z] + 1);
    }
    puts("");
  }


  return 0;
}