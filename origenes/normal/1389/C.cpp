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

char s[maxn];
int n;

int check(int x, int y) {
  int ret = 0;
  FOR(i, 1, n) if (s[i] == x) {
    ret++;
    swap(x, y);
  }
  if (ret % 2 == 1 && x != y) ret--;
  return ret;
}

void solve() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  int ans = 0;
  FOR(i, '0', '9') FOR(j, '0', '9') chkmax(ans, check(i, j));
  printf("%d\n", n - ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}