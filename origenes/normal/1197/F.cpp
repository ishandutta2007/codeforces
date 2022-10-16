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

const int maxn = 1123;
const int MOD = 998244353;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

typedef vector<int> vi;
typedef vector<vi> Mat;

Mat add(const Mat &a, const Mat &b) {
  int n = a.size();
  Mat ret(n, vi(n));
  REP(i, n) REP(j, n) ret[i][j] = add(a[i][j], b[i][j]);
  return ret;
}

Mat mul(const Mat &a, const Mat &b) {
  int n = a.size();
  Mat ret(n, vi(n));
  REP(i, n) REP(j, n) REP(k, n) ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
  return ret;
}

Mat pow(Mat a, int pw) {
  int n = a.size();
  Mat ret(n, vi(n));
  REP(i, n) ret[i][i] = 1;
  while (pw) {
    if (pw & 1) ret = mul(ret, a);
    a = mul(a, a);
    pw >>= 1;
  }
  return ret;
}

vi mul(const Mat &a, const vi &x) {
  int n = a.size();
  vi ret(n);
  REP(i, n) REP(j, n) ret[i] = add(ret[i], mul(x[j], a[i][j]));
  return ret;
}

int encode(const vi &x) {
  int ret = 0, pw = 1;
  for (auto it : x) {
    ret += pw * it;
    pw <<= 2;
  }
  return ret;
}

vi decode(int x) {
  vi ret;
  REP(i, 3) {
    ret.eb(x & 3);
    x >>= 2;
  }
  return ret;
}

int n, m;
int a[maxn], f[3][3], g[maxn][4];
vector<pii> G[maxn];

int cal(int c, vi last) {
  vi vis(4);
  REP(i, 3) if (f[c][i]) vis[last[i]] = true;
  REP(i, 3) if (!vis[i]) return i;
  return 3;
}

vi calc(int c, vi last) {
  int code = cal(c, last);
  last.emplace(last.begin(), code);
  last.pop_back();
  return last;
}

Mat sub[3], pw[35];

vi raise(int k, vi x) {
  REP(i, 31) {
    if (k & 1) x = mul(pw[i], x);
    k >>= 1;
  }
  return x;
}

int main() {
  scanf("%d", &n);
  REP(i, n) scanf("%d", a + i);
  scanf("%d", &m);
  while (m--) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    x--, y--, c--;
    G[x].eb(y, c);
  }
  REP(i, n) sort(all(G[i]));
  REP(i, 3) REP(j, 3) scanf("%d", &f[i][j]);
  REP(i, 3) {
    sub[i] = Mat(64, vi(64));
    REP(j, 64) {
      int code = encode(calc(i, decode(j)));
      sub[i][code][j] = add(sub[i][code][j], 1);
    }
  }
  pw[0] = sub[0];
  FOR(i, 1, 2) pw[0] = add(pw[0], sub[i]);
  REP(i, 31) pw[i + 1] = mul(pw[i], pw[i]);
  g[0][0] = 1;
  REP(i, n) {
    vi now(64);
    now[encode({3, 3, 3})] = 1;
    int tail = 0;
    for (auto it : G[i]) {
      now = raise(it._1 - tail, now);
      now = mul(sub[it._2], now);
      tail = it._1 + 1;
    }
    now = raise(a[i] - tail, now);
    REP(j, 4) REP(k, 64) {
      vi s = decode(k);
      g[i + 1][j ^ s[0]] = add(g[i + 1][j ^ s[0]], mul(g[i][j], now[k]));
    }
  }
  printf("%d", g[n][0]);
}