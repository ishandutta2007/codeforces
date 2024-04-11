#include <bits/stdc++.h>

using namespace std;

const int N = 600000, CHARACTER = 26;

int n;
char pool[N], *s[N], *curMem;
int sz[N], l[N], r[N];
int cnt[N][11];

//set last = 0 everytime we add new string
struct SuffixAutomaton {
    static const int N = 600000;
    static const int CHARACTER = 26;
    int suf[N * 2], nxt[N * 2][CHARACTER], freeMem, last, len[N * 2];

    SuffixAutomaton() {
        memset(suf, -1, sizeof suf);
        memset(nxt, -1, sizeof nxt);
        memset(len, 0, sizeof len);
        last = freeMem = 0;
    }

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
} sa;

long long res = 0;
vector <int> adj[N * 2];

void dfs(int u) {
  for (int v : adj[u]) {
    dfs(v);
    for (int i = 0; i <= n; i++) {
      cnt[u][i] += cnt[v][i];
    }
  }
  if (cnt[u][0] && u) {
    int f = 0;
    for (int i = 1; i <= n; i++) {
      f |= (l[i] > cnt[u][i] || r[i] < cnt[u][i]);
    }
    if (!f) {
      res += sa.len[u] - sa.len[sa.suf[u]];
    }
  }
}

int main() {
  //freopen("input.txt", "r", stdin);
  curMem = pool;
  scanf("%s", curMem);
  s[0] = curMem;
  sz[0] = strlen(curMem);
  curMem += sz[0] + 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s %d %d", curMem, l + i, r+ i);
    s[i] = curMem;
    sz[i] = strlen(curMem);
    curMem += sz[i] + 1;
  }
  for (int i = 0; i <= n; i++) {
    sa.last = 0;
    for (int j = 0; j < sz[i]; j++) {
      sa.add(s[i][j] - 'a');
      cnt[sa.last][i]++;
    }
  }
  for (int i = 1; i <= sa.freeMem; i++) {
    adj[sa.suf[i]].push_back(i);
  }
  dfs(0);
  cout << res << endl;
  return 0;
}