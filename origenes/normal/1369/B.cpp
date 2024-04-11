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

int n;
char s[maxn];

void solve() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  int fi_one = n + 1, last_zero = 0;
  FOR(i, 1, n) {
    if (s[i] == '1') chkmin(fi_one, i);
    else chkmax(last_zero, i);
  }
  FOR(i, 1, n) {
    if (s[i] == '0' && i != last_zero && i > fi_one) continue;
    if (s[i] == '1' && i < last_zero) continue;
    putchar(s[i]);
  }
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}