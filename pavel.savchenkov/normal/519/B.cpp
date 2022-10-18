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
const int MAXN = 1e5 + 10;

vi C;
int n;
int a[MAXN];
int b[MAXN];
int c[MAXN];

int cnt_a[MAXN];
int cnt_b[MAXN];
int cnt_c[MAXN];

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n;
  forn(i, n) {
    scanf("%d", &a[i]);
    C.pb(a[i]);
  }

  sort(all(C));
  C.resize(unique(all(C)) - C.begin());

  forn(i, n) {
    a[i] = lower_bound(all(C), a[i]) - C.begin();
    ++cnt_a[a[i]];
  }

  forn(i, n - 1) {
    scanf("%d", &b[i]);
    b[i] = lower_bound(all(C), b[i]) - C.begin();
    ++cnt_b[b[i]];
  }

  forn(i, n - 2) {
    scanf("%d", &c[i]);
    c[i] = lower_bound(all(C), c[i]) - C.begin();
    ++cnt_c[c[i]];
  }

  forn(i, n) {
    if  (cnt_a[a[i]] > cnt_b[a[i]]) {
      printf("%d\n", C[a[i]]);
      break;
    }
  }

  forn(i, n - 1) {
    if  (cnt_b[b[i]] > cnt_c[b[i]]) {
      printf("%d\n", C[b[i]]);
      break;
    }
  }

  return 0;
}