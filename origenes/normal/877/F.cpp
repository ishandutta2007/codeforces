#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

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

struct splitmix64_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

int n, q;
int t[maxn];
ll a[maxn], ans[maxn], k;
tuple<int, int, int, int> query[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  FOR(i, 1, n) cin >> t[i];
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) {
    if (t[i] == 2) a[i] = -a[i];
    a[i] = a[i - 1] + a[i];
  }
  cin >> q;
  FOR(i, 1, q) {
    int l, r;
    cin >> l >> r;
    query[i] = {(l - 1) / S, r, l - 1, i};
  }
  sort(query + 1, query + q + 1);
  int pl = 0, pr = 0;
  ll now = 0;
  hash_map<ll, int> cnt;
  cnt[a[0]]++;
  FOR(i, 1, q) {
    auto [_, r, l, id] = query[i];
    while (pl < l) {
      cnt[a[pl]]--;
      now -= cnt[a[pl] + k];
      pl++;
    }
    while (pl > l) {
      pl--;
      now += cnt[a[pl] + k];
      cnt[a[pl]]++;
    }
    while (pr < r) {
      pr++;
       now += cnt[a[pr] - k];
      cnt[a[pr]]++;
    }
    while (pr > r) {
      cnt[a[pr]]--;
      now -= cnt[a[pr] - k];
      pr--;
    }
    ans[id] = now;
  }
  FOR(i, 1, q) cout << ans[i] << '\n';
}