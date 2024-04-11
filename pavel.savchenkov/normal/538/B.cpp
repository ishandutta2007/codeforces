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
const int MAXN = 1e6 + 10;

vi nums;

void gen(int num) {
  if  (num > MAXN) {
    return;
  }

  nums.pb(num);
//  printf("%d\n", num);

  gen(num * 10);
  gen(num * 10 + 1);
}

const int INF = 1e9;

int dp[MAXN];

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  gen(1);

  int n;
  scanf("%d", &n);
  forn(i, MAXN) dp[i] = INF;
  dp[0] = 0;
  forn(i, n) {
    for (int num : nums) {
      int ni = i + num;
      if  (ni < MAXN) {
        dp[ni] = min(dp[ni], dp[i] + 1);
      }
    }
  }

  printf("%d\n", dp[n]);
  while (n) {
    for (int num : nums) {
      if  (n - num >= 0 && dp[n - num] + 1 == dp[n]) {
        n -= num;
        printf("%d ", num);
        break;
      }
    }
  }
  puts("");

  return 0;
}