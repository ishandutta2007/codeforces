#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;

int valid(int n, int d) { // O(log n)
  int sumDepth = 0;

  int cnt = 1;
  int depth = 0;

  while (n > 0) {
    if (n < cnt) {
      sumDepth == n * depth;
      n = 0;
      break;
    }
    sumDepth += cnt * depth;
    n -= cnt;
    cnt *= 2;
    depth++;
  }

  return sumDepth <= d && d <= n * (n - 1) / 2;
}

int adj[MAXN][2];
int depth[MAXN];
int par[MAXN];

int leftFree[MAXN];
int rightFree[MAXN];

void solve() {
  memset(adj, 0, sizeof(adj));
  memset(depth, 0, sizeof(depth));
  memset(par, 0, sizeof(par));
  int n, d;
  cin >> n >> d;
  
  depth[0] = 0;
  for (int i = 2; i <= n; i++) {
    adj[i / 2][i % 2] = i;
    par[i] = i / 2;
    depth[i] = depth[i / 2] + 1;
  }

  for (int i = 2; i <= n; i++) {
    // cout << depth[i] << " \n"[i == n];
    d -= depth[i];
  }

  if (d < 0) {
    cout << "NO\n";
    return;
  }

  while (d--) {
    memset(leftFree, 0, sizeof(leftFree));
    memset(rightFree, 0, sizeof(rightFree));
    for (int i = 1; i <= n; i++) {
      if (adj[i][0] == 0 && adj[i][1] == 0) {
        int p = par[i];
        if (i == adj[p][0]) {
          leftFree[depth[i]] = i;
        } else {
          rightFree[depth[i]] = i;
        }
      }
    }

    int done = 0;
    for (int i = 1; i <= n; i++) {
      if (adj[i][0] == 0) {
        if (leftFree[depth[i]] != 0 && i != leftFree[depth[i]]) {
          int oldP = par[leftFree[depth[i]]];
          adj[oldP][0] = 0;

          adj[i][0] = leftFree[depth[i]];
          depth[adj[i][0]] = depth[i] + 1;
          par[adj[i][0]] = i;
          
          done = 1;
        } else if (rightFree[depth[i]] != 0 && i != rightFree[depth[i]]) {
          int oldP = par[rightFree[depth[i]]];
          adj[oldP][1] = 0;

          adj[i][0] = rightFree[depth[i]];
          depth[adj[i][0]] = depth[i] + 1;
          par[adj[i][0]] = i;

          done = 1;
        }
      } else if (adj[i][1] == 0) {
        if (leftFree[depth[i]] != 0 && i != leftFree[depth[i]]) {
          int oldP = par[leftFree[depth[i]]];
          adj[oldP][0] = 0;

          adj[i][1] = leftFree[depth[i]];
          depth[adj[i][1]] = depth[i] + 1;
          par[adj[i][1]] = i;

          done = 1;
        } else if (rightFree[depth[i]] != 0 && i != rightFree[depth[i]]) {
          int oldP = par[rightFree[depth[i]]];
          adj[oldP][1] = 0;

          adj[i][1] = rightFree[depth[i]];
          depth[adj[i][1]] = depth[i] + 1;
          par[adj[i][1]] = i;

          done = 1;
        }
      }
      if (done) {
        break;
      }
    }

    if (!done) {
      cout << "NO\n";
      return;
    }

    // for (int i = 2; i <= n; i++) {
    //   cout << par[i] << " \n"[i == n];
    // }
  }
  
  cout << "YES\n";
  for (int i = 2; i <= n; i++) {
    cout << par[i] << " \n"[i == n];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve(); 
  }
}