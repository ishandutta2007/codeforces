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

const int maxn = 312345;

char s[maxn];
int a, b;

bool solve() {
  scanf("%d%d", &a, &b);
  scanf("%s", s + 1);
  int n = strlen(s + 1); s[n + 1] = 'X';
  int j = 0;
  vector<int> lens;
  FOR(i, 1, n + 1) if (s[i] == 'X') {
    if (j != i - 1) lens.eb(i - j - 1);
    j = i;
  }
  int cnt = 0, L = -1;
  for (auto x : lens) {
    if (x >= b && x < a) return false;
    if (x >= a && x < 2 * b) cnt++;
    else if (x >= 2 * b) {
      if (~L) return false;
      L = x;
    }
  }
  if (~L) {
    REP(u, L - a + 1) {
      int v = L - a - u;
      if (b <= u && u < a) continue;
      if (b <= v && v < a) continue;
      if (u >= 2 * b || v >= 2 * b) continue;
      int now = 0;
      if (u >= a) now++;
      if (v >= a) now++;
      if ((cnt + now + 1) & 1) return true;
    }
    return false;
  }
  return cnt & 1;
}

int main() {
  int T; scanf("%d", &T);
  while (T--) puts(solve() ? "YES" : "NO");
}