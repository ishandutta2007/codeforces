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
const int MAXN = 3e3 + 10;
const int INF = 1e9;

vi g[MAXN];
int n, m;

int Q[MAXN * 10];
int ql, qr;

void calc_d(int* d, int s) {
  forn(v, n) d[v] = INF;
  d[s] = 0;
  ql = qr = 0;
  Q[qr++] = s;
  while (ql != qr) {
    int v = Q[ql++];

    for (int to : g[v]) {
      if  (d[to] > d[v] + 1) {
        d[to] = d[v] + 1;
        Q[qr++] = to;
      }
    }
  } 
}

int d1[MAXN];
int d2[MAXN];
int dt1[MAXN];
int dt2[MAXN];
int s1, s2;
int t1, t2;
int l1, l2;

int d[MAXN];

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  forn(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a].pb(b);
    g[b].pb(a);
  }

  cin >> s1 >> t1 >> l1;
  --s1;
  --t1;
  
  cin >> s2 >> t2 >> l2;
  --s2;
  --t2;

  int mx = -1;

  forn(it, 2) {

  calc_d(d1, s1);
  calc_d(d2, s2);
  calc_d(dt1, t1);
  calc_d(dt2, t2);

  forn(s3, n) {
    ql = qr = 0;
    forn(v, n) d[v] = INF;
    d[s3] = 0;
    Q[qr++] = s3;
    while (ql != qr) {
      int v = Q[ql++];

      int L1 = d1[s3] + d[v] + dt1[v];
      int L2 = d2[s3] + d[v] + dt2[v];

      int stay = d1[s3] + d2[s3] + d[v] + dt1[v] + dt2[v];

      if  (L1 <= l1 && L2 <= l2) {
        mx = max(mx, m - stay);
//        printf("s3=%d, v=%d\n", s3, v);
      } 

      for (int to : g[v]) {
        if  (d[to] > d[v] + 1) {
          d[to] = d[v] + 1;
          Q[qr++] = to;
        }
      }
    } 
  }

  if  (d1[t1] <= l1 && d2[t2] <= l2) {
    mx = max(mx, m - d1[t1] - d2[t2]);
  }

    swap(s1, t1);
  }
  cout << mx << endl;

  return 0;
}