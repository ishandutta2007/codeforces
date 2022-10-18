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
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

const int MAXN = 100 + 10;

bool was[MAXN];
int nxt[MAXN];
bool root[MAXN];

void gen() {
  ofstream os(".in");

  string s;
  forn(i, 26) s += 'a' + i;
  random_shuffle(all(s));

  int n = 10;
  os << n << endl;
  forn(it, n) {
    int start = rand() % sz(s);
    int len = rand() % (sz(s) - start);
    if  (len == 0) len = 1;
    os << s.substr(start, len) << endl;
  }
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
  //freopen(FILE_NAME ".out", "w", stdout);
#endif

//  gen();
//  return 0;

  int n;
  scanf("%d\n", &n);
  vector<string> s(n);
  forn(i, n) {
    getline(cin, s[i]);
  }
  
  memset (was, false, sizeof was);
  memset (nxt, -1, sizeof nxt);
  memset (root, 1, sizeof root);
  forn(i, n) {
    forn(j, sz(s[i]) - 1) {
      int v = s[i][j] - 'a';
      int to = s[i][j + 1] - 'a';
      nxt[v] = to;
      root[to] = false;
    }
    forn(j, sz(s[i])) {
      was[s[i][j] - 'a'] = true;
    }
  }
    
  string ans;
  forn(c, 26) {
    if  (root[c] && was[c]) {
      int v = c;
      while (v != -1) {
        ans += 'a' + v;
        v = nxt[v];
      }
    }
  }

  forn(i, n) {
    bool ok = false;
    forn(start, sz(ans) - sz(s[i]) + 1) {
      if  (ans.substr(start, sz(s[i])) == s[i]) {
        ok = true;
        break;
      } 
    }
    if  (!ok) {
      printf("fail on %s\n", s[i].data());
      assert(false);
    }
  }

  cout << ans;


#ifdef DEBUG
  cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}