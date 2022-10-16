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

const int maxn = 212345;

struct AhoCorasick {
  int nxt[maxn][26], f[maxn], v[maxn], w[maxn];
  int tot;

  void insert(const char *s) {
    int now = 0;
    for (int i = 0; s[i]; i++) {
      int idx = s[i] - 'a';
      if (!nxt[now][idx]) nxt[now][idx] = ++tot;
      now = nxt[now][idx];
    }
    v[now]++;
  }

  void get_fail() {
    queue<int> q;
    REP(i, 26) if (nxt[0][i]) q.emplace(nxt[0][i]);
    while (!q.empty()) {
      auto u = q.front(); q.pop();
      REP(i, 26) {
        if (nxt[u][i]) {
          f[nxt[u][i]] = nxt[f[u]][i];
          v[nxt[u][i]] += v[f[nxt[u][i]]];
          q.emplace(nxt[u][i]);
        } else nxt[u][i] = nxt[f[u]][i];
      }
    }
  }

  void init(const char *s) {
    int now = 0;
    for (int i = 0; s[i]; i++) {
      now = nxt[now][s[i] - 'a'];
      w[i] = v[now];
    }
  }
} T1, T2;

char s[maxn], t[maxn];
int n, m;
ll ans;

int main() {
  scanf("%s%d", t, &n);
  while (n--) {
    scanf("%s", s);
    T1.insert(s);
    m = strlen(s);
    reverse(s, s + m);
    T2.insert(s);
  }
  T1.get_fail(); T2.get_fail();
  T1.init(t);
  m = strlen(t);
  reverse(t, t + m);
  T2.init(t);
  REP(i, m - 1) ans += ll(T1.w[i]) * T2.w[m - 2 - i];
  printf("%lld", ans);
}