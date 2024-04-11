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
const int MAXN = 100 + 10;
const int INF = 1e9;

int arr[MAXN];
int dp[MAXN][MAXN];
int N, T;

struct Matr {
  vvi a;
  int n;

  Matr(int n = 0) : n(n) {
    a.assign(n, vi(n, 0));
  } 

  void init() {
    forn(i, N) forn(j, N) {
      a[arr[i]][arr[j]] = max(a[arr[i]][arr[j]], dp[i][j]);
    }  
  }

  Matr& operator *= (const Matr& m) {
    static vvi na(MAXN, vi(MAXN, 0));
    forn(i, n) forn(j, n) {
      na[i][j] = a[i][j];
      if  (j > 0 && na[i][j - 1] > na[i][j]) {
        na[i][j] = na[i][j - 1];
      }
    }

    static vvi nb(MAXN, vi(MAXN, 0));
    forn(j, n) ford(i, n) {
      nb[i][j] = m.a[i][j];
      if  (i + 1 < n && nb[i + 1][j] > nb[i][j]) {
        nb[i][j] = nb[i + 1][j];
      } 
    }

    vvi c(n, vi(n, -INF));
    forn(i, n) forn(j, n) {
      for (int k = i; k <= j; ++k) {
        c[i][j] = max(c[i][j], na[i][k] + nb[k][j]);
      } 
    }

    a.swap(c);
    return *this;
  }

  Matr operator * (const Matr& m) const {
    return Matr(*this) *= m;
  }

  void print() const {
    forn(i, n) {
      forn(j, n) printf("%d ", a[i][j]);
      puts("");
    }
  }
};

bool read() {
  if  (scanf("%d%d", &N, &T) < 2) {
    return false;
  }
  forn(i, N) {
    scanf("%d", &arr[i]);
  }
  return true;
}

Matr mpow(Matr m, int p) {
  --p;
  Matr res = m;
//  forn(i, p) res *= m;
//  return res;
  for (; p > 0; p /= 2, m *= m) {
    if  (p & 1) {
      res *= m;
    }
  }
  return res;
}

void solve() {
  vi c;
  forn(i, N) c.pb(arr[i]);
  sort(all(c));
  c.resize(unique(all(c)) - c.begin());

  forn(i, N) {
    arr[i] = lower_bound(all(c), arr[i]) - c.begin();
  }

  memset (dp, 0, sizeof dp);

  for (int len = 1; len <= N; ++len) {
    forn(l, N) {
      int r = l + len - 1;
      if  (r >= N) {
        break;
      }
      if  (arr[l] > arr[r]) {
        continue;
      }
      dp[l][r] = 2 - (l == r);
      for (int m = l + 1; m < r; ++m) {
        if  (arr[l] <= arr[m] && arr[m] <= arr[r]) {
          dp[l][r] = max(dp[l][r], dp[l][m] + dp[m][r] - 1);
        }
      }
    }
  }

  Matr m(sz(c));
  m.init();

//  m.print();
//  (mpow(m, 2)).print();

  auto rm = mpow(m, T);

  int ans = 1;
  forn(i, sz(c)) forn(j, sz(c)) ans = max(ans, rm.a[i][j]);

  cout << ans << '\n';
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    solve();
  }

  return 0;
}