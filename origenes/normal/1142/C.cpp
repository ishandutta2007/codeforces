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

const int maxa = 2123456;
const int add = 1e6 + 10;
const double eps = 1e-9;

int y[maxa], n;
double b, c;

inline double f(double x) {
  return sqr(x) + b * x + c;
}

inline int dcmp(double x) {
  if (abs(x) <= eps) return 0;
  return x > 0 ? 1 : -1;
}

bool check(int u, int v, int w) {
  ll dx = u - w, dy = y[u] - y[w] - sqr(ll(u)) + sqr(ll(w));
  b = double(dy) / dx, c = y[u] - sqr(ll(u)) - u * b;
  return dcmp(f(v) - y[v]) >= 0;
}

int main() {
  scanf("%d", &n);
  fill(y, y + maxa, -1e9);
  FOR(i, 1, n) {
    int a, b;
    scanf("%d%d", &a, &b);
    chkmax(y[a + add], b);
  }
  vector<int> q;
  REP(i, maxa) if (y[i] > -5e8) {
    while (q.size() > 1) {
      if (check(q[int(q.size()) - 2], q.back(), i)) q.pop_back();
      else break;
    }
    q.eb(i);
  }
  printf("%d", int(q.size()) - 1);
}