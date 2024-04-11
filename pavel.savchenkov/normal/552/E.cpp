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
const int MAXN = 5e3 + 10;

string s;
int n;

string to_string(ll x) {
  string r;
  while (x) {
    r += '0' + x % 10;;
    x /= 10;
  }
  reverse(all(r));
  return r;
}

ll calc(string t) {
  t += '+';

//  cout << "t = " << t << endl;

  ll res = 0;
  ll mult = 1;
  ll num = 0;
  for (char c : t) {
    if  (c == '*') {
      mult = mult * num;
      num = 0;
    } else if  (c == '+') {
      res += mult * num;
      mult = 1;
      num = 0;
    } else {
      num = num * 10 + (c - '0');
    }
  }
//  cout << "res = " << res << endl << endl;;
  return res;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  getline(cin, s);
  n = sz(s);

  vi left;
  left.pb(-1);
  forn(i, n) {
    if  (s[i] == '*') {
      left.pb(i);
      if  (i + 2 < n - 1) {
        left.pb(i + 2);
      }
    }
  } 

  vi right;
  right.pb(n - 1);
  forn(i, n) {
    if  (s[i] == '*') {
      right.pb(i - 1);
      if  (i - 3 > 0) {
        right.pb(i - 3);
      }
    }
  }

  ll ans = 0;
  for (int l : left) for (int r : right) {
    if  (r - l < 1) {
      continue;
    }
    string mid = to_string(calc(s.substr(l + 1, r - l)));
//    cout << "mid = " << mid << " [" << l << ", " << r << "]" << endl;
    ans = max(ans, calc(s.substr(0, l + 1) + mid + s.substr(r + 1, n - r)));
//    puts("");
  }

  cout << ans << endl;
  return 0;
}