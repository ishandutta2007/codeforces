#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 1123;

int n, ansx[maxn], ansy[maxn];

int ask(int x1, int x2, int y1, int y2) {
  cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
  int ret;
  cin >> ret;
  return ret;
}

void answer(int x1, int y1, int x2, int y2) {
  cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
}

int main() {
  cin >> n;
  FOR(i, 1, n) ansx[i] = ask(i, i, 1, n);
  FOR(i, 1, n) ansy[i] = ask(1, n, i, i);
  vector<int> recx, recy;
  FOR(i, 1, n) if (ansx[i] & 1) recx.eb(i);
  FOR(i, 1, n) if (ansy[i] & 1) recy.eb(i);
  if (recx.empty()) {
    assert(recy.size() == 2);
    int lo = 1, hi = n, nowy = recy[0];
    while (lo < hi) {
      int mi = lo + hi >> 1;
      int cur = ask(lo, mi, nowy, nowy);
      if (cur & 1) hi = mi;
      else lo = mi + 1;
    }
    answer(lo, recy[0], lo, recy[1]);
  } else if (recy.empty()) {
    assert(recx.size() == 2);
    int lo = 1, hi = n, nowx = recx[0];
    while (lo < hi) {
      int mi = lo + hi >> 1;
      int cur = ask(nowx, nowx, lo, mi);
      if (cur & 1) hi = mi;
      else lo = mi + 1;
    }
    answer(recx[0], lo, recx[1], hi);
  } else {
    assert(recx.size() == 2 && recy.size() == 2);
    cerr << recx[0] << ' ' << recx[1] << endl;
    cerr << recy[0] << ' ' << recy[1] << endl;
    vector<pii> ans;
    REP(i, 2) REP(j, 2) {
      int tmp = ask(recx[i], recx[i], recy[j], recy[j]);
      if (tmp == 1) ans.eb(recx[i], recy[j]);
    }
    assert(ans.size() == 2);
    answer(ans[0]._1, ans[0]._2, ans[1]._1, ans[1]._2);
  }
}