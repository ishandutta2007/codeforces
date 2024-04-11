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
#include <complex>
#include <bitset>

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

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

const ld EPS = 1e-9;
const int MAXP = 1e6 + 10;

bool pr[MAXP];
vi primes;
ll a;

vll p;

ll get_p(ll val) {
  if  (val == 1) return -1; // p != -1
//  if  (val == 2) return -1; //!!!!!!!!!!
  ll VAL = val;
  for (int i = 0; i < sz(primes) && primes[i] * 1ll * primes[i] <= VAL; ++i) {
    if  (val % primes[i] == 0) {
      ll pp = primes[i];
      val /= pp;
      while (val % pp == 0) {
        val /= pp;
      }
      if  (val == 1) {
        return pp;
      }
      return -1;
    }
  }      
  return val;
}

vll dels;

int get_id_del(ll d) {
  int pos = lower_bound(all(dels), d) - dels.begin();
  if  (pos < sz(dels) && dels[pos] == d) {
    return pos;
  }
  return -1;
}

vector<pll> good_dels;
int start[10000];

ll calc(vector<vll>& dp, int id_del, int id_p) {
  ll& d = dp[id_del][id_p];
  if  (d != -1) {
    return d;
  }

  if  (id_p == 0) {
    return (d = id_del == 0);
  }

  ll val = dels[id_del];
  d = 0;

  // take
  for (int i = start[id_p]; i < sz(good_dels) && good_dels[i].fst == id_p; ++i) {
    ll cur_d = good_dels[i].snd;
//    printf("val = %I64d, cur_d = %I64d\n", val, cur_d);
    if  (val % cur_d != 0) {
      continue;
    }

    int nid_del = get_id_del(val / cur_d);
    if  (nid_del != -1) {
      d += calc(dp, nid_del, id_p - 1);
    }
  }

  // do not take
  d += calc(dp, id_del, id_p - 1);

//  printf("dp[del=%I64d][p=%I64d] = %I64d\n", dels[id_del], p[id_p], d);
  return d;
}                                  

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  memset (pr, true, sizeof pr);
  for (int i = 2; i < MAXP; ++i) {
    if  (pr[i]) {
      primes.pb(i);
      for (int j = i + i; j < MAXP; j += i) {
        pr[j] = false;
      }
    }
  }

  cin >> a;
  
  for (ll i = 1; i * i <= a; ++i) {
    if  (a % i == 0) {
      dels.pb(i);
      if  (i * i < a) {
        dels.pb(a / i);
      }
    }
  }

  sort(all(dels));
/*  
  for (ll del : dels) {
    printf("%I64d\n", del);
  }
*/
  for (ll del : dels) {
    if  (del == 1) continue;
    ll cur_p = get_p(del - 1);
    if  (cur_p > 0) {
      good_dels.pb(mp(cur_p, del));
//      printf("p=%I64d, del=%I64d\n", cur_p, del);
      p.pb(cur_p);
    }
  }

  p.pb(-1ll);
  sort(all(p));
  p.resize(unique(all(p)) - p.begin());
/*
  puts("p:");
  forn(i, sz(p)) {
    printf("%I64d ", p[i]);
  }
  puts("");
*/
  forn(i, sz(good_dels)) {
    good_dels[i].fst = lower_bound(all(p), good_dels[i].fst) - p.begin();
  }
  sort(all(good_dels));
  forn(i, sz(good_dels)) {
    if  (i == 0 || good_dels[i].fst != good_dels[i - 1].fst) {
      start[good_dels[i].fst] = i;
    }
  }

//  printf("sz = %d\n", sz(good_dels));
//  printf("sz_p = %d\n", sz(p));

  vector<vector<ll>> dp(sz(dels), vector<ll>(sz(p), -1));
  cout << calc(dp, sz(dels) - 1, sz(p) - 1) << endl;

  return 0;
}