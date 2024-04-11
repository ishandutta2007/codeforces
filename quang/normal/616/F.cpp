#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, CHARACTER = 26;

int n;
char pool[N], *curMem, *t[N];
int sz[N], cost[N];
int suf[N * 2], nxt[N * 2][CHARACTER], freeMem, last, len[N * 2];
long long val[N * 2];

int getNode(int last, int u) {
  int q = nxt[last][u];
  if (len[last] + 1 == len[q]) {
    return q;
  }
  int clone = ++freeMem;
  len[clone] = len[last] + 1;
  for (int i = 0; i < CHARACTER; i++) {
    nxt[clone][i] = nxt[q][i];
  }
  while (last != -1 && nxt[last][u] == q) {
    nxt[last][u] = clone;
    last = suf[last];
  }
  suf[clone] = suf[q];
  return suf[q] = clone;
}

void add(int u) {
  if (nxt[last][u] == -1) {
    int newNode = ++freeMem;
    len[newNode] = len[last] + 1;
    while (last != -1 && nxt[last][u] == -1) {
      nxt[last][u] = newNode;
      last = suf[last];
    }
    if (last == -1) {
      suf[newNode] = 0;
      last = newNode;
      return;
    }
    suf[newNode] = getNode(last, u);
    last = newNode;
  } else {
    last = getNode(last, u);
  }
}

vector <int> adj[N * 2];
long long dp[N * 2];
long long res = 0;

void dfs(int u) {
  dp[u] = val[u];
  for (int v : adj[u]) {
    dfs(v);
    dp[u] += dp[v];
  }
  res = max(res, dp[u] * len[u]);
}

int main() {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  scanf("%d", &n);
  curMem = pool;
  for (int i = 0; i < n; i++) {
    scanf("%s", curMem);
    t[i] = curMem;
    sz[i] = strlen(curMem);
    curMem += sz[i] + 1;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", cost + i);
  }
  memset(suf, -1, sizeof suf);
  memset(nxt, -1, sizeof nxt);
  for (int i = 0; i < n; i++) {
    last = 0;
    for (int j = 0; j < sz[i]; j++) {
      add(t[i][j] - 'a');
      val[last] += cost[i];
    }
  }
  for (int i = 1; i <= freeMem; i++) {
    adj[suf[i]].push_back(i);
  }
  dfs(0);
  cout << res << endl;

//  freopen("input.txt", "w", stdout);
//  cout << 100000 << endl;
//  for (int i = 1; i <= 100000; i++) {
//    cout << "aaaaa" << endl;
//  }
  return 0;
}