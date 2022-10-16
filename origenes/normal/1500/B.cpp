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

ll exgcd(ll a, ll b, ll &x, ll &y) {
  ll g = a;
  x = 1, y = 0;
  if (b) g = exgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

ll inv(ll a, ll m) {
  ll x, y;
  exgcd(a, m, x, y);
  return (x + m) % m;
}

vector<int> ids[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m;
  ll k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  REP(i, n) cin >> a[i];
  REP(i, m) cin >> b[i];
  if (n < m) {
    swap(n, m);
    swap(a, b);
  }
  vector<int> occ(n, -1), pos(2 * n + 1, -1), skip(n, -1);
  REP(i, m) pos[b[i]] = i;
  REP(i, n) occ[i] = pos[a[i]];
  ll cyc = lcm(ll(m), ll(n)), d = gcd(m, n), cnt = 0;
  REP(i, n) {
    cnt += cyc / n;
    if (occ[i] != -1) {
      ll diff = i - occ[i];
      if (diff % d == 0) {
        ll x = m / d, y = n / d;
        diff /= d;
        skip[i] = diff * inv(x, y) % y;
        if (skip[i] < 0) skip[i] += y;
        cnt--;
      }
    }
  }
  ll ans = (k - 1) / cnt * cyc;
  k = (k - 1) % cnt + 1;
  REP(i, n) if (skip[i] != -1) ids[skip[i]].eb(i);
  REP(i, cyc / m) {
    if (k == 0) break;
    int cur = ids[i].size();
    if (k > m - cur) {
      k -= m - cur;
      ans += m;
      continue;
    }
    if (!ids[i].empty()) {
      int p = i * ll(m) % n, st = 0;
      if (ids[i].front() < p && ids[i].back() >= p) while (ids[i][st] < p) st++;
      int j = st;
      while (k && j < ids[i].size()) {
        if (ids[i][j] == p) j++;
        else k--;
        ans++, p = (p + 1) % n;
      }
      j = 0;
      while (k && j < st) {
        if (ids[i][j] == p) j++;
        else k--;
        ans++, p = (p + 1) % n;
      }
    }
    ans += k;
    break;
  }
  cout << ans;
}