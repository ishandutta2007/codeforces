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

int n, a, b, c;
char bob[maxn], alice[maxn];

void solve() {
  scanf("%d", &n);
  scanf("%d%d%d", &a, &b, &c);
  scanf("%s", bob + 1);
  reset(alice, 0);
  FOR(i, 1, n) {
    if (bob[i] == 'R' && b) {
      alice[i] = 'P';
      b--;
    }
    if (bob[i] == 'P' && c) {
      alice[i] = 'S';
      c--;
    }
    if (bob[i] == 'S' && a) {
      alice[i] = 'R';
      a--;
    }
  }
  int need = n + 1 >> 1;
  FOR(i, 1, n) {
    if (alice[i]) need--;
    else {
      if (a) {
        alice[i] = 'R';
        a--;
      } else if (b) {
        alice[i] = 'P';
        b--;
      } else {
        alice[i] = 'S';
        c--;
      }
    }
  }
  if (need > 0) {
    puts("NO");
    return;
  }
  puts("YES");
  puts(alice + 1);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}