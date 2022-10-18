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
#include <fstream>
#include <unordered_map>
#include <unordered_set>

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

int n;
int p[MAXN];

void NO() {
  puts("NO");
  exit(0);
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d", &n);
  forn(i, n) {
    scanf("%d", &p[i]);
    --p[i];
  }

  // 1
  forn(i, n) {
    if  (p[i] != i) {
      continue;
    }
    puts("YES");
    forn(j, n) {
      if  (i == j) {
        continue;
      }
      printf("%d %d\n", i + 1, j + 1);
    }
    puts("");
    return 0;
  }

  vvi cycles;
  vi used(n, false);
  forn(i, n) {
    if  (used[i]) {
      continue;
    }
    vi cycle;
    int j = i;
    while (!used[j]) {
      used[j] = true;
      cycle.pb(j);
      j = p[j];
    }
    cycles.pb(cycle);
  }

  vi base;
  for (const auto& cycle : cycles) {
    if  (sz(cycle) & 1) {
      NO();
    }
    if  (sz(cycle) == 2) {
      base = cycle;
    }
  }

  if  (base.empty()) {
    NO();
  }

  puts("YES");
  printf("%d %d\n", base[0] + 1, base[1] + 1);
  for (const auto& cycle : cycles) {
    if  (cycle == base) {
      continue;
    }
    forn(i, sz(cycle)) {
      printf("%d %d\n", base[i % 2] + 1, cycle[i] + 1);
    }
  }
  puts("");

  return 0;
}