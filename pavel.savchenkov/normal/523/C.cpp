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

#define debug(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr(T x) {
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
const int MAXN = 1e6 + 10;

int get(char* t, char* s) {
  int pos_s = 0;
  for (int i = 0; t[i]; ++i) {
    if  (t[i] == s[pos_s]) {
      ++pos_s;
    }
    if  (!s[pos_s]) {
      return i;
    }
  }
  return MAXN;
}

char s[MAXN];
char t[MAXN];

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  gets(s);
  gets(t);

  int l = get(t, s);
  
  int lt = strlen(t);
  reverse(t, t + lt);

  int ls = strlen(s);
  reverse(s, s + ls);

  int r = lt - get(t, s) - 1;

  printf("%d\n", max(0, r - l)); 
  return 0;
}