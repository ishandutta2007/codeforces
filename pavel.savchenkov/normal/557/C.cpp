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

vii vals;
int cnt[210];
int n;

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  cin >> n;
  vals.resize(n);
  forn(i, n) {
    scanf("%d", &vals[i].fst);  
  }
  forn(i, n) {
    scanf("%d", &vals[i].snd);
  }

  sort(all(vals));

  int suff = 0;
  forn(i, n) {
    suff += vals[i].snd;
  }
  int ans = suff;
  int cnt_eq = 0;
  forn(i, n) {
    ++cnt_eq;
    suff -= vals[i].snd;
    if  (i + 1 == n || vals[i].fst != vals[i + 1].fst) {
      int cur = suff;
      // cnt_eq > rest
      // rest = i + 1 - cnt_eq - del
      // cnt_eq - (i + 1 - cnt_eq - del) > 0
      // cnt_eq - i - 1 + cnt_eq + del > 0
      // 2 cnt_eq - i - 1 > -del
      // - 2 * cnt_eq + i + 1 < del
      int need_del = max(0, i + 1 - 2 * cnt_eq + 1);
      forn(d, 201) {
        int cur_cnt = cnt[d];
        cur += min(cur_cnt, need_del) * d;
        need_del -= min(cur_cnt, need_del);
        if  (!need_del) {
          break;
        }
      }
      ans = min(ans, cur); 
      cnt_eq = 0;
      for (int j = i; j >= 0 && vals[j].fst == vals[i].fst; --j) {
        ++cnt[vals[j].snd];
      }
    }                                               
  }

  cout << ans << endl;


  return 0;
}