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

struct Trie {
  struct Node {
    vector<int> nxt, f;

    Node(): nxt(2, -1), f(2) {}
  };

  vector<Node> trie;

  Trie(): trie(1) {}

  int query(int v, int id) {
    int ret = 0, u = 0;
    ROF(i, 29, 0) {
      int d = ((v ^ id) >> i) & 1, ad = (v >> i) & 1;
      if (trie[u].nxt[1 - d] != -1) chkmax(ret, trie[trie[u].nxt[1 - d]].f[1 - ad]);
      if (trie[u].nxt[d] == -1) {
        trie[u].nxt[d] = size(trie);
        trie.eb();
      }
      u = trie[u].nxt[d];
    }
    return ret + 1;
  }

  void insert(int v, int id, int dp) {
    int u = 0;
    ROF(i, 29, 0) {
      int d = ((v ^ id) >> i) & 1, di = (id >> i) & 1;
      u = trie[u].nxt[d];
      chkmax(trie[u].f[di], dp);
    }
  }
};

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  int ans = 0;
  Trie t;
  REP(i, n) {
    int dp = t.query(a[i], i);
    chkmax(ans, dp);
    t.insert(a[i], i, dp);
  }
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}