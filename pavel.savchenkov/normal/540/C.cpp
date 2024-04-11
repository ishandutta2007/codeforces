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
const int MAXN = 500 + 10;

const int di[4] = { 1, -1, 0, 0 };
const int dj[4] = { 0, 0, 1, -1 };

char a[MAXN][MAXN];
int to_i, to_j;
int from_i, from_j;
int n, m;
bool was[MAXN][MAXN];

bool on(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

bool dfs(int i, int j) {
  was[i][j] = true;

  forn(k, 4) {
    int ni = i + di[k];
    int nj = j + dj[k];

    if  (!on(ni, nj)) {
      continue;
    }

    if  (ni == to_i && nj == to_j) {
      return true;
    }

    if  (was[ni][nj]) {
      continue;
    }

    if  (a[ni][nj] == 'X') {
      continue;
    }

    if  (dfs(ni, nj)) {
      return true;
    }
  }

  return false;
}

bool solve() {
  if  (a[to_i][to_j] == 'X') {
    memset (was, false, sizeof was);
    return dfs(from_i, from_j);  
  }

  forn(k, 4) {
    int ni = to_i + di[k];
    int nj = to_j + dj[k];
    
    if  (on(ni, nj) && a[ni][nj] == '.') {
      a[ni][nj] = 'X';
      memset (was, false, sizeof was);
      if  (dfs(from_i, from_j)) {
        return true;
      }
      a[ni][nj] = '.';
    }
  }

  return false;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d%d\n", &n, &m);
  forn(i, n) {
    gets(a[i]);
  }

  cin >> from_i >> from_j;
  --from_i;
  --from_j;

  cin >> to_i >> to_j;
  --to_i;
  --to_j;

  puts(solve() ? "YES" : "NO");
  return 0;
}