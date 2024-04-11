#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 200005;
int n, q, c[N];
vector<int> to[N];
int s[N << 1];

void add(int x, int v) {
  while (x <= n + q)
    s[x] += v, x += x & (-x);
}
int query(int x) {
  int ans = 0;
  while (x)
    ans += s[x], x &= x - 1;
  return ans;
}

void init() {
  static int d[N];
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    to[x].push_back(y), to[y].push_back(x);
    d[x]++, d[y]++;
  }

  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = 1; i <= n; i++)
    if (d[i] == 1)
      q.push(i);
  for (int t = 1; t <= n; t++) {
    int x = q.top();
    q.pop();
    c[x] = t, add(x, 1);
    for (int y : to[x]) {
      d[y]--;
      if (d[y] == 1)
        q.push(y);
    }
  }
}

namespace lct {
int ch[N][2], fa[N], sz[N];
bool r[N];

void update(int i) { sz[i] = sz[ch[i][0]] + 1 + sz[ch[i][1]]; }
bool isr(int i) { return ch[fa[i]][0] != i && ch[fa[i]][1] != i; }
bool getch(int i) { return ch[fa[i]][1] == i; }
void pushdown(int i) {
  if (r[i]) {
    swap(ch[i][0], ch[i][1]), r[i] = 0;
    if (ch[i][0])
      r[ch[i][0]] ^= 1;
    if (ch[i][1])
      r[ch[i][1]] ^= 1;
  }
  if (ch[i][0])
    c[ch[i][0]] = c[i];
  if (ch[i][1])
    c[ch[i][1]] = c[i];
}

void rotate(int i) {
  int f = fa[i], g = fa[f];
  bool fs = getch(i), gs = getch(f), r = isr(f);
  if (ch[i][fs ^ 1])
    fa[ch[i][fs ^ 1]] = f;
  ch[f][fs] = ch[i][fs ^ 1];
  ch[i][fs ^ 1] = f, fa[f] = i;
  fa[i] = g;
  if (!r)
    ch[g][gs] = i;
  update(f), update(i);
}

void splay(int i) {
  static int st[N];
  int top = 1, x = i;
  st[1] = x;
  while (!isr(x))
    st[++top] = x = fa[x];
  while (top)
    pushdown(st[top--]);
  while (!isr(i)) {
    if (!isr(fa[i])) {
      if (getch(i) == getch(fa[i]))
        rotate(fa[i]);
      else
        rotate(i);
    }
    rotate(i);
  }
}

void access(int x) {
  int y = 0;
  while (x) {
    splay(x), ch[x][1] = 0;
    update(x), add(c[x], -sz[x]);
    ch[x][1] = y, update(x);
    y = x, x = fa[x];
  }
}

void modify(int x, int t) {
  access(x), splay(x);
  c[x] = t, r[x] ^= 1;
  add(t, sz[x]);
}
}  // namespace lct

void dfs(int i, int fa) {
  lct::sz[i] = 1;
  for (int j : to[i])
    if (j != fa)
      lct::fa[j] = i, dfs(j, i);
}

int qpos(int x) {
  lct::splay(x);
  return query(c[x] - 1) + lct::sz[lct::ch[x][1]] + 1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> q;
  init();
  dfs(n, 0);

  for (int t = 1; t <= q; t++) {
    char op[8];
    cin >> op;
    if (op[0] == 'u') {
      int x;
      cin >> x;
      lct::modify(x, n + t);
    }
    if (op[0] == 'w') {
      int x;
      cin >> x;
      cout << qpos(x) << '\n';
    }
    if (op[0] == 'c') {
      int x, y;
      cin >> x >> y;
      if (qpos(x) < qpos(y))
        cout << x << '\n';
      else
        cout << y << '\n';
    }
  }
}