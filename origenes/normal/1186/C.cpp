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

const int maxn = 1123456;

char s[maxn], t[maxn];
int ans, n, m;

int main() {
  scanf("%s%s", t + 1, s + 1);
  m = strlen(t + 1), n = strlen(s + 1);
  if (n == 1) {
    FOR(i, 1, m) if (s[1] == t[i]) ans++;
    printf("%d", ans);
    return 0;
  }
  bool mv = false, now = false;
  FOR(i, 1, n - 1) if (s[i] != s[i + 1]) mv ^= true;
  FOR(i, 1, n) if (s[i] != t[i]) now ^= true;
  if (!now) ans++;
  FOR(st, 2, m - n + 1) {
    int en = st + n - 1;
    now ^= mv;
    if (t[st - 1] != s[1]) now ^= true;
    if (t[en] != s[n]) now ^= true;
    if (!now) ans++;
  }
  printf("%d", ans);
}