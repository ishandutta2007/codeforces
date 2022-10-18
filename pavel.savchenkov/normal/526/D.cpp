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
const int MAXN = 1e6 + 10;

int go[MAXN][22];
int p[MAXN];
char s[MAXN];
int n;
char res[MAXN];
int k;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif

  scanf("%d%d\n", &n, &k);
  gets(s);
     
  if  (k == 1) {
    forn(i, n) putchar('1');
    return 0;
  }

  p[0] = 0;
  res[0] = '0';
  for (int i = 1; i < n; ++i) {
    int j = p[i - 1];
    while (j && s[i] != s[j]) j = p[j - 1];
    if  (s[i] == s[j]) {
      ++j;
    }
    p[i] = j;

    if  (p[i] == 0) {
      res[i] = '0';
      continue;
    }

    int L = i + 1;
/*    
    bool ok = false;
    for (int len = p[i]; len > 0; len = p[len - 1]) {
      if  (L == 15) printf("len = %d, %d\n", len, L / (L - len));
      if  (L / (L - len) == k) {
        ok = true;
      }
    }
    puts("");

    res[i] = '0' + ok;
    continue;
*/   

    go[p[i]][0] = p[p[i] - 1];
    for (int j = 1; j < 21; ++j) {
      go[p[i]][j] = go[go[p[i]][j - 1]][j - 1];
    }

    bool ok = false;
    int len = p[i];
    for (int l = 20; l >= 0; --l) {
      int len_ = go[len][l];
      if  (L / (L - len_) >= k) len = len_;
    }

    ok = L / (L - len) == k;
  
    len = p[i];
    for (int l = 20; l >= 0; --l) {
      int len_ = go[len][l];
      if  (L / (L - len_) >= k + 1) len = len_;
    }

    if  (L % (L - len) == 0 && L / (L - len) == k + 1) ok = true;

    res[i] = '0' + ok;
  }

  res[n] = 0;
  puts(res);
  return 0;
}