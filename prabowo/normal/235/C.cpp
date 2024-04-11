#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

struct SAM {
  struct State {
    int len, link;
    int nxt[26];
    bool terminal;
  };
  int sz, lst;
  State states[N << 1];

  void sa_extend(int c) {
    int cur = sz++;
    states[cur].len = states[lst].len + 1;
    int p = lst;
    for (; p != -1 && !states[p].nxt[c]; p = states[p].link) {
      states[p].nxt[c] = cur;
    }
    if (p == -1) {
      states[cur].link = 0;
    } else {
      int q = states[p].nxt[c];
      if (states[p].len + 1 == states[q].len) {
        states[cur].link = q;
      } else {
        int clone = sz++;
        states[clone] = states[q];
        states[clone].len = states[p].len + 1;
        for (; p != -1 && states[p].nxt[c] == q; p = states[p].link) {
          states[p].nxt[c] = clone;
        }
        states[q].link = states[cur].link = clone;
      }
    }
    lst = cur;
  }

  void build(int n, char s[]) {
    states[0].len = 0;
    states[0].link = -1;
    sz = 1; lst = 0;

    for (int i = 0; i < n; ++i) sa_extend(s[i] - 'a');

    for (int cur = lst; cur != -1; cur = states[cur].link) {
      states[cur].terminal = true;
    }
  }
} sam;

// For computing occurences of substring in the machine
int cnt[N << 1];
int dfs(int u) {
  if (cnt[u] != -1) return cnt[u];
  cnt[u] = sam.states[u].terminal;
  for (int i = 0; i < 26; ++i) {
    int v = sam.states[u].nxt[i];
    if (v) cnt[u] += dfs(v);
  }
  return cnt[u];
}

char s[N];
int n;
char x[N << 1];

bool vis[N << 1];

int main() {
  scanf("%s", s);
  sam.build(strlen(s), s);

  memset(cnt, -1, sizeof cnt);
  dfs(0);

  scanf("%d", &n);
  while (n--) {
    scanf("%s", x);
    int len = strlen(x);
    for (int i = 0; i < len - 1; ++i) x[i + len] = x[i] -= 'a';
    x[len-1] -= 'a';

    int cur = 0, r = 0;
    vector<int> states;

    for (int l = 0; l < len; ++l) {
      if (cur > 0 && sam.states[sam.states[cur].link].len + 1 > r - l) cur = sam.states[cur].link;
      while (r - l < len && sam.states[cur].nxt[x[r]]) cur = sam.states[cur].nxt[x[r++]];
      if (r - l == len && !vis[cur]) {
        vis[cur] = true;
        states.push_back(cur);
      }
    }

    int ans = 0;
    for (int u: states) ans += cnt[u], vis[u] = false;
    printf("%d\n", ans);
  }
  return 0;
}