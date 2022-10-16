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
    vector<int> nxt;

    Node() {
      nxt = vector<int>(2, -1);
    }
  };

  vector<Node> trie;

  Trie() {
    trie = vector<Node>(1);
  }

  void insert(int x) {
    int u = 0;
    ROF(i, 16, 0) {
      int op = (x >> i) & 1;
      if (trie[u].nxt[op] == -1) {
        trie[u].nxt[op] = size(trie);
        trie.eb();
      }
      u = trie[u].nxt[op];
    }
  }

  int get_mn(int mask) {
    int u = 0, ret = 0;
    ROF(i, 16, 0) {
      int op = (mask >> i) & 1;
      if (trie[u].nxt[op] == -1) {
        u = trie[u].nxt[1 - op];
        ret |= 1 << i;
      } else u = trie[u].nxt[op];
    }
    return ret;
  }

  int get_mx(int mask) {
    int u = 0, ret = 0;
    ROF(i, 16, 0) {
      int op = (mask >> i) & 1;
      if (trie[u].nxt[1 - op] == -1) u = trie[u].nxt[op];
      else {
        u = trie[u].nxt[1 - op];
        ret |= 1 << i;
      }
    }
    return ret;
  }
};

void solve() {
  int l, r; cin >> l >> r;
  vector<int> candidates;
  Trie t;
  FOR(i, l, r) {
    int a; cin >> a;
    t.insert(a);
    candidates.eb(a ^ l);
  }
  sort(all(candidates)); uni(candidates);
  for (auto x : candidates) {
    int mn = t.get_mn(x), mx = t.get_mx(x);
    if (mn == l && mx == r) {
      cout << x << '\n';
      return;
    }
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