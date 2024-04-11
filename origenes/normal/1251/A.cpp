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

const int maxn = 512;

char s[maxn];
bool good[26];

void solve() {
  scanf("%s", s);
  reset(good, false);
  int n = strlen(s);
  for (int i = 0, j = 0; i <= n; i++) if (s[i] != s[j]) {
    if ((i - j) & 1) good[s[j] - 'a'] = true;
    j = i;
  }
  REP(i, 26) if (good[i]) putchar(i + 'a');
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}