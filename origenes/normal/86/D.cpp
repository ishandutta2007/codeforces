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
const int maxa = 1123456;
const int S = 450;

int n, q;
int a[maxn], cnt[maxa];
ll ans[maxn];
vector<tuple<int, int, int, int>> query;
vector<pii> Q[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> q;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, q) {
    int l, r; cin >> l >> r;
    query.eb((l - 1) / S, r, l, i);
  }
  sort(all(query));
  int j = 0;
  REP(bid, (n - 1) / S + 1) {
    while (j < q && get<0>(query[j]) == bid) {
      auto [_, r, l, id] = query[j];
      Q[r].eb(l, id);
      j++;
    }
    ll now = 0;
    FOR(r, bid * S + 1, n) {
      now += ll(2 * cnt[a[r]] + 1) * a[r];
      cnt[a[r]]++;
      for (auto [l, id] : Q[r]) {
        FOR(i, bid * S + 1, l - 1) {
          now -= ll(2 * cnt[a[i]] - 1) * a[i];
          cnt[a[i]]--;
        }
        ans[id] = now;
        FOR(i, bid * S + 1, l - 1) {
          now += ll(2 * cnt[a[i]] + 1) * a[i];
          cnt[a[i]]++;
        }
      }
    }
    FOR(i, 1, n) {
      cnt[a[i]] = 0;
      Q[i].clear();
    }
  }
  FOR(i, 1, q) cout << ans[i] << '\n';
}