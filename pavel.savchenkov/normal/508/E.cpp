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
const int MAXN = 2 * 600 + 10;

short dp[MAXN][MAXN];
int l[MAXN];
int r[MAXN];
int n;

bool calc(int L, int R) {
//  printf("in [%d, %d]\n", L, R);
  
  if  (L > R) {
    return true;
  }

  if  (dp[L][R] != -1) {
    return dp[L][R];
  }

  short& ans = dp[L][R];
  ans = 0;

  for (int dist = l[L]; dist <= r[L]; ++dist) {
    if  (dist % 2 == 0) {
      continue;
    }

    int mid = L + (dist - 1) / 2;

    if  (mid > R) {
      break;
    }

    if  (calc(L + 1, mid) && calc(mid + 1, R)) {
      return (ans = 1);
    }
  }

  return ans;
}
 
vector<char> res;

void restore(int L, int R) {
//  printf("restore [%d, %d]\n", L, R);
  if  (L > R) {
    return;
  }

  for (int dist = l[L]; dist <= r[L]; ++dist) {
    if  (dist % 2 == 0) {
      continue;
    }

    int mid = L + (dist - 1) / 2;

    if  (mid > R) {
      break;
    }

    if  (calc(L + 1, mid) && calc(mid + 1, R)) {
      res.pb('(');
      restore(L + 1, mid);
      res.pb(')');
      restore(mid + 1, R);
      return;
    } 
  }

  assert(false);
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  memset (dp, -1, sizeof dp);

  cin >> n;
  forn(i, n) {
    scanf("%d%d", &l[i], &r[i]);
  }

  calc(0, n - 1);

  if  (!dp[0][n - 1]) {
    puts("IMPOSSIBLE");
    return 0;
  }

//  forn(L, n) for (int R = L; R < n; ++R) printf("calc(%d, %d) = %d\n", L, R, calc(L, R));

  restore(0, n - 1);

  if  (sz(res) != 2 * n) {
    while (1) {}
  }

  forn(i, 2 * n) putchar(res[i]);

  return 0;
}