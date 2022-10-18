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

const int maxn = 213;

vector<int> G[26];
char s[maxn];

void solve() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  if (n == 1) {
    puts("YES");
    REP(i, 26) putchar(i + 'a');
    putchar('\n');
    return;
  }
  REP(i, 26) G[i].clear();
  FOR(i, 2, n) {
    G[s[i] - 'a'].eb(s[i - 1] - 'a');
    G[s[i - 1] - 'a'].eb(s[i] - 'a');
  }
  REP(i, 26) {
    sort(all(G[i]));
    uni(G[i]);
  }
  vector<int> one;
  bool bad = false;
  REP(i, 26) {
    if (G[i].size() == 1) {
      one.eb(i);
    } else if (G[i].size() > 2) {
      bad = true;
      break;
    }
  }
  if (one.size() != 2) bad = true;
  if (bad) {
    puts("NO");
    return;
  }
  puts("YES");
  int pre = -1;
  for (int i = one.front(); ; ) {
    int j = G[i].size() == 1 ? G[i][0] : G[i][0] ^ G[i][1] ^ pre;
    bool last = j == pre;
    putchar(i + 'a');
    pre = i; i = j;
    if (last) break;
  }
  REP(i, 26) if (G[i].empty()) putchar(i + 'a');
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}