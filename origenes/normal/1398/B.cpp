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

const int maxn = 112;

int n;
char s[maxn];

void solve() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  vector<int> tab;
  int cur = 0;
  FOR(i, 1, n + 1) {
    if (s[i] != '1') {
      if (cur) tab.eb(cur);
      cur = 0;
    } else cur++;
  }
  sort(all(tab), greater<>());
  int ans = 0;
  for (int i = 0; i < int(tab.size()); i += 2) ans += tab[i];
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}