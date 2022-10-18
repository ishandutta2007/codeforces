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
const int MAXN = 2e5 + 10;

int a[MAXN];
ll sum[MAXN];
ld approx[MAXN];
ld real[MAXN];
int n, T;
ld c;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif
  
  cin >> n >> T >> c;
  forn(i, n) {
    scanf("%d", &a[i]);
  }

  sum[0] = 0;
  forn(i, n) {
    sum[i + 1] = sum[i] + a[i];
  }

  forn(i, n) {
    ll s = sum[i + 1] - sum[max(0, i - T + 1)];
    real[i] = (ld) s / T;
  }

  vector<ld> pow_c(T+1);
  pow_c[0] = 1.0;
  for (int i = 1; i <= T; ++i) {
    pow_c[i] = c * pow_c[i - 1];
  }

  ld mean = 0;
  forn(i, n) {
    mean = (mean + (ld) a[i] / ld(T)) / c;
    approx[i] = mean;
  }
  /*
  for (int i = T; i < n; ++i) {
    mean -= (ld) a[i - T] / ld(T) / pow_c[T];
    mean /= c;
    mean += (ld) a[i] / T / c;
    approx[i] = mean;
  }
  */
  int m;
  scanf("%d", &m);
  while (m--) {
    int r;
    scanf("%d", &r);
    --r;

    ld R = real[r];
    ld appr = approx[r];
    ld err = abs(R - appr) / R;
    printf("%.15f %.15f %.15f\n", (double) R, (double) appr, (double) err);
  }


  return 0;
}