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
const int MAXN = 1e5 + 10;
const int K = 200;

struct Query {
  char type;
  int x, y;
  char c;

  Query() {
    c = 0;
  }

  void read() {
    type = getchar();
    scanf("%d %d ", &x, &y);
    --x;
    --y;
    if  (type == 'C') {
      c = getchar();
    }
    scanf("\n");
  }
};

vector<Query> qs;
int n, m, q;

char s[MAXN][11];
pii dp[MAXN][11];
bool is_free[MAXN];
bool ready[MAXN][11];

pii calc_dp(int i, int j) {
  if  (!is_free[i]) {
    return mp(-2, -2);
  }

  if  (ready[i][j]) {
    return dp[i][j];
  }
  ready[i][j] = true;

  if  (s[i][j] == '<' && !j) {
    return dp[i][j] = mp(i, -1);
  }

  if  (s[i][j] == '>' && j == m - 1) {
    return dp[i][j] = mp(i, m);
  }

  if  (s[i][j] == '<' && j > 0 && s[i][j - 1] == '>') {
    return dp[i][j] = mp(-2, -2);
  }

  if  (s[i][j] == '>' && j < m - 1 && s[i][j + 1] == '<') {
    return dp[i][j] = mp(-2, -2);
  }

  if  (s[i][j] == '^') {
    if  (i && is_free[i - 1]) {
      return dp[i][j] = calc_dp(i - 1, j);
    }
    return dp[i][j] = mp(i, j);
  }

  if  (s[i][j] == '<') {
    return dp[i][j] = calc_dp(i, j - 1);
  }

  if  (s[i][j] == '>') {
    return dp[i][j] = calc_dp(i, j + 1);
  }

  assert(0);
}

pii go(int i, int j) {
  pii ans = mp(-1, -1);

  while (1) {
    if  (!is_free[i]) {
      if  (s[i][j] == '^') {
        if  (!i) {
          ans = mp(0, j + 1);
          break;  
        }
        --i;
        continue;
      }

      if  (s[i][j] == '>') {
        if  (j == m - 1) {
          ans = mp(i + 1, m + 1);
          break;
        }
        if  (s[i][j + 1] == '<') {
          break;
        }
        ++j;
        continue;
      }

      if  (s[i][j] == '<') {
        if  (j == 0) {
          ans = mp(i + 1, 0);
          break;
        }
        if  (s[i][j - 1] == '>') {
          break;
        }
        --j;
        continue;
      }

      assert(0);
    } else {
      if  (mp(i, j) == dp[i][j]) {
        assert(s[i][j] == '^' && (i == 0 || !is_free[i - 1]));
        if  (!i) {
          ans = mp(0, j + 1);
          break;
        }
        --i;
        continue;
      }

      tie(i, j) = dp[i][j];

      if  (!(0 <= i && i < n && 0 <= j && j < m)) {
        ans = mp(i + 1, j + 1);
        break;
      }
    }
  }

  return ans;
}

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  cin >> n >> m >> q;
  scanf("\n");

  forn(i, n) {
    gets(s[i]);
  }

  scanf("\n");

  int cntC = 0;
  while (q --> 0) {
    Query cur;
    cur.read();

    if  (cur.type == 'C') {
      ++cntC;
    }

    qs.pb(cur);

    if  (cntC >= K || !q) {
//      forn(i, sz(qs)) {
//        printf("%c %d %d %c\n", qs[i].type, qs[i].x, qs[i].y, qs[i].c);
//      }

      memset (is_free, true, sizeof is_free);

      forn(i, sz(qs)) {
        if  (qs[i].type == 'C') {
          is_free[qs[i].x] = false;
        }
      } 

      memset (ready, false, sizeof ready);

      forn(i, n) {
        forn(j, m) {
          calc_dp(i, j);
        }
      }

      forn(k, sz(qs)) {
        if  (qs[k].type == 'C') {
          s[qs[k].x][qs[k].y] = qs[k].c;  
        } else {
          int i = qs[k].x;
          int j = qs[k].y;

          auto ans = go(i, j);

          printf("%d %d\n", ans.f, ans.s); 
        }
      }
    
      qs.clear();
      cntC = 0;
    } 
  }

  return 0;
}