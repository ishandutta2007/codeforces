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
const int MAXN = 2e5 + 10;

int cnt[300];

char s[MAXN];
char t[MAXN];
bool ready[MAXN];

int change(char c) {
  if  ('a' <= c && c <= 'z') {
    return (c + 'A') - 'a';
  }
  return (c + 'a') - 'A';
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  gets(s);
  gets(t);

  for (int i = 0; t[i]; ++i) {
    ++cnt[(int) t[i]];
  }

  int res1 = 0;
  for (int i = 0; s[i]; ++i) {
    int c = s[i];
    if  (cnt[c]) {
      ready[i] = true;
      ++res1;
      --cnt[c];
    }
  }

  int res2 = 0;
  for (int i = 0; s[i]; ++i) {
    if  (!ready[i]) {
      int c = change(s[i]);

      if  (cnt[c]) {
        ready[i] = true;
        --cnt[c];
        ++res2;
      } 
    }
  }

  printf("%d %d\n", res1, res2);

  return 0;
}