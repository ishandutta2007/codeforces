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
const int MAXN = 2e5 + 10;

int n, k;
int cnt[2];

bool solve() {
  int moves = n - k;
               
  if  (moves == 0) {
    return cnt[1] & 1;
  }

  // remove 1
  int moves2 = moves / 2;
  int moves1 = moves - moves2;
//  printf("moves1 = %d, moves2 = %d\n", moves1, moves2);
  if  (moves2 + max(0, moves1 - cnt[0]) >= cnt[1]) {
    return false;
  }

//  puts("here");

  int sum = cnt[1] & 1;

  // remove 0
  int rem1 = max(0, moves - cnt[0]) & 1;
  if  ((moves2 >= cnt[0] || moves == n) && (sum ^ rem1) == 0) {
    return false;
  }

  // remove 0
  if  ((moves1 >= cnt[0] || moves == n) && (sum ^ rem1) == 1) {
    return true;
  }

//  puts("here2");

  if  (moves % 2 == 0) {
    return false;
  }

  return true;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  forn(i, n) {
    int a;
    scanf("%d", &a);
    ++cnt[a & 1];
  }

  puts(solve() ? "Stannis" : "Daenerys");
  return 0;
}