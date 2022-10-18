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

struct Node {
  vector<int> nxt;
  int idx;

  Node() : idx(0) {
    nxt = vector<int>(2);
  }
};

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), id(n + 1), f(n + 1), pre(n + 1);
  FOR(i, 1, n) cin >> a[i];
  iota(all(id), 0);
  sort(id.begin() + 1, id.end(), [&](int x, int y) { return a[x] < a[y]; });
  vector<Node> trie(2);
  FOR(i, 1, n) {
    int u = 1, best = 0;
    ROF(j, 29, 0) {
      if (u == 0) break;
      int bit = (a[id[i]] >> j) & 1, other = 1 - bit;
      if ((k >> j) & 1) u = trie[u].nxt[other];
      else {
        if (f[best] < f[trie[trie[u].nxt[other]].idx]) best = trie[trie[u].nxt[other]].idx;
        u = trie[u].nxt[bit];
      }
      if (j == 0 && f[best] < f[trie[u].idx]) best = trie[u].idx;
    }
    f[i] = f[best] + 1;
    pre[i] = best;
    u = 1;
    ROF(j, 29, 0) {
      int bit = (a[id[i]] >> j) & 1;
      if (trie[u].nxt[bit] == 0) {
        trie[u].nxt[bit] = size(trie);
        trie.eb();
      }
      u = trie[u].nxt[bit];
      if (f[trie[u].idx] < f[i]) trie[u].idx = i;
    }
  }
  int st = 0;
  FOR(i, 1, n) if (f[st] < f[i]) st = i;
  if (f[st] < 2) cout << -1;
  else {
    cout << f[st] << '\n';
    while (st) {
      cout << id[st] << ' ';
      st = pre[st];
    }
  }
}