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

const int maxa = 1123456;
const int maxn = 312345;

int n, q;
int vis[maxa], a[maxn];

void solve() {
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  map<int, int> cnt;
  FOR(i, 1, n) {
    int rem = 1;
    stack<int> s;
    while (a[i] != 1) {
      if (s.empty() || vis[a[i]] != s.top()) s.emplace(vis[a[i]]);
      else s.pop();
      a[i] /= vis[a[i]];
    }
    while (!s.empty()) {
      auto x = s.top(); s.pop();
      rem *= x;
    }
    cnt[rem]++;
  }
  int ans0 = 0, ans1 = 0, s1 = 0;
  for (auto [x, c] : cnt) chkmax(ans0, c);
  for (auto [x, c] : cnt) {
    if (x == 1 || c % 2 == 0) s1 += c;
    else chkmax(ans1, c);
  }
  cin >> q;
  while (q--) {
    ll w; cin >> w;
    cout << (w ? max(ans1, s1) : ans0) << '\n';
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  FOR(i, 2, 1e6) if (!vis[i]) for (int j = i; j <= 1e6; j += i) vis[j] = i;
  int T; cin >> T;
  while (T--) solve();
}