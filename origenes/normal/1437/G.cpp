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

namespace Aho {
  const int maxn = 312345;

  struct Node {
    vector<int> nex;
    map<int, int> val;

    Node() {
      nex = vector<int>(26);
    }
  };

  vector<Node> trie(1);
  vector<int> f, link;
  int pos[maxn], score[maxn];

  int idx(char ch) {
    return ch - 'a';
  }

  void insert(string s, int id) {
    int u = 0, n = s.length();
    REP(i, n) {
      int c = idx(s[i]);
      if (!trie[u].nex[c]) {
        trie[u].nex[c] = trie.size();
        trie.eb();
      }
      u = trie[u].nex[c];
    }
    trie[u].val[0]++;
    pos[id] = u;
  }

  void get_fail() {
    queue<int> q;
    f = vector<int>(trie.size());
    link = vector<int>(trie.size());
    REP(c, 26) {
      int u = trie[0].nex[c];
      if (u) q.emplace(u);
    }
    while (!q.empty()) {
      auto u = q.front(); q.pop();
      REP(c, 26) if (trie[u].nex[c]) {
        int v = trie[u].nex[c];
        q.emplace(v);
        int j = f[u];
        while (j && !trie[j].nex[c]) j = f[j];
        f[v] = trie[j].nex[c];
        link[v] = trie[f[v]].val.empty() ? link[f[v]] : f[v];
      }
    }
  }

  void check(int j, int &ans) {
    if (j) {
      chkmax(ans, trie[j].val.rbegin()->_1);
      check(link[j], ans);
    }
  }

  void update(int i, int x) {
    int u = pos[i], px = score[i];
    if (!--trie[u].val[px]) trie[u].val.erase(px);
    trie[u].val[x]++;
    score[i] = x;
  }

  void query(string s) {
    int n = s.length(), j = 0, ans = -1;
    REP(i, n) {
      int c = idx(s[i]);
      while (j && !trie[j].nex[c]) j = f[j];
      j = trie[j].nex[c];
      if (!trie[j].val.empty()) check(j, ans);
      else if (link[j]) check(link[j], ans);
    }
    cout << ans << '\n';
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m;
  cin >> n >> m;
  FOR(i, 1, n) {
    string s;
    cin >> s;
    Aho::insert(s, i);
  }
  Aho::get_fail();
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i, x;
      cin >> i >> x;
      Aho::update(i, x);
    } else {
      string s;
      cin >> s;
      Aho::query(s);
    }
  }
}