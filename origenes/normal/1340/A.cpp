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

int n, p[maxn];

void solve() {
  scanf("%d", &n);
  int st;
  FOR(i, 1, n) {
    scanf("%d", p + i);
    if (p[i] == 1) st = i;
  }
  int cnt = 0, en = n;
  while (cnt < n) {
    FOR(i, st + 1, en) if (p[i] != p[i - 1] + 1) {
      puts("No");
      return;
    }
    cnt += en - st + 1;
    en = st - 1;
    ROF(i, en, 1) if (p[i] == cnt + 1) {
      st = i;
      break;
    }
  }
  puts("Yes");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}