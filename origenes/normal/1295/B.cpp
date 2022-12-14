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

char s[maxn];
int b[maxn];

void solve() {
  int n, x;
  scanf("%d%d", &n, &x);
  scanf("%s", s + 1);
  FOR(i, 1, n) b[i] = b[i - 1] + (s[i] == '0' ? 1 : -1);
  if (b[n] == 0) {
    bool f = false;
    REP(i, n) if (b[i] == x) f = true;
    puts(f ? "-1" : "0");
    return;
  }
  int ans = 0;
  REP(i, n) if ((x - b[i]) % b[n] == 0 && (x - b[i]) / b[n] >= 0) ans++;
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}