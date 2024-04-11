#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = (int) 1e6 + 10000;

struct seg {
  int len;
  int x1, x2, y1, y2;

  seg(int x1 = 0, int x2 = 0, int y1 = 0, int y2 = 0) : x1(x1), x2(x2), y1(y1), y2(y2) { len = abs(x1 - x2) + abs(y1 - y2); };
};

seg segs[MAXN];
vector <int> x;
vector <int> y;
int n, m, k;

vector <pii> segv[MAXN];
vector <pii> segg[MAXN];

vector <int> lens;

seg vseg, gseg;

void out(int x1, int x2, int y1, int y2) {
  printf("%d %d %d %d\n", x1, y1, x2, y2);
  exit(0);
}

int main() {                            
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d %d", &n, &m, &k);

  int K = k; k = 0;

  for (int i = 0; i < K; i++) {
    int x1, x2, y1, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    if  (x1 > x2) swap(x1, x2);
    if  (y1 > y2) swap(y1, y2);

    segs[k++] = seg(x1, x2, y1, y2);

    x.pb(x1);
    x.pb(x2);
    y.pb(y1);
    y.pb(y2);  
  }

  sort(x.begin(), x.end());
  x.resize(unique(x.begin(), x.end()) - x.begin());

  sort(y.begin(), y.end());
  y.resize(unique(y.begin(), y.end()) - y.begin());

  for (int i = 0; i < k; i++)
    if  (segs[i].y1 == segs[i].y2) {
      int Y = segs[i].y1;
      int pos = lower_bound(y.begin(), y.end(), Y) - y.begin();
      segv[pos].pb(mp(segs[i].x1, 0));
      segv[pos].pb(mp(segs[i].x2, 1));
    } else {
      int X = segs[i].x1;
      int pos = lower_bound(x.begin(), x.end(), X) - x.begin();
      segg[pos].pb(mp(segs[i].y1, 0));
      segg[pos].pb(mp(segs[i].y2, 1));
    }


  for (int i = 0; i < sz(y); i++) {
    if  (y[i] == 0 || y[i] == m) continue;

    segv[i].pb(mp(0, 0)); segv[i].pb(mp(0, 1));
    segv[i].pb(mp(n, 0)); segv[i].pb(mp(n, 1));

    sort(segv[i].begin(), segv[i].end());

    int cnt = 0; int len = 0;
    for (int j = 0; j < sz(segv[i]) - 1; j++) {
      if  (!segv[i][j].s) cnt++; else cnt--;

      if  (cnt == 0)
        len += segv[i][j + 1].f - segv[i][j].f;
    }

    if  (len > 0) lens.pb(len);
  }

  for (int i = 0; i < sz(x); i++) {
    if  (x[i] == 0 || x[i] == n) continue;

    segg[i].pb(mp(0, 0)); segg[i].pb(mp(0, 1));
    segg[i].pb(mp(m, 0)); segg[i].pb(mp(m, 1));

    sort(segg[i].begin(), segg[i].end());

    int cnt = 0; int len = 0;
    for (int j = 0; j < sz(segg[i]) - 1; j++) {
      if  (!segg[i][j].s) cnt++; else cnt--;

      if  (cnt == 0)
        len += segg[i][j + 1].f - segg[i][j].f;
    }

    if  (len > 0) lens.pb(len);
  }

                           
  vseg = seg(-1, -1, -1, -1);
  int cnt = m - 1 - sz(y);
  if  (!y.empty() && y[0] == 0) cnt++;
  if  (!y.empty() && *y.rbegin() == m) cnt++;

  for (int i = 1; i < MAXN && cnt % 2 == 1 && cnt > 0; i++) {
      int pos = lower_bound(y.begin(), y.end(), i) - y.begin();

      if  (pos == sz(y) || y[pos] != i) {
        vseg = seg(0, n, i, i);
        lens.pb(n);
        break;  
      }          
    }

  gseg = seg(-1, -1, -1, -1);
  cnt = n - 1 - sz(x);
  if  (!x.empty() && x[0] == 0) cnt++;
  if  (!x.empty() && *x.rbegin() == n) cnt++;

  for (int i = 1; i < MAXN && cnt % 2 == 1 && cnt > 0; i++) {
      int pos = lower_bound(x.begin(), x.end(), i) - x.begin();

      if  (pos == sz(x) || x[pos] != i) {
        gseg = seg(i, i, 0, m);
        lens.pb(m);
        break;
      }
  }


  int res = 0;
  for (int i = 0; i < sz(lens); i++)
    res ^= lens[i];

  if  (res == 0) {
    puts("SECOND");
    return 0;
  } else puts("FIRST");

  int bit = 0;
  for (int i = 30; i >= 0; i--)
    if  (res & (1 << i)) {
      bit = i;
      break;
    }

  int need = 0; int needlen = 0;
  for (int i = 0; i < sz(lens); i++)
    if  (lens[i] & (1 << bit)) {
      need = lens[i] - (lens[i] ^ res);
      needlen = lens[i];
      break;
    }

//  printf("need = %d needlen = %d\n", need, needlen);
//  for (int i = 0; i < sz(lens); i++)
//    printf("%d ", lens[i]); puts("");

  int x1, x2, y1, y2;

  for (int i = 0; i < sz(y); i++) {
    if  (y[i] == 0 || y[i] == m) continue;
    int cnt = 0; int len = 0;
    x1 = 0; y1 = y2 = y[i];

    for (int j = 0; j < sz(segv[i]) - 1; j++) {
      if  (!segv[i][j].s) cnt++; else cnt--;

      if  (cnt == 0)
        len += segv[i][j + 1].f - segv[i][j].f;
    }

    if  (len != needlen) continue;
    len = cnt = 0;

    for (int j = 0; j < sz(segv[i]) - 1; j++) {
      if  (!segv[i][j].s) cnt++; else cnt--;

      if  (cnt == 0) {
        len += segv[i][j + 1].f - segv[i][j].f;
        if  (len >= need) {
          len -= segv[i][j + 1].f - segv[i][j].f;
          x2 = segv[i][j].f + (need - len);
          out(x1, x2, y1, y2);
        }
      }
    }
  }


  for (int i = 0; i < sz(x); i++) {
    if  (x[i] == 0 || x[i] == n) continue;

    int cnt = 0; int len = 0;
    x1 = x2 = x[i]; y1 = 0;

    for (int j = 0; j < sz(segg[i]) - 1; j++) {
      if  (!segg[i][j].s) cnt++; else cnt--;

      if  (cnt == 0)
        len += segg[i][j + 1].f - segg[i][j].f;
    }

    if  (len != needlen) continue;
    len = cnt = 0;

    for (int j = 0; j < sz(segg[i]) - 1; j++) {
      if  (!segg[i][j].s) cnt++; else cnt--;

      if  (cnt == 0) {
        len += segg[i][j + 1].f - segg[i][j].f;
        if  (len >= need) {
          len -= segg[i][j + 1].f - segg[i][j].f;
          y2 = segg[i][j].f + (need - len);
          out(x1, x2, y1, y2);  
        }
      }
    }
  }

  if  (vseg.x1 != -1 && needlen == vseg.len)
    out(vseg.x1, vseg.x1 + need, vseg.y1, vseg.y2);

  out(gseg.x1, gseg.x1, gseg.y1, gseg.y1 + need); 
  return 0;
}