#include <bits/stdc++.h>

using namespace std;

const int N = 500010, CHARACTER = 26;

int n, q;
char pool[N];
char *s[N], *curPointer;
int node[N];
vector <pair<int, int> > event[N];
int used[N];
int suf[N], nxt[N][CHARACTER], freeMem, cnt;
int in[N], out[N];
vector <int> adj[N];

int add(char *u) {
  int sz = strlen(u);
  int x = 0;
  for (int i = 0; i < sz; i++) {
    int val = u[i] - 'a';
    if (nxt[x][val] == -1) {
      nxt[x][val] = ++freeMem;
    }
    x = nxt[x][val];
  }
  return x;
}

void dfs(int u) {
  in[u] = ++cnt;
  for (int v : adj[u]) {
    dfs(v);
  }
  out[u] = cnt;
}

void buildSuf() {
  int q[N], top;
  top = 1;
  q[0] = 0;
  for (int i = 0; i < top; i++) {
    int u = q[i];
    for (int j = 0; j < CHARACTER; j++) {
      int v = suf[u] == -1 ? 0 : nxt[suf[u]][j];
      if (nxt[u][j] == -1) {
        nxt[u][j] = v;
      } else {
        suf[nxt[u][j]] = v;
        q[top++] = nxt[u][j];
      }
    }
  }
  for (int i = 1; i <= freeMem; i++) {
    adj[suf[i]].push_back(i);
  }
  dfs(0);
}

struct bit {
  int t[N];

  void add(int x, int v) {
    while (x < N) {
      t[x] += v;
      x += (x & -x);
    }
  }

  int get(int x) {
    int res = 0;
    while (x) {
      res += t[x];
      x -= (x & -x);
    }
    return res;
  }
} tree;

int res[N];

void push(int id) {
  int sz = strlen(s[id]);
  int x = 0;
  for (int i = 0; i < sz; i++) {
    x = nxt[x][s[id][i] - 'a'];
    tree.add(in[x], 1);
  }
}

int main() {
  curPointer = pool;
  memset(suf, -1, sizeof suf);
  memset(nxt, -1, sizeof nxt);
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%s", curPointer);
    int len = strlen(curPointer);
    s[i] = curPointer;
    curPointer += len + 1;
    node[i] = add(s[i]);
  }
  buildSuf();
  for (int i = 1; i <= q; i++) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    if (l > 1) {
      event[l - 1].push_back(make_pair(i, k));
    } else {
      used[i] = 1;
    }
    event[r].push_back(make_pair(i, k));
  }
  for (int i = 1; i <= n; i++) {
    push(i);
    for (pair<int, int> foo : event[i]) {
      int id = foo.second;
      int now = tree.get(out[node[id]]) - tree.get(in[node[id]] - 1);
      if (!used[foo.first]) {
        res[foo.first] -= now;
        used[foo.first] = 1;
      } else {
        res[foo.first] += now;
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    printf("%d\n", res[i]);
  }
  return 0;
}