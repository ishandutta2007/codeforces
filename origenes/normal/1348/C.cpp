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

int n, k, cnt[26];
char s[maxn];

void solve() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  reset(cnt, 0);
  FOR(i, 1, n) cnt[s[i] - 'a']++;
  int fi;
  REP(i, 26) if (cnt[i]) {
    fi = i;
    break;
  }
  if (cnt[fi] < k) {
    k -= cnt[fi];
    FOR(i, fi + 1, 25) {
      k -= cnt[i];
      if (k <= 0) {
        printf("%c\n", i + 'a');
        return;
      }
    }
  }
  putchar(fi + 'a');
  cnt[fi] -= k;
  FOR(i, fi, 25) if (cnt[i] == n - k) {
    while (cnt[i] > 0) {
      putchar(i + 'a');
      cnt[i] -= k;
    }
    putchar('\n');
    return;
  }
  FOR(i, fi, 25) while (cnt[i]--) putchar(i + 'a');
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}