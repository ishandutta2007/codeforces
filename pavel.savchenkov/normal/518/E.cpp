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
const int MAXN = 1e5 + 10;

#define terminate dkljsfkljfkld

void terminate() {
  puts("Incorrect sequence");
  exit(0);
}

vi make(int cnt, int low, int up) {
  vvi r;

  vi res1;
  forn(i, cnt) {
    res1.pb(low + i + 1);
  }
  if  (res1.back() >= up) {
    terminate();
  }

  if  (low >= 0) {
    return res1;
  }
  r.pb(res1);

  vi res2;
  forn(i, cnt) {
    res2.pb(up - i - 1);
  }
  reverse(all(res2));
  if  (res2[0] <= low) {
    terminate();
  }

  if  (up <= 0) {
    return res2;
  }
  r.pb(res2);

  vi res3(cnt);
  res3[cnt / 2] = 0;
  for (int i = cnt / 2 - 1; i >= 0; --i) {
    res3[i] = res3[i + 1] - 1;
  }
  for (int i = cnt / 2 + 1; i < cnt; ++i) {
    res3[i] = res3[i - 1] + 1;
  }
  r.pb(res3);

  if  (cnt / 2 - 1 >= 0) {
    vi res4(cnt);
    res4[cnt / 2 - 1] = 0;
    for (int i = cnt / 2 - 1 - 1; i >= 0; --i) {
      res4[i] = res4[i + 1] - 1;
    }
    for (int i = cnt / 2; i < cnt; ++i) {
      res4[i] = res4[i - 1] + 1;
    }
  }

  vi res = r[0];
  ll min_sum = 0;
  forn(i, cnt) {
    min_sum += abs(res[i]);
  }

  for (int j = 1; j < sz(r); ++j) {
    ll sum = 0;
    forn(i, cnt) {
      sum += abs(r[j][i]);
    }

    if  (r[j][0] > low && r[j].back() < up && sum < min_sum) {
      res = r[j];
    }
  }
  
  return res;
}

vi chain[MAXN];
int n, k;
int a[MAXN];
bool know[MAXN];

void make(int r) {
  int low = - (int) 2e9;
  int cnt = 0;
  int up = (int) 2e9;
  forn(i, sz(chain[r])) {
    int id = r + i * k;
/*
    printf("id = %d\n", id);
    printf("know = %d\n", know[id]);
    printf("cnt = %d\n\n", cnt);
*/
    if  (know[id]) {
      if  (cnt > 0) {
        up = chain[r][i];
        vi cur = make(cnt, low, up);
        for (int j = i - 1; j >= i - cnt; --j) {
          chain[r][j] = cur[j - (i - cnt)];
        }
      }
      cnt = 0;
      low = chain[r][i]; 
    } else {
      ++cnt;
    }
  }

  if  (cnt > 0) {
    vi cur = make(cnt, low, (int) 2e9);
    for (int j = sz(chain[r]) - 1; j >= sz(chain[r]) - cnt; --j) {
      chain[r][j] = cur[j - (sz(chain[r]) - cnt)];
    }
  }

  forn(i, sz(chain[r])) {
    int id = r + i * k;
    a[id] = chain[r][i];
  }
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d%d\n", &n, &k);

  forn(i, n) {
    scanf(" ");

    string s;
    char c;
    while (1) {
      c = getchar();
      if  (c != '?' && !('0' <= c && c <= '9') && !(c == '-')) {
        break;
      }
      s += c;
    }

    if  (s == "?") {
      know[i] = false;
      scanf(" ");
    } else {
      bool neg = s[0] == '-';
      int x = 0;
      forn(j, sz(s)) {
        char c = s[j];
        if  ('0' <= c && c <= '9') {
          x = x * 10 + (c - '0');
        } 
      }
      if  (neg) {
        x = -x;
      }
      a[i] = x;
      know[i] = true;
    }

    chain[i % k].pb(a[i]);
  }

  forn(r, k) {
    make(r);
  }

  forn(i, n) {
    if  (i + k < n) {
      if  (a[i] >= a[i + k]) {
        terminate();
      }
    }
  }

  forn(i, n) {
    printf("%d ", a[i]);
  }
  puts("");

  return 0;
}