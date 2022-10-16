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

const int maxn = 3123;

int n, k;
ll f[maxn], ans;
vector<int> a[maxn];
vector<ll> s[maxn];

void solve(int l, int r) {
  if (l == r) {
    REP(i, min(int(s[l].size()), k + 1)) chkmax(ans, s[l][i] + f[i]);
    return;
  }
  vector<ll> pre(f, f + k + 1);
  int mi = l + r >> 1;
  FOR(i, l, mi) FOR(j, int(s[i].size()) - 1, k) chkmax(f[j - s[i].size() + 1], f[j] + s[i].back());
  solve(mi + 1, r);
  REP(i, k + 1) f[i] = pre[i];
  FOR(i, mi + 1, r) FOR(j, int(s[i].size()) - 1, k) chkmax(f[j - s[i].size() + 1], f[j] + s[i].back());
  solve(l, mi);
  REP(i, k + 1) f[i] = pre[i];
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  FOR(i, 1, n) {
    int t; cin >> t;
    a[i].resize(t + 1); s[i].resize(t + 1);
    FOR(j, 1, t) {
      cin >> a[i][j];
      s[i][j] = s[i][j - 1] + a[i][j];
    }
  }
  solve(1, n);
  cout << ans;
}