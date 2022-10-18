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
const int MAXN = 1e5 + 10;

int a[MAXN];
int n;

string ans;

bool make1(int, int);

bool make0(int l, int r) {
//  printf("make0 [%d, %d]\n", l, r);

  if  (l == r) {
    if  (a[l] == 0) {
      ans += "0";
      return true;
    }
    return false;
  }

  if  (a[r] != 0) {
    return false;
  }

  if  (!make1(l, r - 1)) {
    return false;
  }
  ans += "->0";
  return true;
}

void make(int l, int r) {
//  printf("make [%d, %d]\n", l, r);

  for (int i = l; i <= r; ++i) {
    ans += a[i] + '0';
    if  (i + 1 <= r) {
      ans += "->";
    }
  }
}

bool make1(int l, int r) {
//  printf("make1 [%d, %d]\n", l, r);

  if  (l == r) {
    if  (a[l] == 1) {
      ans += "1";
      return true;
    }
    return false;
  }

  int pref = -1;
  int cur = a[l];
  for (int i = l + 1; i <= r; ++i) {
    if  (cur == 0) {
      pref = i - 1;
      break;
    }
    if  (cur == 1 && a[i] == 0) {
      cur = 0;
    } else {
      cur = 1;
    }
  }

  if  (cur == 1) {
    make(l, r);
    return true;
  }

  if  (pref == -1) {
    return false;
  }

  if  (pref == r) {
    return false;
  }

  if  (pref == -1) {
    make(l, r);
    return true;
  }

  make(l, pref);
  ans += "->(";
  make(pref + 1, r);
  ans += ")";

  return true; 
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d", &n);
  forn(i, n) {
    scanf("%d", &a[i]);
  }

  if  (!make0(0, n - 1)) {
    puts("NO");
    return 0;
  }

  puts("YES");
  puts(ans.c_str());

  return 0;
}