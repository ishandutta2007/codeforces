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
#include <unordered_map>

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
const int INF = 1e9;

bool pow2(int x) {
  return x && ((x & (x - 1)) == 0);
}

int make(int a, int na) {
  int done = 0;
  while (a > 0 && (a > na || na % a != 0 || !pow2(na / a))) {
    ++done;
    a /= 2;
  }
  if  (!a) {
    return INF;
  }
  while (a < na) {
    a *= 2;
    ++done;
  }
  return (a == na) ? done : INF;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  int n;
  cin >> n;
  vii vals;

  forn(i, n) {
    int a;
    scanf("%d", &a);

    if  (i == 0) {
      vals.pb(mp(a, 0));
      forn(cnt0, 100500) {
        int na = a;
        int done = 0;
        forn(it, cnt0) {
          na /= 2;
          ++done;
          vals.pb(mp(na, done));
        }          
        if  (!na) {
          break;
        }
        forn(it, 100500) {
          na *= 2;
          ++done;
          vals.pb(mp(na, done));
          if  (na >= (int) 2e5) {
            break;
          }
        }
      }
      sort(all(vals));
      vii nvals;
      forn(i, sz(vals)) {
        if  (i == 0 || vals[i].fst != vals[i - 1].fst) {
          nvals.pb(vals[i]);
        }
      }
      vals.swap(nvals);
    } else {
      forn(i, sz(vals)) {
        int cur_steps = make(a, vals[i].fst);
        if  (cur_steps >= INF) {
          vals[i].snd = INF;
        }
        if  (vals[i].snd == INF) {
          continue;
        }
        vals[i].snd += cur_steps;
      }
    }
  }

  int mn = INF;
  forn(i, sz(vals)) {
    mn = min(vals[i].snd, mn);
  }
  cout << mn << endl;


  return 0;
}