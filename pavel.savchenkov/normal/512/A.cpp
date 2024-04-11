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
const int A = 'z' - 'a' + 1;
const int MAXN = 100 + 10;

vi g[A];
char s[MAXN][MAXN];
int len[MAXN];
int n;
int color[MAXN];

void addE(char v, char to) {
  if  ('a' <= v && v <= 'z' && 'a' <= to && to <= 'z') {
//    printf("%c less %c\n", v, to);
    g[v - 'a'].pb(to - 'a');                              
  }
}

void go(int l, int r, int pos) {
//  if  (pos == 3) printf("%d %d %d\n", l, r, pos);

  if  (l == r) {
    return;
  }

  bool was = false;
  for (int i = l; i <= r; ++i) {
    was |= len[i] > pos;
    if  (len[i] <= pos && was) {
      puts("Impossible");
      exit(0);
    }
  }

  if  (!was) {
    return;
  }

  int prev = l;
  for (int i = l + 1; i <= r + 1; ++i) {
    if  (i == r + 1 || s[i][pos] != s[i - 1][pos]) {
      if  (i < r + 1) addE(s[i - 1][pos], s[i][pos]);
      go(prev, i - 1, pos + 1);
      prev = i;
    }
  }
}

vi top;

void dfs(int v) {
//  printf("in %d\n", v);
  color[v] = 1;

  for (int to : g[v]) {
    if  (color[to] == 1) {
      puts("Impossible");
      exit(0);      
    }

    if  (color[to] == 0) {
      dfs(to);
    }
  }

  color[v] = 2;
  top.pb(v);
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d\n", &n);
  forn(i, n) {
    gets(s[i]);
    len[i] = (int) strlen(s[i]);
  }
  
  go(0, n - 1, 0);

  memset (color, 0, sizeof color);
  forn(c, A) {
    if  (color[c] == 0) {
      dfs(c);
    }
  }

//  printf("%d\n", sz(top));
  reverse(all(top));
  for (int c : top) {
    putchar('a' + c);
  }

  return 0;
}