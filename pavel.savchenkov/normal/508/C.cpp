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
const int MAXN = 300 + 10;

int m, t, r;
vi w;

int cnt[MAXN * 5];
bool need[MAXN * 5];
bool fire[MAXN * 5];
int sum[MAXN * 5];

void add(int l, int r) {
  --sum[r + 1];
  ++sum[l];
}
 
int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> m >> t >> r;

  if  (r > t) {
    puts("-1");
    return 0;
  }

  w.resize(m);
  forn(i, m) {
    scanf("%d", &w[i]);
    w[i] += 2 * MAXN;
    need[w[i]] = true;
  }


  while (1) {
    bool was = false;

    forn(i, 5 * MAXN) {
      if  (need[i] && cnt[i] < r) {
        int put = 0;
        for (int j = i - 1; put != (r - cnt[i]); --j) {
          if  (!fire[j]) {
            fire[j] = true;
            add(j + 1, j + t);
            ++put;
          }
        }
        was = true;
        break;
      } 
    }

    if  (!was) {
      break;
    }

    int pref = 0;
    forn(i, 5 * MAXN) {
      pref += sum[i];
      cnt[i] += pref;
    }

    memset (sum, 0, sizeof sum);
  }

  int ans = 0;
  forn(i, 5 * MAXN) {
    ans += fire[i];
  }

  printf("%d\n", ans);
  return 0;
}