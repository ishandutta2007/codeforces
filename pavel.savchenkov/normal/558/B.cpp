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
const int MAXN = 1e5 + 10;
const int MAXA = 1e6 + 10;

int cnt[MAXA];
int left[MAXA];
int right[MAXA];
int a[MAXN];
int n;

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  cin >> n;
  memset (left, -1, sizeof left);
  forn(i, n) {
    scanf("%d", &a[i]);
    ++cnt[a[i]];
    if  (left[a[i]] == -1) {
      left[a[i]] = i;
    }
    right[a[i]] = i;
  }

  int mx = *max_element(cnt, cnt + MAXA);
  int l = 0;
  int r = n - 1;
  forn(i, n) {
    if  (cnt[a[i]] == mx) {
      if  (right[a[i]] - left[a[i]] < r - l) {
        l = left[a[i]];
        r = right[a[i]];
      }
    }
  }

  printf("%d %d\n", l + 1, r + 1);

  return 0;
}