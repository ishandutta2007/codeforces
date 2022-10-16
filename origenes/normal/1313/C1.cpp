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

const int maxn = 512345;

int n, ans[maxn];
ll m[maxn], L[maxn], R[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", m + i);
  stack<pair<ll, int>> s;
  ll tot = 0;
  FOR(i, 1, n) {
    int cnt = 0;
    while (!s.empty() && s.top()._1 > m[i]) {
      tot -= s.top()._1 * s.top()._2;
      cnt += s.top()._2;
      s.pop();
    }
    L[i] = tot + cnt * m[i];
    cnt++;
    s.emplace(m[i], cnt);
    tot += cnt * m[i];
  }
  while (!s.empty()) s.pop();
  tot = 0;
  ROF(i, n, 1) {
    int cnt = 0;
    while (!s.empty() && s.top()._1 > m[i]) {
      tot -= s.top()._1 * s.top()._2;
      cnt += s.top()._2;
      s.pop();
    }
    R[i] = tot + cnt * m[i];
    cnt++;
    s.emplace(m[i], cnt);
    tot += cnt * m[i];
  }
  ll best = 0, peak = -1;
  FOR(i, 1, n) if (L[i] + m[i] + R[i] > best) {
    best = L[i] + m[i] + R[i];
    peak = i;
  }
  ans[peak] = m[peak];
  ll mx = m[peak];
  ROF(i, peak - 1, 1) {
    chkmin(mx, m[i]);
    ans[i] = mx;
  }
  mx = m[peak];
  FOR(i, peak + 1, n) {
    chkmin(mx, m[i]);
    ans[i] = mx;
  }
  FOR(i, 1, n) printf("%d ", ans[i]);
}