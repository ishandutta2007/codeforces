#include <bits/stdc++.h>

using namespace std;

const int N = 12;
const int dirX[] = {0, -1, 0, 1};
const int dirY[] = {1, 0, -1, 0};

int n, t;
char a[N][N], b[N][N];
int used[N][N], cnt;
int h[N][N];
pair<int, int>  q[N * N];
int top;
bool dp[N][N][N][N];

void bfsFindTime(int xx, int yy) {
  top = 1;
  q[0] = make_pair(xx, yy);
  h[xx][yy] = 0;
  used[xx][yy] = cnt;
  for (int i=  0; i < top; i++) {
    int x= q[i].first;
    int y = q[i].second;
    for (int j = 0; j < 4; j++) {
      int nx = x + dirX[j];
      int ny = y + dirY[j];
      if (nx < 1 || nx > n || ny < 1 || ny > n) {
        continue;
      }
      if (used[nx][ny] >= cnt || a[nx][ny] == 'Y') {
        continue;
      }
      h[nx][ny] = h[x][y] + 1;
      q[top++] = make_pair(nx, ny);
      used[nx][ny] = cnt;
    }
  }
}

int hh[N][N];

void bfs(int ru, int rv, int now) {
  top = 1;
  dp[ru][rv][ru][rv] = 1;
  q[0] = make_pair(ru, rv);
  used[ru][rv] = cnt;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      hh[i][j] = 2e9;
    }
  }
  hh[ru][rv] = 0;
  for (int i=  0; i < top; i++) {
    int x = q[i].first;
    int y = q[i].second;
    for (int j = 0; j < 4; j++) {
      int nx = x + dirX[j];
      int ny = y + dirY[j];
      if (nx < 1 || nx > n || ny < 1 || ny > n) {
        continue;
      }
      if (used[nx][ny] >= cnt || a[nx][ny] == 'Y' || a[nx][ny] == 'Z') {
        continue;
      }
      hh[nx][ny] = hh[x][y] + 1;
      if (hh[nx][ny] > t) {
        continue;
      }
      if (hh[nx][ny] > h[nx][ny]) {
        continue;
      }
      dp[ru][rv][nx][ny] = 1;
      if (hh[nx][ny] == h[nx][ny]) {
        continue;
      }
      q[top++] = make_pair(nx, ny);
      used[nx][ny] = cnt;
    }
  }
}

void getDp() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 'Z' || a[i][j] == 'Y') {
        continue;
      }
      cnt++;
      bfs(i, j, 0);
    }
  }
}

void pre() {
  int posx, posy;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 'Z') {
        posx = i;
        posy = j;
        break;
      }
    }
  }
  cnt++;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      h[i][j] = 1e9;
    }
  }
  bfsFindTime(posx, posy);
  getDp();
}

const int V = 1e5;
const int INF = 1e9;

/*
    Complexity: O(V^2 * E)
*/

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

int main() {
  scanf("%d %d", &n, &t);
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%s", b[i] + 1);
  }
  Flow f(n * n * 2 + 2, 0, n * n * 2 + 1);
  int pos[N][N];
  memset(pos, -1, sizeof pos);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 'Z' || a[i][j] == 'Y' || a[i][j] == '0') {
        continue;
      }
      pos[i][j] = f.addEdge(f.s, n * (i - 1) + j, a[i][j] - '0');
    }
  }
  int pos2[N][N];
  memset(pos2, -1, sizeof pos2);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (b[i][j] == 'Z' || b[i][j] == 'Y' || b[i][j] == '0') {
        continue;
      }
      pos2[i][j]  = f.addEdge(n * (i - 1) + j + n * n, f.t, b[i][j] - '0');
    }
  }
  pre();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 'Z' || a[i][j] == 'Y' || a[i][j] == '0') {
        continue;
      }
      for (int ii = 1; ii <= n; ii++) {
        for (int jj = 1; jj <= n; jj++) {
          if (b[ii][jj] == 'Z' || b[ii][jj] == 'Y' || b[ii][jj] == '0') {
            continue;
          }
          if (!dp[i][j][ii][jj]) {
            continue;
          }
          f.addEdge(n * (i - 1) + j, n * (ii - 1) + jj + n * n, 2e9);
        }
      }
    }
  }
//  cout << dp[1][2][5][5] << endl;
  cout << f.maxFlow() << endl;
//  for (int i = 1; i <= n; i++) {
//    for (int j = 1; j <= n; j++) {
//      if (pos[i][j] != -1 && f.f[pos[i][j]] > 0) {
//        cout << i << " " << j << endl;
//      }
//    }
//  }
//  cout << endl;
//  for (int i = 1; i <= n; i++) {
//    for (int j = 1; j <= n; j++) {
//      if (pos2[i][j] != -1 ) {
//        cout << i << " " << j << " " << f.f[pos2[i][j]] << endl;
//      }
//    }
//  }
  return 0;
}