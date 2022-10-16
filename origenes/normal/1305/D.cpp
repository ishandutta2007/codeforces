#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

int ask(int u, int v) {
  cout << "? " << u << ' ' << v << endl;
  int ret;
  cin >> ret;
  return ret;
}

void answer(int u) {
  cout << "! " << u << endl;
}

const int maxn = 1123;

int n, leaf[maxn];
vector<int> G[maxn];
bool bad[maxn];

void dfs(int u, int par) {
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    leaf[u] = leaf[v];
  }
  if (G[u].size() == 1) leaf[u] = u;
}

void mark(int u, int par) {
  bad[u] = true;
  for (auto v : G[u]) if (v != par && !bad[v]) mark(v, u);
}

int dfs(int u, int par, int ban) {
  if (u == ban) return u;
  for (auto v : G[u]) if (v != par) {
    if (dfs(v, u, ban)) return v;
  }
  return 0;
}

int main() {
  cin >> n;
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v); G[v].eb(u);
  }
  vector<int> need;
  FOR(i, 1, n) if (G[i].size() == 1) {
    need.eb(i);
    if (need.size() == 2) break;
  }
  int r = ask(need[0], need[1]);
  if (r == need[0] || r == need[1]) {
    answer(r);
    return 0;
  }
  dfs(r, 0);
  need[0] = dfs(r, 0, need[0]);
  need[1] = dfs(r, 0, need[1]);
  mark(need[0], r); mark(need[1], r);
  while (true) {
    int pre = -1;
    bool changed = false;
    for (auto u : G[r]) if (!bad[u]) {
      if (pre == -1) pre = u;
      else {
        int o = ask(leaf[pre], leaf[u]);
        if (o != r) {
          if (o == leaf[pre] || o == leaf[u]) {
            answer(o);
            return 0;
          }
          int v = dfs(o, 0, leaf[pre]);
          mark(v, o);
          v = dfs(o, 0, leaf[u]);
          mark(v, o);
          r = o;
          changed = true;
          break;
        }
        mark(pre, r); mark(u, r);
        pre = -1;
      }
    }
    if (!changed) {
      if (pre != -1) {
        int u = ask(leaf[pre], r);
        if (u == leaf[pre] || u == r) {
          answer(u);
          return 0;
        }
        int v = dfs(u, 0, leaf[pre]);
        mark(v, u);
        v = dfs(u, 0, r);
        mark(v, u);
        r = u;
      } else {
        answer(r);
        return 0;
      }
    }
  }
}
/*
 9
1 2
1 3
1 4
1 5
1 6
1 7
5 8
8 9
 */