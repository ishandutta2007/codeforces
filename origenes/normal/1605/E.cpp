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

int n, q;
int a[maxn], b[maxn], c[maxn], coeff[maxn];
ll pre[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) cin >> b[i];
  FOR(i, 2, n) c[i] = b[i] - a[i];
  coeff[1] = 1;
  FOR(i, 1, n) for (int j = i + i; j <= n; j += i) {
    coeff[j] -= coeff[i];
    c[j] -= c[i];
  }
  ll ans = 0;
  vector<int> v;
  FOR(i, 1, n) {
    if (coeff[i] == 0) ans += abs(c[i]);
    else v.eb(coeff[i] * c[i]);
  }
  sort(all(v));
  FOR(i, 1, int(v.size())) pre[i] = pre[i - 1] + v[i - 1];
  cin >> q;
  while (q--) {
    int x; cin >> x;
    x -= a[1];
    ll pos = lower_bound(all(v), -x) - v.begin();
    cout << ans - (pos * x + pre[pos]) + x * (int(v.size()) - pos) + pre[v.size()] - pre[pos] << '\n';
  }
}