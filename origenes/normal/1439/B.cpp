#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

typedef long long ll;
typedef std::pair<int, int> pii;
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

int n, m, k;
int deg[maxn];
bool vis[maxn];

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

template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

void solve() {
  using namespace std;
  cin >> n >> m >> k;
  vector<hash_set<int>> G(n);
  REP(i, n) {
    G[i].clear();
    deg[i] = 0;
    vis[i] = false;
  }
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].insert(v);
    G[v].insert(u);
    deg[u]++;
    deg[v]++;
  }
  auto check = [&](int u) -> vector<int> {
    vector<int> ret = {u};
    for (auto v : G[u]) if (!vis[v]) ret.eb(v);
    FOR(i, 1, k - 1) FOR(j, i + 1, k - 1) if (G[ret[i]].find(ret[j]) == G[ret[i]].end()) return {};
    return ret;
  };
  set<pii> s;
  REP(i, n) s.emplace(deg[i], i);
  while (!s.empty()) {
    auto u = s.begin()->_2;
    if (deg[u] == k) {
      cout << 1 << ' ' << s.size() << '\n';
      for (auto [_, v] : s) cout << v + 1 << ' ';
      cout << '\n';
      return;
    }
    if (deg[u] == k - 1) {
      auto clique = check(u);
      if (!clique.empty()) {
        cout << "2\n";
        for (auto v : clique) cout << v + 1 << ' ';
        cout << '\n';
        return;
      }
    }
    vis[u] = true;
    s.erase(s.begin());
    for (auto v : G[u]) if (!vis[v]) {
      s.erase(mp(deg[v], v));
      s.emplace(--deg[v], v);
    }
  }
  cout << "-1\n";
}

int main() {
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
#endif
  int T; std::cin >> T;
  while (T--) solve();
}