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

const int maxn = 112345;

char s[maxn], t[maxn];

void solve() {
  scanf("%s%s", s + 1, t + 1);
  int n = strlen(s + 1), m = strlen(t + 1);
  vector<vector<int>> nxt(n + 1, vector<int>(26, -1));
  ROF(i, n - 1, 0) {
    nxt[i] = nxt[i + 1];
    nxt[i][s[i + 1] - 'a'] = i + 1;
  }
  int ans = 1, j = 0;
  for (int i = 1; i <= m && ans <= 1e5 + 5; ) {
    int need = t[i] - 'a';
    j = nxt[j][need];
    if (j == -1) {
      j = 0;
      ans++;
    } else i++;
  }
  if (ans > 1e5) ans = -1;
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}