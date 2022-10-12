#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MOD2 = 1004535809;

const int N = 100005;

const int LW = 17;
const int W = 1 << LW;

int n, m;

vector<int> edges[N];
vector<int> weights[N];

vector<vector<int>> cycs;

bool vis[N], vis2[N];
void dfs(int u, int p, vector<pair<int, int>> &ws) {
  vis[u] = true;
  vis2[u] = true;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    int w = weights[u][i];

    if (v == p) continue;
    if (vis[v]) {
      int cur = (int) ws.size() - 1;
      vector<int> cyc = {w};

      while (cur >= 0 && ws[cur].first != v) {
        cyc.push_back(ws[cur].second);
        --cur;
      }

      cyc.push_back(ws[cur].second);
      cycs.push_back(cyc);
      continue;
    }
    if (vis2[v]) continue;

    ws.emplace_back(u, w);
    dfs(v, u, ws);
    ws.pop_back();
  }
  vis[u] = false;
}

void fwht(int n, vector<int> &a, int mod) {
  for (int len = 1; len < n; len <<= 1) {
    for (int i = 0; i < n; i += len << 1) {
      for (int j = 0; j < len; ++j) {
        int u = a[i + j], v = a[i + j + len];
        a[i + j] = (u + v) % MOD;
        a[i + j + len] = (u - v) % MOD;
      }
    }
  }

}

int main() {
  scanf("%d %d", &n, &m);
  int costall = 0;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;

    edges[u].push_back(v);
    weights[u].push_back(w);

    edges[v].push_back(u);
    weights[v].push_back(w);

    costall ^= w;
  }

  vector<pair<int, int>> tmp;
  dfs(0, 0, tmp);

  vector<int> res1(W, 1), res2(W, 1);
  for (const vector<int> &cyc: cycs) {
    vector<int> a(W, 0);
    for (int w: cyc) a[w] += 1;

    vector<int> b = a;

    fwht(W, a, MOD);
    fwht(W, b, MOD2);

    for (int i = 0; i < W; ++i) {
      res1[i] = 1LL * res1[i] * a[i] % MOD;
      res2[i] = 1LL * res2[i] * b[i] % MOD2;
    }
  }


  fwht(W, res1, MOD); fwht(W, res2, MOD2);
  pair<int, int> ans = {W * 2, 0};

  // invese of W
  int inv = 742744451;
  for (int i = 0; i < W; ++i) {
    if (res1[i] == 0 && res2[i] == 0) continue;
    
    if ((costall ^ i) < ans.first) ans = {costall ^ i, 1LL * res1[i] * inv % MOD};
  }

  if (ans.second < 0) ans.second += MOD;
  printf("%d %d\n", ans.first, ans.second);
  return 0;
}