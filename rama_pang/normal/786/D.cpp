#include <bits/stdc++.h>
using namespace std;

template<int MOD>
class ModInt {
 public:
  int v;

  ModInt() : v(0) {}
  ModInt(long long _v) {
    v = int((-MOD < _v && _v < MOD) ? (_v) : (_v % MOD));
    if (v < 0) v += MOD; }

  friend bool operator==(const ModInt &a, const ModInt &b) { return a.v == b.v; }
  friend bool operator!=(const ModInt &a, const ModInt &b) { return a.v != b.v; }
  friend bool operator<(const ModInt &a, const ModInt &b) { return a.v < b.v; }
  friend bool operator<=(const ModInt &a, const ModInt &b) { return a.v <= b.v; }
  friend bool operator>(const ModInt &a, const ModInt &b) { return a.v > b.v; }
  friend bool operator>=(const ModInt &a, const ModInt &b) { return a.v >= b.v; }

  ModInt& operator+=(const ModInt &a) {
    if ((v += a.v) >= MOD) v -= MOD;
    return *this; }
  ModInt& operator-=(const ModInt &a) {
    if ((v -= a.v) < 0) v += MOD;
    return *this; }
  ModInt& operator*=(const ModInt &a) {
    v = 1ll * v * a.v % MOD;
    return *this; }
  ModInt& operator/=(const ModInt &a) {
    return (*this) *= inverse(a); }

  friend ModInt pow(ModInt a, long long x) {
    ModInt res = 1; assert(x >= 0);
    for (; x; x /= 2, a *= a) if (x & 1) res *= a;
    return res; }
  friend ModInt inverse(ModInt a) {
    assert(a.v != 0);
    return pow(a, MOD - 2); }

  ModInt operator+() const { return ModInt(v); }
  ModInt operator-() const { return ModInt(-v); }
  ModInt operator++() const { return *this += 1; }
  ModInt operator--() const { return *this -= 1; }

  friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
  friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
  friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
  friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }

  friend istream& operator>>(istream &is, ModInt &v) { is >> v.v; return is; }
  friend ostream& operator<<(ostream &os, const ModInt &v) { os << v.v; return os; }
};

const int MOD = 1e9 + 993;
using Mint = ModInt<MOD>;

const int KEY = 67;
const int INVKEY = (Mint(1) / Mint(KEY)).v;

const int MAX = 20005;
const int LOG = 15;
const int ALP = 30;

Mint power_key[MAX];
Mint inverse_key[MAX];

void InitKey() {
  power_key[0] = inverse_key[0] = 1;
  for (int i = 1; i < MAX; i++) {
    power_key[i] = KEY * power_key[i - 1];
    inverse_key[i] = INVKEY * inverse_key[i - 1];
  }
}

int N, Q;
int ans[MAX];

vector<pair<int, int>> adj[MAX];

int depth[MAX];
int parent[LOG][MAX];
int parentLetter[MAX];

Mint hashUp[MAX];
Mint hashDown[MAX];

void dfsBuildHash(int u, int p, int c) {
  depth[u] = depth[p] + 1;
  parentLetter[u] = c;

  parent[0][u] = p;
  for (int j = 1; j < LOG; j++) parent[j][u] = parent[j - 1][parent[j - 1][u]];

  hashUp[u] = c + power_key[1] * hashUp[p];
  hashDown[u] = hashDown[p] + power_key[depth[u] - depth[1]] * c;

  for (auto [v, c] : adj[u]) if (v != p) {
    dfsBuildHash(v, u, c);
  }
}

int kthParent(int u, int k) {
  for (int i = 0; i < LOG; i++) {
    if ((k >> i) & 1) {
      u = parent[i][u];
    }
  }
  return u;
}

int lca(int u, int v) {
  int origu = u, origv = v;
  if (depth[u] > depth[v]) swap(u, v);
  v = kthParent(v, depth[v] - depth[u]);
  assert(depth[u] == depth[v]);

  for (int i = LOG - 1; i >= 0; i--) {
    if (parent[i][u] != parent[i][v]) {
      u = parent[i][u];
      v = parent[i][v];
    }
  }

  assert(parent[0][u] == parent[0][v]);
  return u == v ? u : parent[0][u];
}

int getKthNode(int u, int v, int k) { // u = 0
  int w = lca(u, v);
  if (depth[u] + depth[v] - 2 * depth[w] < k) return 0;
  if (depth[u] - depth[w] >= k) {
    return kthParent(u, k);
  } else {
    k -= depth[u] - depth[w]; // we are now at w
    return kthParent(v, (depth[v] - depth[w]) - k);
  }
}

int getKthLetter(int u, int v, int k) {
  int w = lca(u, v);
  if (k < 1 || depth[u] + depth[v] - 2 * depth[w] < k) return 0;
  if (depth[u] - depth[w] >= k) {
    return parentLetter[kthParent(u, k - 1)];
  } else {
    k -= depth[u] - depth[w]; // we are now at w
    return parentLetter[kthParent(v, (depth[v] - depth[w]) - k)];
  }
}

Mint getHash(int u, int v) {
  int w = lca(u, v);
  Mint up = hashUp[u] - power_key[depth[u] - depth[w]] * hashUp[w];
  Mint dn = inverse_key[depth[w] - depth[1] + 1] * (hashDown[v] - hashDown[w]);
  return up + power_key[depth[u] - depth[w]] * dn;
}

int dist(int u, int v) {
  int w = lca(u, v);
  return depth[u] + depth[v] - 2 * depth[w];
}

Mint getHash(int u, int v, int len) {
  if (dist(u, v) < len) return -1;
  return getHash(u, getKthNode(u, v, len));
}

int comparePath(pair<int, int> p1, pair<int, int> p2) {
  int d1 = dist(p1.first, p1.second);
  int d2 = dist(p2.first, p2.second);

  // if |p2| is a prefix of |p1|, return 0
  if (d2 <= d1 && getHash(p2.first, p2.second) == getHash(p1.first, p1.second, d2)) {
    return 0;
  }

  int lo = 0, hi = min(d1, d2);
  while (lo < hi) {
    int md = (lo + hi + 1) / 2;
    if (getHash(p1.first, p1.second, md) == getHash(p2.first, p2.second, md)) {
      lo = md;
    } else {
      hi = md - 1;
    }
  }

  int a = getKthLetter(p1.first, p1.second, lo + 1);
  int b = getKthLetter(p2.first, p2.second, lo + 1);

  assert(a != b);
  return a < b ? -1 : 1;
}

int siz[MAX];
int dead[MAX];
vector<pair<int, int>> query[MAX];

int getCentroid(int u) {
  const auto dfs = [&](const auto &self, int u, int p) -> void {
    siz[u] = 1;
    for (auto [v, _] : adj[u]) if (!dead[v] && v != p) {
      self(self, v, u);
      siz[u] += siz[v];
    }
  };
  dfs(dfs, u, 0);
  int s = siz[u];
  int p = 0;
  while (true) {
    pair<int, int> mx = {-1, -1};
    for (auto [v, _] : adj[u]) if (!dead[v] && v != p) {
      mx = max(mx, {siz[v], v});
    }
    if (mx.first * 2 <= s) {
      return u;
    }
    p = u;
    u = mx.second;
  }
  return 0;
}

vector<int> subtree[MAX];

void getSubtree(int u, int p, vector<int> &res) {
  res.emplace_back(u);
  for (auto [v, _] : adj[u]) if (!dead[v] && v != p) {
    getSubtree(v, u, res);
  }
}

vector<array<int, 4>> current_query[MAX]; // (from, to, query index, sign)

int trie_size;
int trie[MAX][ALP]; // note: 1 is root
int trie_subtree[MAX]; // subtree size in trie
int less_than_current[MAX];

Mint hash_of_pos_in_trie[MAX];
map<int, int> pos_of_hash_in_trie;

int newNode() {
  trie_size++;
  trie_subtree[trie_size] = 0;
  less_than_current[trie_size] = 0;
  for (int i = 0; i < ALP; i++) {
    trie[trie_size][i] = 0;
  }
  return trie_size;
}

void clearTrie() {
  trie_size = 0;
  pos_of_hash_in_trie.clear();
  newNode();
}

int trieNext(int node, int c) {
  if (!trie[node][c]) {
    trie[node][c] = newNode();
  }
  return trie[node][c];
}

void initTrie(int u, int p, int trie_node) {
  trie_subtree[trie_node] += 1;
  for (auto [v, c] : adj[u]) if (!dead[v] && v != p) {
    initTrie(v, u, trieNext(trie_node, c));
  }
}

void buildTrie() {
  const auto dfs = [&](const auto &self, int u, int d, Mint current_hash) -> void {
    hash_of_pos_in_trie[u] = current_hash;
    pos_of_hash_in_trie[current_hash.v] = u;
    for (int i = 0; i < ALP; i++) if (trie[u][i]) {
      self(self, trie[u][i], d + 1, current_hash + power_key[d] * i);
      trie_subtree[u] += trie_subtree[trie[u][i]];
    }
  };

  dfs(dfs, 1, 0, 0);

  for (queue<int> q({1}); !q.empty(); q.pop()) {
    int u = q.front();
    int sum = trie_subtree[u];
    for (int i = 0; i < ALP; i++) if (trie[u][i]) {
      sum -= trie_subtree[trie[u][i]];
    }
    for (int i = 0; i < ALP; i++) {
      int v = trie[u][i];
      if (!v) continue;
      q.emplace(v);
      less_than_current[v] += less_than_current[u];
      less_than_current[v] += sum;
      sum += trie_subtree[v];
    }
  }
}

int solveTrie(pair<int, int> path) {
  int lo = 0, hi = dist(path.first, path.second);
  while (lo < hi) {
    int md = (lo + hi + 1) / 2;
    if (pos_of_hash_in_trie.count(getHash(path.first, path.second, md).v)) {
      lo = md;
    } else {
      hi = md - 1;
    }
  }

  int nxtchar = getKthLetter(path.first, path.second, lo + 1);
  int node = pos_of_hash_in_trie[getHash(path.first, path.second, lo).v];
  assert(node != 0);
  assert(trie[node][nxtchar] == 0);

  int res = less_than_current[node];

  if (nxtchar != 0) { // string which end at current node
    res += trie_subtree[node];
    for (int i = 0; i < ALP; i++) if (trie[node][i]) {
      res -= trie_subtree[trie[node][i]];
    }
  }

  // extend to different next character
  for (int i = 0; i < nxtchar; i++) if (trie[node][i]) {
    res += trie_subtree[trie[node][i]];
  }

  return res;
}

void decompose(int cen) {
  cen = getCentroid(cen);

  subtree[cen].clear();
  current_query[cen].clear();
  for (auto [v, _] : adj[cen]) if (!dead[v]) {
    subtree[v].clear();
    current_query[v].clear();
  }

  getSubtree(cen, 0, subtree[cen]);
  for (auto [v, _] : adj[cen]) if (!dead[v]) {
    getSubtree(v, cen, subtree[v]);
  }

  for (auto q : query[cen]) {
    current_query[cen].push_back({cen, q.first, q.second, 1});
  }

  for (auto [v, _] : adj[cen]) if (!dead[v]) {
    for (auto x : subtree[v]) {
      for (auto q : query[x]) {
        int cmp = comparePath({x, q.first}, {x, cen});
        if (cmp == -1) {
          // no valid strings less than query() that passes through centroid
        } else if (cmp == +1) {
          // all strings that passes through centroid is less than query()
          ans[q.second] += int(subtree[cen].size()) - int(subtree[v].size());
        } else {
          // path to centroid is a prefix of query()
          current_query[cen].push_back({getKthNode(x, q.first, dist(x, cen)), q.first, q.second, 1});
          current_query[v].push_back({getKthNode(x, q.first, dist(x, cen)), q.first, q.second, -1}); // exclude from subtree
        }
      }
    }
  }

  {
    clearTrie();
    initTrie(cen, 0, 1);
    buildTrie();
    for (auto q : current_query[cen]) {
      ans[q[2]] += q[3] * solveTrie({q[0], q[1]});
    }
  }

  for (auto [v, c] : adj[cen]) if (!dead[v]) {
    clearTrie();
    initTrie(v, cen, trieNext(1, c));
    buildTrie();
    for (auto q : current_query[v]) {
      ans[q[2]] += q[3] * solveTrie({q[0], q[1]});
    }
  }

  dead[cen] = 1;
  for (auto [v, _] : adj[cen]) if (!dead[v]) decompose(v);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  InitKey();

  cin >> N >> Q;

  for (int i = 1; i < N; i++) {
    int u, v; char c;
    cin >> u >> v >> c;
    adj[u].emplace_back(v, c - 'a' + 1);
    adj[v].emplace_back(u, c - 'a' + 1);
  }

  dfsBuildHash(1, 0, 0);

  for (int i = 0; i < Q; i++) {
    int x, y;
    cin >> x >> y;
    query[x].emplace_back(y, i);
  }

  decompose(1);

  for (int i = 0; i < Q; i++) {
    cout << ans[i] - 1 << '\n';
  }
  return 0;
}