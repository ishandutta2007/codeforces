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

namespace Suffix_Array {
  const int maxn = 712345;
  const int maxlog = 20;

  // ht: LCP of sa[i - 1] and sa[i]
  int sa[maxn], rk[maxn], ht[maxn], s[maxn << 1], t[maxn << 1], p[maxn], cnt[maxn], f[maxn];
  int bits[maxn], d[maxn][maxlog];  // RMQ related
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
    for (int i = 0, x, y; i < n; ++i)
      if (~(x = rk[sa[i]])) {
        if (ch < 1 || p[x + 1] - p[x] != p[y + 1] - p[y]) ++ch;
        else {
          for (int j = p[x], k = p[y]; j <= p[x + 1]; ++j, ++k) {
            if ((s[j] << 1 | t[j]) != (s[k] << 1 | t[k])) {
              ++ch;
              break;
            }
          }
        }
        s1[y = x] = ch;
      }
    if (ch + 1 < n1) sais(n1, ch + 1, s1, t + n, p + n1);
    else
      REP(i, n1) sa[s1[i]] = i;
    REP(i, n1) s1[i] = p[sa[i]];
    inducedSort(s1);
  }

  template<typename T>
  int mapCharToInt(const T *str, int n) {
    int m = *max_element(str, str + n);
    fill_n(rk, m + 1, 0);
    REP(i, n) rk[str[i]] = 1;
    REP(i, m) rk[i + 1] += rk[i];
    REP(i, n) s[i] = rk[str[i]] - 1;
    return rk[m];
  }

  // str[n] shall be the unique lexicographically smallest character
  template<typename T>
  void suffixArray(const T *str, int n) {
    int m = mapCharToInt(str, ++n);
    sais(n, m, s, t, p);
    REP(i, n) rk[sa[i]] = i;
    // get height:
    for (int i = 0, h = ht[0] = 0; i < n - 1; ++i) {
      if (h) --h;
      int j = sa[rk[i] - 1];
      while (i + h < n && j + h < n && s[i + h] == s[j + h]) ++h;
      ht[rk[i]] = h;
    }
    // init sparse table:
    for (int i = 2; i < n; ++i) bits[i] = bits[i / 2] + 1;
    for (int i = 1; i < n; ++i) d[i][0] = ht[i];
    for (int j = 1; (1 << j) <= n; ++j) {
      for (int i = 1; i + (1 << j) <= n; ++i) {
        d[i][j] = min(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  int lcp(int i, int j) {
    i = rk[i], j = rk[j];
    assert(i != j);
    if (i > j) swap(i, j);
    ++i;
    int num = bits[j - i + 1];
    return min(d[i][num], d[j - (1 << num) + 1][num]);
  }
}

const int maxn = 212345;

int n, q;
char s[maxn], par[maxn * 2];
int nxt[maxn], pre[maxn], cnt[maxn];

int get(int l, int r) {
  int ret = cnt[r];
  return l ? ret - cnt[l - 1] : ret;
}

int main() {
  scanf("%d", &n);
  scanf("%s", s);
  int p = -1, tot = 0;
  REP(i, n) {
    if (s[i] == '0') p = i, par[tot++] = (i & 1) + '0';
    pre[i] = p;
    if (i) cnt[i] = cnt[i - 1];
    if (s[i] == '0') cnt[i]++;
  }
  par[tot] = '#';
  REP(i, tot) par[tot + i + 1] = par[i] ^ 1;
  p = n;
  ROF(i, n - 1, 0) {
    if (s[i] == '0') p = i;
    nxt[i] = p;
  }
  Suffix_Array::suffixArray(par, 2 * tot + 1);
  scanf("%d", &q);
  while (q--) {
    int l1, l2, len;
    scanf("%d%d%d", &l1, &l2, &len);
    l1--, l2--;
    if (get(l1, l1 + len - 1) != get(l2, l2 + len - 1)) {
      puts("No");
      continue;
    }
    if (get(l1, l1 + len - 1) == 0) {
      puts("Yes");
      continue;
    }
    bool f1 = l1 & 1, f2 = l2 & 1;
    int r1 = cnt[pre[l1 + len - 1]] - 1, r2 = cnt[pre[l2 + len - 1]] - 1;
    l1 = cnt[nxt[l1]] - 1, l2 = cnt[nxt[l2]] - 1;
    if (f1) l1 += tot + 1, r1 += tot + 1;
    if (f2) l2 += tot + 1, r2 += tot + 1;
    if (l1 == l2) {
      puts("Yes");
      continue;
    }
    puts(Suffix_Array::lcp(l1, l2) >= r1 - l1 + 1 ? "Yes" : "No");
  }
}