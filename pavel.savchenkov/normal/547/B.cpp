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

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  int n;
  scanf("%d", &n);
  vi a(n);
  forn(i, n) scanf("%d", &a[i]);

  vi l(n, -1);
  vi r(n, -1);

  vi st;
  forn(i, n) {
    while  (!st.empty() && a[st.back()] >= a[i]) {
      st.pop_back(); 
    }
    l[i] = st.empty() ? 0 : st.back() + 1;
    st.pb(i);
  }

  st.clear();
  ford(i, n) {
    while (!st.empty() && a[st.back()] >= a[i]) {
      st.pop_back();
    } 
    r[i] = st.empty() ? n - 1 : st.back() - 1;
    st.pb(i);
  }

  vi ans(n + 1, -1);
  forn(i, n) {
    int len = r[i] - l[i] + 1;
//    printf("%d %d\n", l[i], r[i]);
    ans[len] = max(ans[len], a[i]);
  }

  ford(i, n) {
    ans[i] = max(ans[i], ans[i + 1]);
  }

  forn(i, n) {
    printf("%d ", ans[i + 1]);
  }
  puts("");
  return 0;
}