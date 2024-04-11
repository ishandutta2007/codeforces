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
#define all(C) begin(C), end(C)

#define debug(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr(T x) {
  return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;
const int MAXN = 1e3 + 10;

int n, m, k;
bool a[MAXN][MAXN];

bool check(int i, int j) {
  return 0 <= i && i + 1 < n && 0 <= j && j + 1 < m && a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1];
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n >> m >> k;
  int ans = 0;
  forn(ii, k) {
    int i, j;
    scanf("%d%d", &i, &j);
    --i;
    --j;

    a[i][j] = true;

    bool was = false;
    for (int I = i - 3; I <= i + 3; ++I) {
      for (int J = j - 3; J <= j + 3; ++J) {
        was |= check(I, J);
      }
    }

    if  (was) {
      ans = ii + 1;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}