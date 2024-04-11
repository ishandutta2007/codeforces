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
const int MAXN = 1e5 + 5;

char s[MAXN];
int n, p;

int code(char c) {
  return c - 'a';
}

int main() {    
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

  scanf("%d%d\n", &n, &p);
  gets(s);
  --p;

  if  (p >= n / 2) {
    reverse(s, s + n);
    p = n - p - 1;  
  }

  int res = 0;
  int r = -1;
  int l = n;
  for (int i = 0; i < n / 2; ++i) {
    if  (s[i] != s[n - i - 1]) {
      int c1 = code(s[i]);
      int c2 = code(s[n - i - 1]);

      res += min((c1 - c2 + 26) % 26, (c2 - c1 + 26) % 26);
      l = min(l, i);
      r = max(r, i);
    }
  }

  if  (0 <= l && r < n / 2 && l <= r) {
    if  (p < l) {
      res += r - p;
    } else if  (r < p) {
      res += p - l;
    } else {
      res += min(p - l + r - l, r - p + r - l);
    }
  }

  cout << res << endl;
	return 0;
}