#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, m;
char t[N], pool[N * 2];
char* curIt;
char *w[N];

struct node {
  int son[26];
  int id;
  node() {
    for (int i = 0; i < 26;i ++) {
      son[i] = -1;
    }
    id = -1;
  }
} a[N];
int totNode;

int dp[N];

int main() {
 // freopen("input.txt", "r", stdin);
  scanf("%d", &n);
  scanf("%s", t + 1);
  scanf("%d", &m);
  curIt = pool;
  for (int i = 1; i <= m; i++) {
    scanf("%s", curIt);
    w[i] = curIt;
    curIt += strlen(curIt) + 1;
    int x = 0;
    for (int j = 0; w[i][j]; j++) {
      int nxt = (w[i][j] <= 'Z') ? w[i][j] - 'A' : w[i][j] - 'a';
      if (a[x].son[nxt] == -1) {
        a[x].son[nxt] = ++totNode;
      }
      x = a[x].son[nxt];
    }
    a[x].id = i;
  }
  reverse(t + 1, t + n + 1);
  memset(dp, -1, sizeof dp);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    if (dp[i] == -1) {
      continue;
    }
    int x = 0;
    for (int j = i + 1; j <= n; j++) {
      int nxt = t[j] <= 'Z' ? t[j] - 'A' : t[j] - 'a';
      if (a[x].son[nxt] == -1) {
        break;
      }
      x = a[x].son[nxt];
      if (a[x].id != -1) {
        dp[j] = a[x].id;
      }
    }
  }
  while (n) {
    printf("%s ", w[dp[n]]);
    n -= strlen(w[dp[n]]);
  }
  return 0;
}