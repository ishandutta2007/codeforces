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
const int S = 320;

int n, q, k;
int cnt[1 << 20], a[maxn];
ll ans[maxn];
tuple<int, int, int, int> qs[maxn];
vector<pii> query[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> q >> k;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) a[i] ^= a[i - 1];
  FOR(i, 1, q) {
    int l, r;
    cin >> l >> r;
    qs[i] = make_tuple((l - 1) / S, r, l - 1, i);
  }
  sort(qs + 1, qs + q + 1);
  int j = 1;
  REP(b, n / S + 1) {
    while (j <= q && get<0>(qs[j]) == b) {
      auto [_, r, l, id] = qs[j];
      query[r].eb(l, id);
      j++;
    }
    ll now = 0;
    FOR(r, b * S, n) {
      now += cnt[a[r] ^ k];
      cnt[a[r]]++;
      for (auto [l, id] : query[r]) {
        FOR(i, b * S, l - 1) {
          cnt[a[i]]--;
          now -= cnt[a[i] ^ k];
        }
        ans[id] = now;
        FOR(i, b * S, l - 1) {
          now += cnt[a[i] ^ k];
          cnt[a[i]]++;
        }
      }
    }
    FOR(r, b * S, n) {
      cnt[a[r]] = 0;
      query[r].clear();
    }
  }
  FOR(i, 1, q) cout << ans[i] << '\n';
}