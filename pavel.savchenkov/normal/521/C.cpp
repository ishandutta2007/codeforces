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
#define hash kjfdkljkdhgjdkfhgurehg
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
  ((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

int mpow(int a, int p) {
  int res = 1;
  for (; p; p /= 2, a = mul(a, a))
    if  (p & 1)
      res = mul(res, a);
  return res;
}

int fact[MAXN];
int inv_fact[MAXN];
int sum_func[MAXN];
int pow10[MAXN];
int n, k;

int C(int n, int k) {
  return mul(fact[n], mul(inv_fact[k], inv_fact[n - k]));
}

void precalc() {
  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fact[i] = mul(i, fact[i - 1]);
  }               

  forn(i, MAXN) {
    inv_fact[i] = mpow(fact[i], MOD - 2);
  }

  pow10[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    pow10[i] = mul(10, pow10[i - 1]);
  }

  sum_func[0] = mul(C(n - 2, k - 1), pow10[0]);
  for (int i = 1; i < MAXN; ++i) {
    int NN = n - i - 2;

    int cur = 0;
    if  (NN < k - 1) {
      cur = 0;
    } else {
      cur = mul(C(NN, k - 1), pow10[i]);
    }

    sum_func[i] = cur;
    add(sum_func[i], sum_func[i - 1]);
  }
}

char a[MAXN];

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d%d\n", &n, &k);
  gets(a);

  precalc();

  int ans = 0;
  forn(i, n) {
    int coef = a[i] - '0';

    int x = n - i;

    int up_to = x - 2;

//    printf("i = %d, up_to = %d\n", i, up_to);

    if  (up_to >= 0) {
      add(ans, mul(coef, sum_func[up_to]));
    }

    int deg = n - i - 1;

    int places = i;

    if  (deg >= 0 && places >= k) {
//      printf("aux\n");
      add(ans, mul(mul(coef, pow10[deg]), C(places, k)));
    }
  }

  cout << ans << endl;
  return 0;
}