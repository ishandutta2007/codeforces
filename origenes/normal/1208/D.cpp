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
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 212345;

ll fen[maxn], s[maxn];
int n, ans[maxn];

inline int lowbit(int x) {
  return x & -x;
}

void add(int x, int d) {
  while (x <= n) {
    fen[x] += d;
    x += lowbit(x);
  }
}

ll query(int x) {
  ll ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", s + i);
  FOR(i, 1, n) add(i, i);
  ROF(i, n, 1) {
    int lo = 1, hi = n;
    while (lo < hi) {
      int mi = lo + hi + 1 >> 1;
      ll cur = query(mi - 1);
      if (cur > s[i]) hi = mi - 1;
      else lo = mi;
    }
    ans[i] = lo;
    add(ans[i], -ans[i]);
  }
  FOR(i, 1, n) printf("%d ", ans[i]);
}