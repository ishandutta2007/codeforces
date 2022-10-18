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
const ll INF = 1e18;

struct Stack {
  vector<pair<int, ll>> st;
  vll max_dp;

  void push(int val, ll dp) {
    st.pb(mp(val, dp));
    max_dp.pb(dp);
    if  (sz(max_dp) > 1) {
      max_dp.back() = max(max_dp.back(), max_dp[sz(max_dp) - 2]);
    }
  }

  ll get_max_dp() const {
    return max_dp.empty() ? -INF : max_dp.back();
  }

  void pop() {
    st.pop_back();
    max_dp.pop_back();
  }

  int back_val() const {
    return st.back().fst;
  }

  bool empty() const {
    return st.empty();
  }
};

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  int n;
  scanf("%d", &n);
  vi a(n);
  forn(i, n) {
    scanf("%d", &a[i]);
  }

  Stack st_max;
  Stack st_min;
  vll dp(n, 0);
  forn(i, n) {
    if  (i) {
      dp[i] = max(dp[i], dp[i - 1]);
    }
    while (!st_min.empty() && a[i] >= st_min.back_val()) {
      st_min.pop();
    }
    while (!st_max.empty() && a[i] <= st_max.back_val()) {
      st_max.pop();
    }
    dp[i] = max(dp[i], max(st_max.get_max_dp() + a[i], st_min.get_max_dp() - a[i]));
    st_min.push(a[i], (i ? dp[i - 1] : 0) + a[i]);
    st_max.push(a[i], (i ? dp[i - 1] : 0) - a[i]);
  }

  cout << *max_element(all(dp)) << '\n';

  return 0;
}