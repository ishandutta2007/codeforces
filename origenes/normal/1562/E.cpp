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

const int N = 5123;

namespace SA {
  // ht: lcp of sa_{i-1} and sa_i
  int sa[N], rk[N], ht[N], s[N << 1], t[N << 1], p[N], cnt[N], f[N];
  // rmq-related
  int bits[N], d[N][25];
#define pushS(x) sa[f[s[x]]--] = x
#define pushL(x) sa[f[s[x]]++] = x
#define inducedSort(v) fill_n(sa, n, -1); fill_n(cnt, m, 0); \
REP(i, n) ++cnt[s[i]]; \
FOR(i, 1, m - 1) cnt[i] += cnt[i - 1]; \
REP(i, m) f[i] = cnt[i] - 1; \
ROF(i, n1 - 1, 0) pushS(v[i]); \
FOR(i, 1, m - 1) f[i] = cnt[i - 1]; \
REP(i, n) if (sa[i] > 0 && t[sa[i] - 1]) pushL(sa[i] - 1); \
REP(i, m) f[i] = cnt[i] - 1; \
ROF(i, n - 1, 0) if (sa[i] > 0 && !t[sa[i] - 1]) pushS(sa[i] - 1)

void sais(int n, int m, int *s, int *t, int *p) {
  int n1 = t[n - 1] = 0, ch = rk[0] = -1, *s1 = s + n;
  ROF(i, n - 2, 0) t[i] = s[i] == s[i + 1] ? t[i + 1] : s[i] > s[i + 1];
  FOR(i, 1, n - 1) rk[i] = t[i - 1] && !t[i] ? (p[n1] = i, n1++) : -1;
  inducedSort(p);
  for (int i = 0, x, y; i < n; ++i) if (~(x = rk[sa[i]])) {
    if (ch < 1 || p[x + 1] - p[x] != p[y + 1] - p[y]) ch++;
    else {
      for (int j = p[x], k = p[y]; j <= p[x + 1]; ++j, ++k)
        if ((s[j] << 1 | t[j]) != (s[k] << 1 | t[k])) {
          ch++;
          break;
        }
    }
    s1[y = x] = ch;
  }
  if (ch + 1 < n1) sais(n1, ch + 1, s1, t + n, p + n1);
  else REP(i, n1) sa[s1[i]] = i;
  REP(i, n1) s1[i] = p[sa[i]];
  inducedSort(s1);
}

template <typename T>
int mapCharToInt(const T *str, int n) {
  int m = *max_element(str, str + n);
  fill_n(rk, m + 1, 0);
  REP(i, n) rk[str[i]] = 1;
  REP(i, m) rk[i + 1] += rk[i];
  REP(i, n) s[i] = rk[str[i]] - 1;
  return rk[m];
}

// make str_n the unique lexicographically smallest character
template <typename T>
void suffixArray(const T *str, int n) {
  int m = mapCharToInt(str, ++n);
  sais(n, m, s, t, p);
  REP(i, n) rk[sa[i]] = i;
  // get ht
  for (int i = 0, h = ht[0] = 0; i < n - 1; ++i) {
    if (h) --h;
    int j = sa[rk[i] - 1];
    while (i + h < n && j + h < n && s[i + h] == s[j + h]) ++h;
    ht[rk[i]] = h;
  }
  // preprocess rmq
  for (int i = 2; i < n; ++i) bits[i] = bits[i / 2] + 1;
  for (int i = 1; i < n; ++i) d[i][0] = ht[i];
  for (int j = 1; (1 << j) <= n; ++j) for (int i = 1; i + (1 << j) <= n; ++i)
    d[i][j] = min(d[i][j - 1], d[i + (1 << j - 1)][j - 1]);
}

// lcp of suffix i and suffix j
int LCP(int i, int j) {
  i = rk[i], j = rk[j];
  if (i > j) swap(i, j);
  ++i;
  int num = bits[j - i + 1];
  return min(d[i][num], d[j - (1 << num) + 1][num]);
}
}

char S[N];
int f[N];

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  REP(i, n) S[i] = s[i];
  S[n] = 0;
  SA::suffixArray(S, n);
  REP(i, n) {
    f[i] = n - i;
    REP(j, i) if (SA::rk[i] > SA::rk[j]) chkmax(f[i], f[j] + n - i - SA::LCP(i, j));
  }
  cout << *max_element(f, f + n) << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}