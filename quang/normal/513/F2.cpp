#include <bits/stdc++.h>

using namespace std;

const int N = 25;
const int dirU[] = {0, 1, 0, -1};
const int dirV[] = {-1, 0, 1, 0};

int n, m, male, female;
int x[2][N * N], y[2][N * N], t[2][N * N], cnt[2];
char a[N][N];
long long h[2][N * N][N][N];
int used[N][N], cntUsed;
pair<int, int> q[N * N];
int top;

void bfs(int uu, int vv, int id, int r) {
  top = 1;
  cntUsed++;
  used[uu][vv] = cntUsed;
  q[0] = make_pair(uu, vv);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      h[id][r][i][j] = (1ll << 60);
    }
  }
  h[id][r][uu][vv] = 0;
  for (int i = 0; i < top; i++) {
    int u = q[i].first;
    int v = q[i].second;
    for (int j = 0; j < 4; j++) {
      int nu = u + dirU[j];
      int nv = v + dirV[j];
      if (nu < 1 || nu > n || nv < 1 || nv > m) {
        continue;
      }
      if (a[nu][nv] == '#' || used[nu][nv] >= cntUsed) {
        continue;
      }
      used[nu][nv] = cntUsed;
      h[id][r][nu][nv] = h[id][r][u][v] + t[id][r];
      q[top++] = make_pair(nu, nv);
    }
  }
}

int getId(int u, int v) {
  return m * (u - 1) + v + cnt[0] + cnt[1];
}

int getId1(int u, int v) {
  return getId(u, v) + n * m;
}

const int V = 1e6;

/*
    Complexity: O(V*E*log(MC)) (MC: max capacity)
    Tested: https://vn.spoj.com/problems/FFLOW/
*/

struct Flow {
    static const int INF = 1e9;
 
    int n, s, t;
    vector<vector<int>> adj;
    vector<int> d, cur;
    vector<int> to, c, f;
 
    Flow(int n, int s, int t) : n(n), s(s), t(t) {
        adj.assign(n, vector<int>());
        d.assign(n, -1);
        cur.assign(n, 0);
    }
 
    int addEdge(int u, int v, int _c) {
        adj[u].push_back(to.size()); 
        to.push_back(v); f.push_back(0); c.push_back(_c);
        adj[v].push_back(to.size());
        to.push_back(u); f.push_back(0); c.push_back(0);
        return (int)to.size() - 2;
    }
 
    bool bfs(int lim) {
        fill(d.begin(), d.end(), -1);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto edgeId : adj[u]) {
                int v = to[edgeId];
                if (d[v] == -1 && f[edgeId] + lim <= c[edgeId]) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[t] != -1;
    }
 
    int dfs(int u, int res) {
        if (u == t) return res;
        for (int &i = cur[u]; i < adj[u].size(); i++) {
            int edgeId = adj[u][i];
            int v = to[edgeId];
            if (d[v] == d[u] + 1 && f[edgeId] + res <= c[edgeId]) {
                int foo = dfs(v, min(res, c[edgeId] - f[edgeId]));
                if (foo) {
                    f[edgeId] += foo;
                    f[edgeId ^ 1] -= foo;
                    return foo;
                }
            }
        }
        return 0;
    }
 
    long long maxFlow() {
        long long res = 0;
        int lim = 1 << 30;
        while (lim >= 1) {
            if (!bfs(lim)) {
                lim >>= 1;
                continue;
            }
            fill(cur.begin(), cur.end(), 0);
            while (1) {
                int foo = dfs(s, lim);
                if (foo) res += lim;
                else break;
            }
        }
        return res;
    }
};

bool check(long long lim) {
  Flow f(getId1(n, m) + 2, 0, getId1(n, m) + 1);
  for (int i = 1; i <= cnt[0]; i++) {
    f.addEdge(f.s, i, 1);
    f.addEdge(i + cnt[0], f.t, 1);
  }
  for (int id = 1; id <= cnt[0]; id++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (h[0][id][i][j] <= lim) {
          f.addEdge(id, getId(i, j), 1);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f.addEdge(getId(i, j), getId1(i, j), 1);
    }
  }
  for (int id = 1; id <= cnt[1]; id++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (h[1][id][i][j] <= lim) {
          f.addEdge(getId1(i, j), id + cnt[0], 1);
        }
      }
    }
  }
  long long foo = f.maxFlow();
  return foo >= cnt[0];
}

int main() {
  scanf("%d %d %d %d", &n, &m, &male, &female);
  if (abs(male - female) != 1) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i] + 1);
  }
  if (male > female) {
    cnt[1]++;
    scanf("%d %d %d", x[1] + cnt[1], y[1] + cnt[1], t[1] + cnt[1]);
  } else {
    cnt[0]++;
    scanf("%d %d %d", x[0] + cnt[0], y[0] + cnt[0], t[0] + cnt[0]);
  }
  for (int i = 1; i <= male; i++) {
    cnt[0]++;
    scanf("%d %d %d", x[0] + cnt[0], y[0] + cnt[0], t[0] + cnt[0]);
  }
  for (int i = 1; i <= female; i++) {
    cnt[1]++;
    scanf("%d %d %d", x[1] + cnt[1], y[1] + cnt[1], t[1] + cnt[1]);
  }
  for (int i = 1; i <= cnt[0]; i++) {
    bfs(x[0][i], y[0][i], 0, i);
  }
  for (int i = 1; i <= cnt[1]; i++) {
    bfs(x[1][i], y[1][i], 1, i);
  }
  long long low = -1, high = 1e13;
  while (high - low > 1) {
    long long mid = (high + low) >> 1ll;
    if (check(mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  printf("%I64d", high >= 1e13 ? -1ll : high);
  return 0;
}