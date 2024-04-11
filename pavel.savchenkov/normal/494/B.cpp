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
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
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
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

void add(int& x, int y) {
  if  ((x += y) >= MOD)
    x -= MOD;
}

int dp[MAXN];
int sum_dp[MAXN];
int p[2 * MAXN];
bool can[MAXN];

int get_sum(int l, int r) {
  if  (l > r)
    return 0;

  int res = sum_dp[r];
  if  (l > 0) {
    add(res, - sum_dp[l - 1] + MOD);  
  }
  return res;
}

string s;
string t;
string ts;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif

  getline(cin, s);
  getline(cin, t);
  ts = t + '#' + s;

  p[0] = 0;
  for (int i = 1; i < sz(ts); ++i) {
    int j = p[i - 1];
    while (j && ts[i] != ts[j]) j = p[j - 1];
    if  (ts[i] == ts[j]) {
      ++j;
    }
    p[i] = j;

    if  (i - 1 - sz(t) >= 0) {
      can[i - 1 - sz(t)] = p[i] == sz(t);
    }
  }

  dp[0] = can[0];
  sum_dp[0] = dp[0];
  int last_start = can[0] ? 0 : MAXN;
  for (int i = 1; i < sz(s); ++i) {
    if  (can[i]) {
      last_start = i - sz(t) + 1;
    }

    if  (last_start <= i) {
      if  (last_start >= 1) {
        dp[i] = sum_dp[last_start - 1];
      }
      add(dp[i], last_start + 1);
      add(dp[i], dp[i - 1]);
    }

    sum_dp[i] = sum_dp[i - 1];
    add(sum_dp[i], dp[i]);
  }

  printf("%d\n", dp[sz(s) - 1]);
  return 0;
}