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

const int maxn = 412345;

int trie[maxn][26], f[maxn], en[maxn], cnt[maxn], tail[maxn], ans[maxn];
int n, m, tot;
vector<int> G[maxn];
vector<pii> query[maxn];
char s[maxn];
bool vis[maxn];

void insert(const string &t, int id) {
  int now = 0;
  for (auto ch : t) {
    int idx = ch - 'a';
    if (!trie[now][idx]) trie[now][idx] = ++tot;
    now = trie[now][idx];
  }
  en[now] = id;
}

void get_fail() {
  queue<int> q;
  q.emplace(0);
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    REP(i, 26) if (trie[u][i]) {
      int v = trie[u][i];
      q.emplace(v);
      if (!u) continue;
      f[v] = f[u];
      while (f[v] && !trie[f[v]][i]) f[v] = f[f[v]];
      f[v] = trie[f[v]][i];
      tail[v] = en[f[v]] ? f[v] : tail[f[v]];
    }
  }
}

void add(int i, int d) {
  for (; i > 0; i = tail[i]) cnt[en[i]] += d;
}

void dfs(int u, int i) {
  while (i && !trie[i][s[u] - 'a']) i = f[i];
  i = trie[i][s[u] - 'a'];
  add(i, 1);
  for (auto q : query[u]) ans[q._1] = cnt[q._2];
  for (auto v : G[u]) dfs(v, i);
  add(i, -1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  FOR(i, 1, n) {
    int op;
    cin >> op;
    if (op == 1) {
      cin >> s[i];
    } else {
      int j;
      cin >> j >> s[i];
      G[j].eb(i);
      vis[i] = true;
    }
  }
  map<string, int> mmap;
  cin >> m;
  FOR(i, 1, m) {
    int j;
    string t;
    cin >> j >> t;
    if (!mmap.count(t)) {
      int now = mmap.size() + 1;
      mmap[t] = now;
    }
    insert(t, mmap[t]);
    query[j].eb(i, mmap[t]);
  }
  get_fail();
  FOR(i, 1, n) if (!vis[i]) dfs(i, 0);
  FOR(i, 1, m) cout << ans[i] << '\n';
}