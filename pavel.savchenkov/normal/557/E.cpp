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
const int MAXN = 5e3 + 10;

bool is_pal[MAXN][MAXN];
int cnt_pals[MAXN][MAXN];
char s[MAXN];
int n, k;

char t[2 * MAXN];
int m;
int p[2 * MAXN];

int cnt_ch[30];

int get_pref(const string& pref, bool eq = false) {
  m = 0;
  forn(i, sz(pref)) t[m++] = pref[i];
  t[m++] = '#';
  forn(i, n) t[m++] = s[i];
  t[m] = 0;
  
//  puts(t);

  memset (cnt_ch, 0, sizeof cnt_ch);
  int cnt = 0;
  p[0] = 0;
  for (int i = 1; i < m; ++i) {
    int j = p[i - 1];
    while (j > 0 && t[i] != t[j]) j = p[j - 1];
    j += t[i] == t[j];
    p[i] = j;

    if  (i > sz(pref) && p[i] == sz(pref)) {
      cnt += eq ? is_pal[(i - sz(pref) - 1) - sz(pref) + 1][i - sz(pref) - 1] : cnt_pals[(i - sz(pref) - 1) - sz(pref) + 1][i - sz(pref) - 1];
      if  (i + 1 < m) {
        ++cnt_ch[t[i + 1] - 'a'];
      }
    } 
  }

  return cnt;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  gets(s);
  n = strlen(s);
  scanf("%d", &k);

  for (int len = 1; len <= n; ++len) {
    forn(l, n) {
      int r = l + len - 1;
      if  (r >= n) {
        break;
      }
      is_pal[l][r] = (s[l] == s[r]) && (l + 2 <= r - 2 ? is_pal[l + 2][r - 2] : true);
    }
  }

  forn(l, n) ford(r, n) {
    cnt_pals[l][r] = is_pal[l][r]; 
    cnt_pals[l][r] += cnt_pals[l][r + 1];
  }

  string pref;
  vector<char> ch;
  forn(i, 26) ch.pb('a' + i);
  forn(it, 100500) {
//    cout << "pref = " << pref << "; k = " << k << 
//     endl;

    int cnt = 0;
    for (char c : ch) {
      pref += c;
      cnt = get_pref(pref);
//      printf("c=%c, cnt=%d, k=%d\n", c, cnt, k);
      if  (cnt < k) {
        k -= cnt;
        pref.pop_back();
      } else {
        break;
      }
    }
//    ch.clear();
//    forn(i, 26) if  (cnt_ch[i]) ch.pb('a' + i);
    int last = get_pref(pref, true);
    if  (last >= k) {
      break;
    } 
    k -= last;
  }

  printf("%s\n", pref.c_str());
  return 0;
}