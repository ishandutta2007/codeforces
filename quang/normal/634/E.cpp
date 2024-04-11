#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

template <class T> void maximize(T &u, const T &v) { if (u < v) u = v;}

int n, k;
vector <int> adj[N];
int a[N], b[N], good[N], dp[N];
int numChild[N], f[N];

void dfs(int u, int p) {
  int sum = 0, maxVal = 0;
  numChild[u] = 1;
  for (int v : adj[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    numChild[u] += numChild[v];
    if (f[v] == numChild[v]) {
      sum += f[v];
    } else {
      maximize(maxVal, f[v]);
    }
  }
  f[u] = sum + maxVal + 1;
  if (!good[u]) {
    f[u] = 0;
  }
}

void reDfs(int u, int p, int up) {
  int sum = 0, maxVal = 0;
  vector <int> child;
  for (int v : adj[u]) {
    if (v == p) {
      continue;
    }
    child.push_back(v);
    if (f[v] == numChild[v]) {
      sum += f[v];
    } else {
      maximize(maxVal, f[v]);
    }
  }
  if (n - numChild[u] == up) {
    sum += up;
  } else {
    maximize(maxVal, up);
  }
  dp[u] = sum + maxVal + 1;
  if (!good[u]) {
    dp[u] = 0;
  }
  int sz = child.size();
  vector <pair<int, int> > sufDp(sz + 1);
  vector <pair<int, int> > preDp(sz + 1);
  preDp[0] = sufDp[sz] = make_pair(0, 0);
  for (int i = 0; i < sz; i++) {
    int v = child[i];
    preDp[i + 1] = preDp[i];
    if (f[v] == numChild[v]) {
      preDp[i + 1].first += f[v];
    } else {
      maximize(preDp[i + 1].second, f[v]);
    }
  }
  for (int i = sz - 1; i >= 0; i--) {
    int v = child[i];
    sufDp[i] = sufDp[i + 1];
    if (f[v] == numChild[v]) {
      sufDp[i].first += f[v];
    } else {
      maximize(sufDp[i].second, f[v]);
    }
  }
  for (int i = 0; i < sz; i++) {
    int v = child[i];
    pair<int, int> cur = make_pair(0, 0);
    cur.first = preDp[i].first + sufDp[i + 1].first;
    cur.second = max(preDp[i].second, sufDp[i + 1].second);
    if (up == n - numChild[u]) {
      cur.first += up;
    } else {
      maximize(cur.second, up);
    }
    int nxtUp = cur.first + cur.second + 1;
    if (!good[u]) {
      nxtUp = 0;
    }
    reDfs(v, u, nxtUp);
  }
}

bool check(int u) {
  for (int i = 1; i <= n; i++) {
    good[i] = (a[i] >= u);
  }
  dfs(1, 0);
  reDfs(1, 0, 0);
  for (int i = 1; i <= n; i++) {
    if (dp[i] >= k) {
      return 1;
    }
  }
  return 0;
}

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    b[i] = a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int l = 0, r = 1000010;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (check(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}