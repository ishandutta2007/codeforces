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

const int maxn = 112345;

int n, m, s;
int a[maxn], b[maxn], c[maxn];
int bid[maxn], sid[maxn], ans[maxn];

bool check(int day) {
  int rem = s, j = 1;
  map<int, vector<int>> cnt;
  for (int i = 1; i <= m; i += day) {
    while (j <= n && b[sid[j]] >= a[bid[i]]) cnt[c[sid[j]]].eb(sid[j]), j++;
    if (cnt.empty()) return false;
    rem -= cnt.begin()->_1;
    if (rem < 0) return false;
    FOR(k, i, min(i + day - 1, m)) ans[bid[k]] = cnt.begin()->_2.back();
    cnt.begin()->_2.pop_back();
    if (cnt.begin()->_2.empty()) cnt.erase(cnt.begin());
  }
  return true;
}

int main() {
  scanf("%d%d%d", &n, &m, &s);
  FOR(i, 1, m) scanf("%d", a + i);
  FOR(i, 1, n) scanf("%d", b + i);
  FOR(i, 1, n) scanf("%d", c + i);
  iota(bid + 1, bid + m + 1, 1);
  iota(sid + 1, sid + n + 1, 1);
  sort(bid + 1, bid + m + 1, [&](int x, int y) { return a[x] > a[y]; });
  sort(sid + 1, sid + n + 1, [&](int x, int y) { return b[x] > b[y]; });
  int mn = s + 5;
  FOR(i, 1, n) {
    if (b[sid[i]] < a[bid[1]]) break;
    chkmin(mn, c[sid[i]]);
  }
  if (mn > s) {
    puts("NO");
    return 0;
  }
  puts("YES");
  int lo = 1, hi = m;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  check(lo);
  FOR(i, 1, m) printf("%d ", ans[i]);
}