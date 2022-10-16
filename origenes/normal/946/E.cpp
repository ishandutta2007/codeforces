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

const int maxn = 212345;

char s[maxn];
int ans[maxn], t, n;

bool dfs(int pos, int mask, bool bad, bool en) {
  if (pos == n) {
    if (bad || !en) return false;
    if (!mask) {
      int st = 0;
      while (st + 1 < n && !ans[st]) st++;
      FOR(i, st, n - 1) printf("%d", ans[i]);
      puts("");
      return true;
    }
    return false;
  }
  if (__builtin_popcount(mask) > n - pos) return false;
  if ((__builtin_popcount(mask) + (n - pos)) & 1) {
    if (!en) {
      ans[pos] = 0;
      return dfs(pos + 1, 0, false, false);
    }
    return false;
  }
  if (!bad) {
    ROF(i, 9, 0) {
      ans[pos] = i;
      if (dfs(pos + 1, (i || en) ? mask ^ (1 << i) : mask, false, (i || en))) return true;
    }
    return false;
  }
  ROF(i, s[pos], 0) {
    ans[pos] = i;
    if (dfs(pos + 1, (i || en) ? mask ^ (1 << i) : mask, i == s[pos], (i || en))) return true;
  }
  return false;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    n = strlen(s);
    REP(i, n) s[i] -= '0';
    dfs(0, 0, true, false);
  }
}