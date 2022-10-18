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
const int MAXN = 3e5 + 10;
const int INF = 2e9 + 10;

int a[MAXN];
int n, k;

const int MAXK = 5e3 + 10;
int dp[MAXK][MAXK];

int get_sum_diff(int l, int r) {
  return a[r] - a[l];
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  cin >> n >> k;
  forn(i, n) scanf("%d", &a[i]);
  sort(a, a + n);

  vi lens(k); 
  forn(i, n) {
    ++lens[i % k];
  }
  sort(all(lens));
  reverse(all(lens));
  while (lens.back() == 0) lens.pop_back();
  reverse(all(lens));

  assert(lens.back() - lens[0] <= 1);

  /*
  puts("lens:");
  for (int len : lens) {
    printf("%d ", len);
  }
  puts("");
  */

  vi sum_len(sz(lens) + 1, 0);
  forn(i, sz(lens)) {
    sum_len[i + 1] = sum_len[i] + lens[i];
  }
  auto get_sum_len = [&](int l, int r) {
    return sum_len[r + 1] - sum_len[l];                    
  };

  forn(l, sz(lens)) forn(r, sz(lens)) dp[l][r] = INF;
  for (int len = 1; len <= k; ++len) { // not related to lens
    forn(l, k) {
      int r = l + len - 1;
      if  (r >= k) {
        break;
      }
      int ready = n - get_sum_len(l, r);
      // 1
      int L = ready;
      int R = L + lens[l] - 1;
      int cur = get_sum_diff(L, R);
      int to_dp = len == 1 ? 0 : dp[l + 1][r];
      dp[l][r] = min(dp[l][r], cur + to_dp);
      // 2
      R = L + lens[r] - 1;
      cur = get_sum_diff(L, R);
      to_dp = len == 1 ? 0 : dp[l][r - 1];
      dp[l][r] = min(dp[l][r], cur + to_dp);
    }
  }

  cout << dp[0][k - 1] << endl;
  return 0;
}