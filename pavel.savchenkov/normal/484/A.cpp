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
inline T sqr( T x ) {
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

int hb(ll x) {
  for (int b = 63; b >= 0; --b) {
    if  ((x >> b) & 1) {
      return b;
    }
  }
  return -1;
}

ll solve(ll l, ll r) {
  if  (!l && !r) {
    return 0;
  }

  if  (hb(l) < hb(r)) {
    bool good = true;
    ll R = r;
    while (R) { if  (R % 2 == 0) good = false; R /= 2; }
    if  (good) {
      return (1ll << (hb(r) + 1)) - 1ll;
    }
    return (1ll << hb(r)) - 1ll;
  }

  return solve(l ^ (1ll << hb(r)), r ^ (1ll << hb(r))) | (1ll << hb(r));
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

  int T;
  scanf("%d", &T);
  while (T --> 0) {
    ll l, r;
    scanf("%I64d%I64d\n", &l, &r);
    printf("%I64d\n", solve(l, r));
  }

	return 0;
}