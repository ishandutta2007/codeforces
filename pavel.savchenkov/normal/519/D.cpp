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
const int A = 26;

vi T[A];
vll sums[A];

void turn_on(int c, ll sum) {
  int pos = lower_bound(all(sums[c]), sum) - sums[c].begin();
  assert(pos < sz(sums[c]) && sums[c][pos] == sum);
  ++T[c][pos];
}

int get_cnt(int c, ll sum) {
  int pos = lower_bound(all(sums[c]), sum) - sums[c].begin();
  if  (pos < sz(sums[c]) && sums[c][pos] == sum) {
    return T[c][pos];                               
  } else {
    return 0;
  }
}

const int MAXN = 1e5 + 10;

int x[A];
ll pref[MAXN];
char s[MAXN];
int n;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  forn(c, A) {
    cin >> x[c];
  }
  scanf("\n");

  gets(s);
  n = (int) strlen(s);

  ll sum = 0;
  forn(i, n) {
    int c = s[i] - 'a';

    sum += x[c];

    sums[c].pb(sum);
  }

  forn(c, A) {
    sort(all(sums[c]));
    sums[c].resize(unique(all(sums[c])) - sums[c].begin());
    T[c].assign(sz(sums[c]), 0);
  }
/*
  forn(c, A) {
    if  (!sums[c].empty()) {
      for (auto s : sums[c]) {
        cout << s << " ";
      }
      puts("");
    }
  }
*/
  ll ans = 0;
  sum = 0;
  forn(i, n) {
    int c = s[i] - 'a';

    int cur = get_cnt(c, sum);

    ans += cur;

    sum += x[c];

    turn_on(c, sum);
  }

  cout << ans << endl;

  return 0;
}