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

vi w;
vi h;
int sum_w;
int max_h1, max_h2;
int n;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d", &n);
  w.resize(n);
  h.resize(n);
  forn(i, n) {
    scanf("%d%d", &w[i], &h[i]);
  }

  sum_w = 0;
  max_h1 = 0;
  max_h2 = 0;
  forn(i, n) {
    sum_w += w[i];
    if  (h[i] > max_h1) {
      max_h2 = max_h1;
      max_h1 = h[i];
    } else if  (h[i] > max_h2) {
      max_h2 = h[i];
    }
  }

  forn(i, n) {
    int W = sum_w - w[i];
    int H = h[i] == max_h1 ? max_h2 : max_h1;
    printf("%d ", W * H);
  }
  puts("");

  return 0;
}