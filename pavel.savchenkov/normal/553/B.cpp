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
const int MAXN = 50 + 10;
const ull INF = (ull) 1e18 + 10;

ull cnt[MAXN];
int n;
ull k;

ull add(ull a, ull b) {
  if  (a >= INF || b >= INF || a + b >= INF) {
    return INF;
  }
  return a + b;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  cin >> n >> k;

  cnt[0] = 1;
  cnt[1] = 1;
  for (int i = 2; i <= n; ++i) {
    cnt[i] = cnt[i - 1];
    cnt[i] = add(cnt[i - 2], cnt[i]);
  }

  vi ans;
  int i = 0;
  while (i < n) {
    ull cur = cnt[n - i - 1];
    if  (cur < k) {
      k -= cur;
      ans.pb(i + 1);
      ans.pb(i);
      i += 2;
    } else {
      ans.pb(i);
      ++i;
    }
  }

  for (int x : ans) printf("%d ", x + 1);
  puts("");

  return 0;
}