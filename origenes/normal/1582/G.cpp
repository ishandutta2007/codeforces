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

const int maxn = 1123456;

int n;
int a[maxn], vis[maxn], head[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, n) cin >> a[i];
  string s; cin >> s;
  FOR(i, 2, 1e6) if (!vis[i]) {
    vis[i] = i;
    for (int j = i + i; j <= 1e6; j += i) vis[j] = i;
  }
  ll ans = ll(n) * (n + 1) / 2;
  vector<map<int, int>> extras;
  map<int, int> need;
  REP(i, n) if (s[i] == '/' && a[i] != 1) {
    int now = a[i], j, st = i - 1, bad = 1;
    map<int, int> rem;
    while (true) {
      for (j = st; j >= 0 && (s[j] == '*' || a[j] == 1); j--) {
        if (s[j] == '/') {
          bad++;
          continue;
        }
        int cur = a[j];
        while (cur != 1) {
          rem[vis[cur]]++;
          cur /= vis[cur];
        }
        while (now != 1 && rem.count(vis[now])) {
          if (!--rem[vis[now]]) rem.erase(vis[now]);
          now /= vis[now];
        }
        if (now == 1) break;
        bad++;
      }
      if (now == 1 || j < 0) break;
      if (s[j] == '/') {
        st = head[j];
        if (!extras.empty()) {
          if (extras.back().size() > rem.size()) swap(rem, extras.back());
          for (auto [k, v] : extras.back()) rem[k] += v;
          extras.pop_back();
        }
        while (now != 1 && rem.count(vis[now])) {
          if (!--rem[vis[now]]) rem.erase(vis[now]);
          now /= vis[now];
        }
        if (now == 1) {
          j = st;
          break;
        }
        if (st >= 0) {
          st--;
          bad++;
        }
      }
    }
    head[i] = j;
    if (j >= 0) extras.eb(rem);
    ans -= ll(bad) * (n - i);
  }
  cout << ans;
}