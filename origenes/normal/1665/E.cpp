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

int a[maxn];

struct Trie {
  struct Node {
    vector<int> nxt, ids;

    Node() {
      nxt = vector<int>(2, -1);
    }
  };

  vector<Node> trie;

  Trie() {
    trie = vector<Node>(1);
  }

  void insert(int x, int pos) {
    int u = 0;
    ROF(i, 29, 0) {
      int op = (x >> i) & 1;
      if (trie[u].nxt[op] == -1) {
        trie[u].nxt[op] = size(trie);
        trie.eb();
      }
      u = trie[u].nxt[op];
      trie[u].ids.eb(pos);
    }
  }

  int query(int l, int r) {
    int u = 0;
    vector<int> candidates;
    ROF(i, 29, 0) {
      int v = trie[u].nxt[0], zero = 0;
      if (v != -1) {
        auto it1 = lower_bound(all(trie[v].ids), l);
        auto it2 = lower_bound(all(trie[v].ids), r + 1);
        if (it2 - it1 >= 2) zero = 1;
        else if (it1 + 1 == it2) candidates.eb(*it1);
      }
      if (zero) u = v;
      else {
        u = trie[u].nxt[1];
        if (u == -1) break;
      }
    }
    if (u != -1) {
      auto it1 = lower_bound(all(trie[u].ids), l);
      auto it2 = lower_bound(all(trie[u].ids), r + 1);
      int cnt = 0;
      for (auto it = it1; it != it2 && cnt < 2; ++it) {
        candidates.eb(*it);
        cnt++;
      }
    }
    int ans = 1 << 30;
    REP(i, size(candidates)) FOR(j, i + 1, size(candidates) - 1) chkmin(ans, a[candidates[i]] | a[candidates[j]]);
    return ans;
  }
};

void solve() {
  int n; cin >> n;
  FOR(i, 1, n) cin >> a[i];
  Trie t;
  FOR(i, 1, n) t.insert(a[i], i);
  int q; cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << t.query(l, r) << '\n';
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}