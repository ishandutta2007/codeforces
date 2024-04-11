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

const int maxn = 5123;
const int MOD = 1e9 + 7;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int pre[maxn][maxn], suf[maxn][maxn];
bool have[maxn][maxn];
int n, m, s[maxn];
vector<int> L[maxn], R[maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", s + i);
  FOR(i, 1, n) {
    memcpy(pre[i], pre[i - 1], sizeof(pre[i - 1]));
    pre[i][s[i]]++;
  }
  ROF(i, n, 1) {
    memcpy(suf[i], suf[i + 1], sizeof(suf[i + 1]));
    suf[i][s[i]]++;
  }
  while (m--) {
    int f, h; scanf("%d%d", &f, &h);
    have[f][h] = true;
  }
  int ans = 0, way = 0;
  REP(l, n + 1) {
    FOR(i, 1, l) L[s[i]].eb(pre[i][s[i]]);
    FOR(i, l + 1, n) R[s[i]].eb(suf[i][s[i]]);
    int now = 0, cnt = 1;
    FOR(i, 1, n) {
      if (L[i].empty() && R[i].empty()) continue;
      if (L[i].empty()) {
        int ops = 0;
        for (auto j : R[i]) ops += have[i][j];
        if (ops) {
          now++;
          cnt = mul(cnt, ops);
        }
      } else if (R[i].empty()) {
        int ops = 0;
        if (i != s[l]) for (auto j : L[i]) ops += have[i][j];
        else ops = have[i][L[i].back()];
        if (ops) {
          now++;
          cnt = mul(cnt, ops);
        } else if (i == s[l]) cnt = 0;
      } else {
        reverse(all(R[i]));
        vector<int> l_only, both, r_only;
        int k = 0;
        for (auto j : L[i]) {
          while (k < R[i].size() && R[i][k] < j) {
            r_only.eb(R[i][k]);
            k++;
          }
          if (k < R[i].size() && j == R[i][k]) {
            both.eb(j);
            k++;
          } else l_only.eb(j);
        }
        while (k < R[i].size()) {
          r_only.eb(R[i][k]);
          k++;
        }
        int a = 0, b = 0, c = 0;
        for (auto j : l_only) a += have[i][j];
        for (auto j : both) b += have[i][j];
        for (auto j : r_only) c += have[i][j];
        if (i != s[l]) {
          if (b >= 2 || (a && c) || (b == 1 && (a || c))) {
            now += 2;
            int tmp = b * (b - 1) + (a + c) * b + a * c;
            cnt = mul(cnt, tmp);
          } else if (a + b + c > 0) {
            now++;
            cnt = mul(cnt, a + 2 * b + c);
          }
        } else {
          if (!have[i][L[i].back()]) cnt = 0;
          bool only = !l_only.empty() && l_only.back() == L[i].back();
          if (only) {
            if (b || c) {
              now += 2;
              cnt = mul(cnt, b + c);
            } else now++;
          } else {
            if (c + b - 1 >= 1) {
              now += 2;
              cnt = mul(cnt, c + b - 1);
            } else now++;
          }
        }
      }
    }
    if (cnt && now > ans) {
      ans = now;
      way = cnt;
    } else if (now == ans) way = add(way, cnt);
    FOR(i, 1, n) L[i].clear(), R[i].clear();
  }
  printf("%d %d", ans, way);
}