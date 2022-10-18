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

int n;
ll m;

void small() {
  int max_f = 0;
  vi p(n);
  forn(i, n) {
    p[i] = i;
  }

  do {
    int f = 0;
    forn(i, n) {
      for (int j = i; j < n; ++j) {
        int mn = n;
        for (int k = i; k <= j; ++k) {
          mn = min(mn, p[k]);
        }
        f += mn;
      }
    }

   max_f = max(max_f, f); 
  } while (next_permutation(all(p)));


  forn(i, n) {
    p[i] = i;
  }

  ll M = m;

  do {
    int f = 0;
    forn(i, n) {
      for (int j = i; j < n; ++j) {
        int mn = n;
        for (int k = i; k <= j; ++k) {
          mn = min(mn, p[k]);
        }
        f += mn;
      }
    }

    if  (f == max_f) {
      /*
      forn(i, n) {
        printf("%d ", p[i] + 1);
      }
      puts("");
      */   
      --m;
    }

    if  (m == 0) {
      puts("ans:");
      forn(i, n) {
        printf("%d ", p[i] + 1);
      }
      puts("");
      m = M;
      return;
    }

  } while (next_permutation(all(p)));
}


bool alive[60];

void solve(int len, ll num) {
  if  (len == 0) {
    return;
  }

  if  (len == 1) {
    forn(j, n) {
      if  (alive[j]) {
        alive[j] = false;
        printf("%d ", j + 1);
        return;
      }
    }
  }

  int st = len - 2;
  ll cur = 1ll << st;

  if  (num <= cur) {
    forn(j, n) {
      if  (alive[j]) {
        alive[j] = false;
        printf("%d ", j + 1);
        solve(len - 1, num);
        return;
      }
    }

    assert(false);
  }

  ll prev = 0;
  forn(k, n) {
//    printf("len = %d, k = %d, cur = %I64d\n, num = %I64d\n", len, k + 1, cur, num);
    if  (num <= cur) {
      int K = 0;
      vi ls;
      forn(j, n) {
        if  (alive[j]) {
          ls.pb(j);
          ++K;
        }
        if  (K == k + 1) {
          for (int x : ls) alive[x] = false;
          printf("%d ", j + 1);
          solve(len - sz(ls), num - prev);
          for (int jj = sz(ls) - 2; jj >= 0; --jj) printf("%d ", ls[jj] + 1); 
          return;
        }
      }
    }

    prev = cur;
    st = max(st - 1, 0);
    cur += 1ll << st;
  }

//  assert(false);
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

//  ll m;
  cin >> n >> m;

  memset (alive, true, sizeof alive);
  solve(n, m);
  puts("");
//  small();  
  return 0;
}