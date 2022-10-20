#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

template <class T> void maximize(T &u, const T &v) {if (u < v) u = v;}
template <class T> void minimize(T &u, const T &v) {if (u > v) u = v;}

int n;
vector <int> adj[N];
int a[N];
long long oneRoute[N][2], twoRoute[N][2];

void dfs(int u, int p) {
  oneRoute[u][1] = oneRoute[u][0] = a[u];
  long long maxVal = 0;
  for (int v : adj[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    long long curOneRoute[2], curTwoRoute[2];
    curOneRoute[0] = curOneRoute[1] = 0;
    curTwoRoute[0] = curTwoRoute[1] = 0;

    maximize(curTwoRoute[0], oneRoute[v][0] + max(maxVal, oneRoute[u][0]));
    maximize(curTwoRoute[1], oneRoute[v][0] + oneRoute[u][1]);

    maximize(curOneRoute[1], oneRoute[v][1] + a[u]);
    maximize(curTwoRoute[1], oneRoute[v][1] + a[u] + maxVal);
    maximize(curOneRoute[0], oneRoute[u][1] + oneRoute[v][1]);
    maximize(curTwoRoute[0], oneRoute[v][1] + twoRoute[u][1]);

    maximize(curTwoRoute[0], twoRoute[v][0]);

    maximize(curTwoRoute[1], twoRoute[v][1] + a[u]);
    maximize(curTwoRoute[0], twoRoute[v][1] + oneRoute[u][1]);

    maximize(maxVal, oneRoute[v][0]);
    maximize(oneRoute[u][0], curOneRoute[0]);
    maximize(oneRoute[u][1], curOneRoute[1]);
    maximize(twoRoute[u][0], curTwoRoute[0]);
    maximize(twoRoute[u][1], curTwoRoute[1]);
  }

  maximize(oneRoute[u][0], oneRoute[u][1]);
  maximize(oneRoute[u][0], maxVal);
  maximize(twoRoute[u][0], twoRoute[u][1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  long long res = 0;
  maximize(res, oneRoute[1][0]);
  maximize(res, twoRoute[1][0]);
  cout << res << endl;
  return 0;
}