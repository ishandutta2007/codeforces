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

const ld EPS = 1e-9;
const int MAXN = 1e6 + 10;

int next_start[MAXN];
int blocks[MAXN];
ll in_last[MAXN];
int n, q;
int a[MAXN];
ll suma[MAXN];

void precalc() {
  suma[0] = 0;
  forn(i, n) suma[i + 1] = suma[i] + a[i]; 
}

ll sum(int l, int r) {
  return suma[r + 1] - suma[l];
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n >> q;
  forn(i, n) {
    scanf("%d", &a[i]);
  }

  precalc();

  forn(it, q) {
    ll b;
    cin >> b;

    blocks[n] = 0;
    in_last[n] = 0;
    next_start[n] = -1;

    next_start[n - 1] = n;
    blocks[n - 1] = 1;
    in_last[n - 1] = a[n - 1];

    ford(i, n - 1) {
      next_start[i] = next_start[i + 1];
      while (sum(i, next_start[i] - 1) > b) {
        --next_start[i];
      } 

      assert(next_start[i] > i);
      blocks[i] = blocks[next_start[i]] + 1;
      in_last[i] = blocks[i] == 1 ? sum(i, n - 1) : in_last[next_start[i]];
    }
    
    int ans = (int) 1e9;
    ll beg = 0;
    forn(i, n) {
      if  (beg > b) {
        break;
      }

      int cur = blocks[i];

      if  (in_last[i] + beg > b) {
        ++cur;
      }

      ans = min(ans, cur);
      beg += a[i];
    }

    printf("%d\n", ans);
  }

  return 0;
}