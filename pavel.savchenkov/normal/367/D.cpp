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
const int MAXN = 1e5 + 5;

bool good[1 << 21];
int n, m, d;
int who[MAXN];
int sum[MAXN][21];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);

  memset (who, -1, sizeof who);

  scanf("%d%d%d", &n, &m, &d);

  forn(j, m) {
    int s;
    scanf("%d", &s);
    forn(i, s) {
      int a;
      scanf("%d", &a);
      who[a] = j;
    }
  }

  forn(j, m) {
    sum[0][j] = 0;
  }
  for (int i = 1; i <= n + 1; ++i) {
    forn(j, m) {
      if  (j == who[i]) {
        sum[i][j] = sum[i - 1][j] + 1;
      } else {
        sum[i][j] = sum[i - 1][j];
      }
    }
  }

  memset (good, true, sizeof good);
  forn(i, n + 1) {
    int l = i + 1;
    int r = i + d;

    if  (n + 1 - i <= d) {
      break;
    }

    int have_mask = 0;
    forn(j, m) {
      int Sum = sum[r][j];
      if  (l) {
        Sum -= sum[l - 1][j];
      }
      if  (Sum) {
        have_mask |= 1 << j;  
      }
    }

//    printf("i = %d, have_mask = %d\n", i, have_mask);

    if  (!i) {
      good[~have_mask & ((1 << m) - 1)] = false;
    } else {
      if  ((have_mask >> who[i]) & 1) {
        continue;
      } else {
        good[((~have_mask) | (1 << who[i])) & ((1 << m) - 1)] = false;
      }
    }
  }
/*
  forn(mask, 1 << m) {
    printf("good[%d] = %d\n", mask, good[mask]);
  }
*/
  for (int len = m; len >= 0; --len) {
    forn(mask, 1 << m) {
      if  (!good[mask] && __builtin_popcount(mask) == len) {
        forn(i, m) {
          if  ((mask >> i) & 1) {
            good[mask ^ (1 << i)] = false;  
          }
        } 
      }
    }
  }

  int res = m;
  forn(mask, 1 << m) {
    if  (good[mask]) {
      res = min(res, __builtin_popcount(mask));
    }
  }

  printf("%d\n", res);
  return 0;
}