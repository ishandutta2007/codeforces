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

struct Seg {
  int l, r;
  int mn, lzy;
} T[maxn << 2];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

void push_down(int o) {
  T[o << 1].mn += T[o].lzy; T[o << 1].lzy += T[o].lzy;
  T[o << 1 | 1].mn += T[o].lzy; T[o << 1 | 1].lzy += T[o].lzy;
  T[o].lzy = 0;
}

void push_up(int o) {
  T[o].mn = min(T[o << 1].mn, T[o << 1 | 1].mn);
}

void add(int o, int l, int r, int x) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].mn += x;
    T[o].lzy += x;
    return;
  }
  push_down(o);
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) add(o << 1, l, r, x);
  if (r > mi) add(o << 1 | 1, l, r, x);
  push_up(o);
}

int query(int o, int l, int r, int x) {
  if (T[o].mn > x) return 0;
  if (T[o].l == T[o].r) return T[o].l;
  push_down(o);
  if (l <= T[o].l && T[o].r <= r) {
    int ret = query(o << 1, l, r, x);
    if (!ret) ret = query(o << 1 | 1, l, r, x);
    return ret;
  }
  int mi = T[o].l + T[o].r >> 1, ret = 0;
  if (l <= mi) ret = query(o << 1, l, r, x);
  if (!ret && r > mi) ret = query(o << 1 | 1, l, r, x);
  return ret;
}

int n, k, d;
int a[maxn], L[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k >> d;
  FOR(i, 1, n) cin >> a[i];
  if (!d) {
    int ans = 1, best = 1;
    FOR(i, 1, n) {
      if (i > 1 && a[i] == a[i - 1]) L[i] = L[i - 1] + 1;
      else L[i] = 1;
      if (L[i] > ans) {
        ans = L[i];
        best = i;
      }
    }
    cout << best - ans + 1 << ' ' << best;
    return 0;
  }
  FOR(i, 1, n) a[i] += 1e9;
  map<int, int> last;
  FOR(i, 1, n) {
    if (i > 1 && a[i] % d == a[i - 1] % d) L[i] = max(L[i - 1], last[a[i]] + 1);
    else L[i] = i;
    last[a[i]] = i;
  }
  FOR(i, 1, n) a[i] /= d;
  stack<int> s1, s2;
  s1.emplace(0), s2.emplace(0);
  build(1, 1, n);
  int ans = 1, best = 1;
  FOR(i, 1, n) {
    add(1, i, i, i);
    while (s1.size() > 1 && a[s1.top()] <= a[i]) {
      int r = s1.top(); s1.pop();
      int l = s1.top() + 1;
      add(1, l, r, a[i] - a[r]);
    }
    s1.emplace(i);
    while (s2.size() > 1 && a[s2.top()] >= a[i]) {
      int r = s2.top(); s2.pop();
      int l = s2.top() + 1;
      add(1, l, r, a[r] - a[i]);
    }
    s2.emplace(i);
    int l = query(1, L[i], i, k + i);
    if (l && i - l + 1 > ans) {
      ans = i - l + 1;
      best = i;
    }
  }
  cout << best - ans + 1 << ' ' << best;
}