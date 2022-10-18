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
const int MAXN = 1e5 + 10;

int a[MAXN];
int n;
int mx[MAXN];
int ans = 0;
int N;

void calc(int v) {
  if  (2 * v >= N) {
    mx[v] = 0;
    return;
  } 

  calc(2 * v);
  calc(2 * v + 1);

  mx[v] = max(a[2 * v] + mx[2 * v], a[2 * v + 1] + mx[2 * v + 1]);
}

void make(int v, int sum) {
  if  (2 * v >= N) {
    return;
  }

  int put = sum - (mx[2 * v] + a[2 * v]);
  ans += put;
  make(2 * v, sum - (put + a[2 * v]));

  put = sum - (mx[2 * v + 1] + a[2 * v + 1]);
  ans+= put;
  make(2 * v + 1, sum - (put + a[2 * v + 1]));
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n;
  N = 1 << (n + 1);
  for (int i = 2; i < N; ++i) {
    scanf("%d", &a[i]);
  }

  calc(1);

  make(1, mx[1]);

  cout << ans << endl;
  return 0;
}