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

int n, m;
pii a[maxn], b[maxn];
int ans[maxn];
ll f[maxn];

inline void add(int l, int r, ll d) {
  if (l <= r) f[l] += d, f[r + 1] -= d;
}

void add1(int i, int l, int r, ll d) {
  if (l <= r) {
    if (i < l) add(l - i + 1, r - i + 1, d);
    else if (i > r) add(l + n - i + 1, r + n - i + 1, d);
    else {
      add(1, r - i + 1, d);
      add(l + n - i + 1, n, d);
    }
  }
}

void add2(int i, int l, int r, ll d) {
  if (l <= r) {
    if (i < l) add(i + n - r + 1, i + n - l + 1, d);
    else if (i > r) add(i - r + 1, i - l + 1, d);
    else {
      add(1, i - l + 1, d);
      add(i + n - r + 1, n, d);
    }
  }
}

int main() {
  scanf("%d%d", &m, &n);
  FOR(i, 1, n) {
    scanf("%d", &a[i]._1);
    a[i]._2 = i;
  }
  FOR(i, 1, n) {
    scanf("%d", &b[i]._1);
    b[i]._2 = i;
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  FOR(i, 1, n) {
    int l = 1, r = lower_bound(b + 1, b + n + 1, mp(a[i]._1 - (m + 1) / 2, n + 1)) - b - 1;
    add1(i, l, r, m - a[i]._1);
    l = lower_bound(b + 1, b + n + 1, mp(a[i]._1 - (m + 1) / 2, n + 1)) - b;
    r = lower_bound(b + 1, b + n + 1, mp(a[i]._1, n + 1)) - b - 1;
    add1(i, l, r, a[i]._1);
    l = lower_bound(b + 1, b + n + 1, mp(a[i]._1, n + 1)) - b;
    r = lower_bound(b + 1, b + n + 1, mp(a[i]._1 + m / 2, n + 1)) - b - 1;
    add1(i, l, r, -a[i]._1);
    l = lower_bound(b + 1, b + n + 1, mp(a[i]._1 + m / 2, n + 1)) - b;
    r = n;
    add1(i, l, r, m + a[i]._1);
  }
  FOR(i, 1, n) {
    int l = lower_bound(a + 1, a + n + 1, mp(b[i]._1 + (m + 1) / 2, 0)) - a, r = n;
    add2(i, l, r, b[i]._1);
    l = lower_bound(a + 1, a + n + 1, mp(b[i]._1, 0)) - a;
    r = lower_bound(a + 1, a + n + 1, mp(b[i]._1 + (m + 1) / 2, 0)) - a - 1;
    add2(i, l, r, -b[i]._1);
    l = lower_bound(a + 1, a + n + 1, mp(b[i]._1 - m / 2, 0)) - a;
    r = lower_bound(a + 1, a + n + 1, mp(b[i]._1, 0)) - a - 1;
    add2(i, l, r, b[i]._1);
    l = 1;
    r = lower_bound(a + 1, a + n + 1, mp(b[i]._1 - m / 2, 0)) - a - 1;
    add2(i, l, r, -b[i]._1);
  }
  int best = 0;
  FOR(i, 1, n) {
    f[i] += f[i - 1];
    if (!best || f[i] < f[best]) best = i;
  }
  FOR(i, 1, n) {
    int j = i + best - 1;
    if (j > n) j -= n;
    ans[a[i]._2] = b[j]._2;
  }
  printf("%lld\n", f[best]);
  FOR(i, 1, n) printf("%d ", ans[i]);
}