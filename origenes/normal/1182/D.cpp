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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;

vector<int> G[maxn], E[maxn << 1];

int st[maxn << 1], en[maxn << 1];
int n;

inline void update(vector<int> &a, const vector<int> &b) {
  if (b.empty()) return;
  if (a.empty()) a = b;
  else {
    if (a[0] == -1) return;
    if (a != b) a = {-1};
  }
}

inline bool bad(const vector<int> &a) {
  return a.size() && a[0] == -1;
}

inline void append(vector<int> &a, int b) {
  if (bad(a)) return;
  if (!b) a = {0};
  else {
    a.back()++;
    if (b > 1) {
      a.eb(b);
      a.eb(0);
    }
  }
}

void dfs(int u, int link) {
  int cnt = 0;
  for (auto _ : G[u]) if ((_ ^ 1) != link) {
    dfs(en[_], _);
    cnt++;
    if (link != -1) update(E[link], E[_]);
  }
  if (link != -1) append(E[link], cnt);
}

void dfs2(int u, int link) {
  vector<int> ch;
  vector<vector<int>> tab;
  for (auto _ : G[u]) {
    ch.eb(_);
    tab.eb(E[_]);
  }
  vector<vector<int>> pre(tab.size() + 1), suf(tab.size() + 1);
  REP(i, int(tab.size())) {
    update(pre[i + 1], pre[i]);
    update(pre[i + 1], tab[i]);
  }
  ROF(i, int(tab.size()) - 1, 0) {
    update(suf[i], suf[i + 1]);
    update(suf[i], tab[i]);
  }
  REP(i, int(tab.size())) if ((ch[i] ^ 1) != link) {
    update(E[ch[i] ^ 1], pre[i]);
    update(E[ch[i] ^ 1], suf[i + 1]);
    append(E[ch[i] ^ 1], int(tab.size()) - 1);
  }
  for (auto _ : G[u]) if ((_ ^ 1) != link) dfs2(en[_], _);
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    int idx = 2 * i;
    scanf("%d%d", st + idx, en + idx);
    st[idx]--, en[idx]--;
    G[st[idx]].eb(idx);
    G[en[idx]].eb(idx + 1);
    st[idx + 1] = en[idx];
    en[idx + 1] = st[idx];
  }
  dfs(0, -1);
  dfs2(0, -1);
  REP(i, n) {
    vector<int> ans;
    for (auto _ : G[i]) update(ans, E[_]);
    if (!bad(ans)) {
      printf("%d", i + 1);
      return 0;
    }
  }
  puts("-1");
}