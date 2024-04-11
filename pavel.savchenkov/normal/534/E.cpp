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

const ld EPS = 1e-9;
const int MAXN = 8e5 + 10;

int eq = 0;
int nc[MAXN];
int c[MAXN];
int a[MAXN];
int n;

int m;
int b[MAXN];

void read() {
  scanf("%d", &n);
  forn(i, n) scanf("%d", &a[i]);

  scanf("%d", &m);
  forn(i, m) {
    scanf("%d", &b[i]);
    --b[i];
    ++c[b[i]];
  }
}
 
void change(int i, int add) {
  eq -= c[i] == nc[i];
  nc[i] += add;
  eq += c[i] == nc[i];
}

int who(int pos) {
  pos %= 2 * n - 2;
  if  (pos <= n - 1) {
    return pos;
  }
  pos -= n - 1;
  return n - 1 - pos;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif

  read();

  eq = 0;
  forn(i, n) eq += c[i] == 0;
  ll cur_dist = 0;
  forn(i, m - 1) {
    change(who(i), +1);
    cur_dist += abs(a[who(i)] - a[who(i + 1)]);
  }
  change(who(m - 1), +1);

  ll dist = -1;
  for (int l = 0, r = m; l < 2 * n - 1; ++l, ++r) {
    if  (eq == n) {
      if  (dist != -1 && cur_dist != dist) {
        puts("-1");
        return 0;
      }
      dist = cur_dist;
    }

    cur_dist -= abs(a[who(l)] - a[who(l + 1)]);
    cur_dist += abs(a[who(r - 1)] - a[who(r)]);

    change(who(l), -1);
    change(who(r), +1);
  }

  cout << dist << endl;
  return 0;
}