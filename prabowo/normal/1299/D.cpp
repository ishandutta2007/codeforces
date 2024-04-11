#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int N = 100005;
const int L = 5;

int n, m;
int a[N], b[N], c[N];

vector<int> adj[N];

vector<vector<int>> _add;
int iadd(int &x, int y) {
  if (x == -1 || y == -1) return x = -1;
  return x = _add[x][y];
}

vector<unsigned int> basis;
void init() {
  basis = {0};
  vector<unsigned int> base = {0};
  map<unsigned int, int> baseId;
  baseId[0] = 0;
  for (int k = 0; k < L; ++k) {
    vector<unsigned int> nbase;
    for (int i = 0; i < base.size(); ++i) {
      for (int num = 1; num < 1 << L; ++num) {
        if (base[i] >> num & 1) continue;
        int nb = base[i];
        for (int j = 1; j < 1 << L; ++j) {
          if (base[i] >> j & 1) nb ^= 1 << (j ^ num);
        }
        nbase.push_back(nb ^ (1 << num));
      }
    }
    sort(nbase.begin(), nbase.end());
    nbase.erase(unique(nbase.begin(), nbase.end()), nbase.end());
    swap(base, nbase);
    for (int b : base) {
      baseId[b] = basis.size();
      basis.push_back(b);
    }
  }

  // for (int b : basis) cout << (bitset<1 << L>(b)) << endl;

  _add.assign(basis.size(), vector<int>(basis.size()));
  for (int i = 0; i < basis.size(); ++i) {
    for (int j = 0; j < basis.size(); ++j) {
      if (basis[i] & basis[j]) {
        _add[i][j] = -1;
        continue;
      }
      unsigned int sum = basis[i] | basis[j];
      for (int ii = 1; ii < 1 << L; ++ii) if (basis[i] >> ii & 1) {
        for (int jj = 1; jj < 1 << L; ++jj) if (basis[j] >> jj & 1) {
          sum ^= 1 << (ii ^ jj);
        }
      }
      _add[i][j] = baseId[sum];
    }
  }
}

int main() {
  init();

  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", &a[i], &b[i], &c[i]);
    --a[i], --b[i];
    adj[a[i]].push_back(i);
    adj[b[i]].push_back(i);
  }

  queue<int> q;
  vector<bool> vis(n), usedEdge(m);
  vector<int> root(n), sum(n), depth(n);
  vis[0] = true;

  auto visitNode = [&](int u, int i) {
    int v = a[i] ^ b[i] ^ u, w = c[i];
    if (vis[v]) return;
    vis[v] = true;
    sum[v] = sum[u] ^ w;
    depth[v] = depth[u] + 1;
    root[v] = root[u];
    q.push(v);
    usedEdge[i] = true;
  };

  int rootCnt = 0;
  for (int i : adj[0]) {
    visitNode(0, i);
    root[a[i] ^ b[i]] = rootCnt++;
  }

  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int j : adj[u]) {
      visitNode(u, j);
    }
  }

  vector<int> basis(rootCnt);
  vector<int> merged(rootCnt, -1);
  vector<int> cycle(rootCnt); // 0 means no cycle, -1 means cycle with cost 0

  for (int i = 0; i < m; ++i) {
    if (usedEdge[i]) continue;
    int u = a[i], v = b[i], w = c[i];
    int cycleBase = sum[u] ^ sum[v] ^ w;
    if (cycleBase == 0) cycleBase = -1;

    if (depth[u] == 1 && depth[v] == 1) {
      merged[root[v]] = root[u];
      iadd(basis[root[u]], basis[root[v]]);
      cycle[root[u]] = cycleBase;
    } else {
      int r = merged[root[u]] == -1 ? root[u] : merged[root[u]];
      iadd(basis[r], cycleBase);
    }
  }

  // cerr << rootCnt << endl;
  // for (int b : basis) cerr << bitset<1 << L>(b == -1 ? -1 : ::basis[b]) << endl;
  // for (int m : merged) cerr << m << " "; cerr << endl;
  // for (int c : cycle) cerr << c << " "; cerr << endl;

  vector<int> dp(_add.size(), 0);
  dp[0] = 1;

  for (int i = 0; i < rootCnt; ++i) {
    if (merged[i] != -1) continue;
    vector<int> ndp = dp;
    for (int j = 0; j < dp.size(); ++j) {
      int base = j;
      if (iadd(base, basis[i]) == -1) continue;
      ndp[base] = ((cycle[i] == 0 ? 1LL : 2LL) * dp[j] + ndp[base]) % MOD;
      if (cycle[i] == 0 || iadd(base, cycle[i]) == -1) continue;
      ndp[base] = (dp[j] + ndp[base]) % MOD;
    }
    swap(dp, ndp);
  }

  int ans = 0;
  for (int val : dp) {
    ans = (ans + val) % MOD;
  }

  printf("%d\n", ans);
  return 0;
}