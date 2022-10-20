#include <bits/stdc++.h>

#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 10010;

int n, vt, SufLen;
char s[N];
int pos[N], tmp[N], sa[N], lcp[N];

bool cmp(int u, int v) {
  if (pos[u] != pos[v]) {
    return pos[u] < pos[v];
  }
  u += SufLen;
  v += SufLen;
  if (u <= n && v <= n) {
    return pos[u] < pos[v];
  }
  return u > v;
}

int main() {
  //ios_base::sync_with_stdio(0);
 // fi, fo;
  scanf("%s", s + 1);
  vt = strlen(s + 1);
  s[vt + 1] = 'Q';
  scanf("%s", s + vt + 2);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    sa[i] = i;
    pos[i] = s[i];
  }
  SufLen = tmp[1] = 1;
  while (1) {
    sort (sa + 1, sa + n + 1, cmp);
    for (int i = 2; i <= n; i++) {
      tmp[i] = tmp[i - 1] + cmp(sa[i - 1], sa[i]);
    }
    for (int i = 1; i <= n; i++) {
      pos[sa[i]] = tmp[i];
    }
    if (tmp[n] == n) {
      break;
    }
    SufLen *= 2;
  }
  SufLen = 0;
  for (int i = 1; i <= n; i++) {
    if (pos[i] == n) {
      continue;
    }
    int k = sa[pos[i] + 1];
    while (s[i + SufLen] == s[k + SufLen]) {
      SufLen++;
    }
    lcp[pos[i]] = SufLen;
    if (SufLen) {
      SufLen--;
    }
  }
  int res = -1;
  for (int i = 1; i < n; i++) {
    if (!lcp[i] || lcp[i] <= lcp[i + 1] || lcp[i] <= lcp[i - 1]) {
      continue;
    }
    if ((sa[i] <= vt) ^ (sa[i + 1] <= vt) == 0) {
      continue;
    }
    int gtmax = max (lcp[i - 1], lcp[i + 1]) + 1;
    if (res == -1 || res > gtmax) {
      res = gtmax;
    }
  }
  cout << res;
  return 0;
}