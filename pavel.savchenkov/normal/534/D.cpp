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

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  vector<set<pii>> a(3);
  int n;
  cin >> n;
  forn(i, n) {
    int x;
    scanf("%d", &x);
    a[x % 3].insert(mp(x, i));
  }

  vi res;
  int fr = 0;
  forn(i, n) {
    int r = fr % 3;
    auto it = a[r].lower_bound(mp(fr, n+1));

//    printf("fr = %d\n", fr);

    if  (it == a[r].begin()) {
      puts("Impossible");
      return 0;
    }
    --it;

//    printf("a_i = %d\n", it->fst);
    fr = it->fst + 1;
    res.pb(it->snd);
    a[r].erase(it);
  }

  puts("Possible");
  for (int x : res) printf("%d ", x + 1);
  puts("");
  return 0;
}