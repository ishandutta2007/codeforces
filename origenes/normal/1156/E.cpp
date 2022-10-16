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

const int maxn = 212345;

int n;
int p[maxn], lo[maxn], hi[maxn], loc[maxn];
ll ans;

int get(int l, int m, int r) {
  if (l == m || r == m) return 0;
  int ret = 0;
  if (m - l <= r - m) {
    FOR(i, l, m - 1) if (loc[p[m] - p[i]] > m && loc[p[m] - p[i]] <= r) ret++;
  } else {
    FOR(i, m + 1, r) if (loc[p[m] - p[i]] < m && loc[p[m] - p[i]] >= l) ret++;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", p + i);
    loc[p[i]] = i;
  }
  stack<int> s;
  p[n + 1] = p[0] = n + 1;
  s.emplace(0);
  FOR(i, 1, n) {
    while (p[s.top()] < p[i]) s.pop();
    lo[i] = s.top() + 1;
    s.emplace(i);
  }
  if (!s.empty()) {
    stack<int> tmp;
    swap(s, tmp);
  }
  s.emplace(n + 1);
  ROF(i, n, 1) {
    while (p[s.top()] < p[i]) s.pop();
    hi[i] = s.top() - 1;
    s.emplace(i);
  }
  FOR(i, 1, n) ans += get(lo[i], i, hi[i]);
  printf("%lld", ans);
}