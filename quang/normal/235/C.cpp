#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, CHAR = 26;

char s[N];
char x[N];
int nxt[N * 2][CHAR], len[N * 2], suf[N * 2], freeMem, last, sz;
long long cnt[N * 2];

void add(int u) {
  int newNode = ++freeMem;
  len[newNode] = len[last] + 1;
  cnt[newNode] = 1;
  while (last != -1 && nxt[last][u] == -1) {
    nxt[last][u] = newNode;
    last = suf[last];
  }
  if (last == -1) {
    suf[newNode] = 0;
    last = newNode;
    return;
  }
  int q = nxt[last][u];
  if (len[q] == len[last] + 1) {
    suf[newNode] = q;
    last = newNode;
    return;
  }
  int clone = ++freeMem;
  len[clone] = len[last] + 1;
  for (int i = 0; i < CHAR; i++) {
    nxt[clone][i] = nxt[q][i];
  }
  while (last != -1 && nxt[last][u] == q) {
    nxt[last][u] = clone;
    last = suf[last];
  }
  suf[clone] = suf[q];
  suf[q] = suf[newNode] = clone;
  last = newNode;
}

int used[N * 2];

vector <int> adj[N * 2];

void dfs(int u) {
  for (int v : adj[u]) {
    dfs(v);
    cnt[u] += cnt[v];
  }
}

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%s", s + 1);
  sz = strlen(s + 1);
  memset(nxt, -1, sizeof nxt);
  memset(suf, -1, sizeof suf);
  for (int i = 1; i <= sz; i++) {
    add(s[i] - 'a');
  }
  for (int i = 1; i <= freeMem; i++) {
    adj[suf[i]].push_back(i);
  }
  dfs(0);
  int n;
  scanf("%d", &n);
  for (int ii = 1; ii <= n; ii++) {
    scanf("%s", x + 1);
    int l = strlen(x + 1);
    int cur = 0, res = 0, curLen = 0;
    for (int i = 1; i <= l; i++) {
      int u = x[i] - 'a';
      while (cur != -1  && nxt[cur][u] == -1) {
        cur = suf[cur];
        curLen = len[cur];
      }
      if (cur == -1) {
        cur = 0;
        curLen = 0;
      } else {
        cur = nxt[cur][u];
        curLen++;
      }
    }
    for (int i = 1; i <= l; i++) {
      int u = x[i] - 'a';
      while (cur != -1 && nxt[cur][u] == -1) {
        cur = suf[cur];
        curLen = len[cur];
      }
      if (cur == -1) {
        cur = 0;
        curLen = 0;
      } else {
        cur = nxt[cur][u];
        curLen++;
        while (suf[cur] != -1 && len[suf[cur]] >= l) {
          cur = suf[cur];
          curLen = len[cur];
        }
      }
      if (curLen >= l && used[cur] != ii) {
        used[cur] = ii;
        res += cnt[cur];
      }
    }
    printf("%d\n", res);
  }
  return 0;
}