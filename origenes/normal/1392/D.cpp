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

int n;
char s[maxn];

void solve() {
  scanf("%d%s", &n, s);
  if (n <= 2) {
    puts("0");
    return;
  }
  int now = 1, fi = 0, ans = 0;
  FOR(i, 1, n - 1) {
    if (s[i] == s[i - 1]) now++;
    else {
      if (!fi) fi = now;
      else ans += now / 3;
      now = 1;
    }
  }
  if (!fi) printf("%d\n", (n + 2) / 3);
  else {
    if (s[0] == s[n - 1]) printf("%d\n", ans + (fi + now) / 3);
    else printf("%d\n", ans + fi / 3 + now / 3);
  }
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}