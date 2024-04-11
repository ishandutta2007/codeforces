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
#include <fstream>
#include <unordered_map>
#include <unordered_set>

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
const int INF = 2e9;

struct MySet {
  multiset<int> s;
  int add;

  MySet() : add(0) {}

  void insert(int x) {
    s.insert(x - add);
  }

  int get_min() {
    return s.empty() ? -INF : (*s.begin() + add);
  }
};

const int MAXN = 1e5 + 10;

int n;
int h[MAXN];

bool read() {
  if  (scanf("%d", &n) < 1) {
    return false;
  }
  forn(i, n) scanf("%d", &h[i]);
  return true;
}

int left[MAXN];
int right[MAXN];

int solve() {
  int ans = 0;

  MySet s_left;
  s_left.insert(1);
  forn(i, n) {
    left[i] = s_left.get_min();
    s_left.insert(h[i]);  
    ++s_left.add;
  } 

  MySet s_right;
  s_right.insert(1);
  ford(i, n) {
    right[i] = s_right.get_min();
    s_right.insert(h[i]);
    ++s_right.add;
  }

  forn(i, n) {
//    printf("%d %d\n", left[i], right[i]);
    int cur = min(min(left[i], right[i]), h[i]);
    ans = max(ans, cur);
  }

  return ans;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    cout << solve()<< '\n';
  }

  return 0;
}