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

struct Solver {
  int m, k;
  vi a;
  vi t;
  vi r;

  void solve() {
    scanf("%d%d", &m, &k);
    --m;

    a.resize(k);
    forn(i, k) {
      scanf("%d", &a[i]);
    }

    t.resize(m);
    r.resize(m);
    forn(i, m) {
      scanf("%d%d", &t[i], &r[i]);
    }

    vector<char> was_after_border(k, false);
    int cnt_free = 0;
    int cnt_free_to_border = -1;
    forn(i, m) {
      if  (r[i] == 1 && cnt_free_to_border == -1) {
        cnt_free_to_border = cnt_free;
      }
        
      if  (t[i]) {
        --a[t[i] - 1];
        if  (cnt_free_to_border != -1) {
          was_after_border[t[i] - 1] = true;
        }
      } else {
        ++cnt_free;
      }
    }

    int min_id = -1;
    forn(i, k) {
      if  (!was_after_border[i] && (min_id == -1 || a[i] < a[min_id])) {
        min_id = i;
      }
    }

    string ans;
    forn(i, k) {
      bool can = false;

      // 1
      if  (cnt_free_to_border >= a[i] && !was_after_border[i]) {
        can = true;
      }

      // 2
      if  (cnt_free >= a[i] + a[min_id]) {
        can = true;
      }

      // 3
      if  (cnt_free_to_border == -1) {
        can = cnt_free >= a[i];  
      }

      ans += can ? 'Y' : 'N';
    }

    printf("%s\n", ans.c_str());
  }
};

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  int T;
  scanf("%d", &T);
  while (T --> 0) {
    Solver solver;
    solver.solve();
  }
  return 0;
}