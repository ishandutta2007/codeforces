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
const int MAXN = 3e6 + 5;

bool A[MAXN];
int last[MAXN];

int main() {

  int n;
  scanf("%d", &n);
  forn(i, n) {
    int a;
    scanf("%d", &a);
    A[a] = true;
  }

  last[0] = 0;
  for (int i = 1; i < MAXN; ++i) {
    last[i] = A[i] ? i : last[i - 1];
  }

  int res = 0;
  for (int d = 2; d < MAXN; ++d) {
    if  (A[d]) {
      for (int j = d + d; j < MAXN; j += d) {
        if  (last[j - 1] > j - d) {
          res = max(res, last[j - 1] - (j - d));
        }
      }
    }
  }

  cout << res << endl;

	return 0;
}